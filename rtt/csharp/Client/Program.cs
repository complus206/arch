using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Diagnostics;
using Thrift.Transport;
using Thrift.Protocol;
using ClientConsole;
using System.Threading;
using com.eLong.Hotel.Framework.Utility;
using System.IO;

namespace Client
{
    class Program
    {
        static int threadCount = 1;
        static ManualResetEvent[] manualEvents;
        static double[] statResults;
        static List<double> packageLog = new List<double>();
        static readonly int invokeCount = 100;
        static readonly int packageCount = 100;
        static string svrAddr = "localhost";

        static void Main(string[] args)
        {
            
            try
            {
                Console.WriteLine("Press any key to start...");
                Console.ReadKey();

                StringBuilder sb = new StringBuilder();
                for (int i = 0; i < 10; i++)
                {
                    sb.Append("中文测试");
                }

                svrAddr = "10.0.1.7";
                if (args.Length > 0)
                {
                    svrAddr = args[0];
                }
                if (args.Length > 1)
                {
                    threadCount = int.Parse(args[1].Trim());
                }

                TestFunc(svrAddr, threadCount);
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
                Console.WriteLine(ex.StackTrace);
            }
            finally
            {
                Console.WriteLine("Client exit!");
            }
        }

        static void TestFunc(string svrAddr, int threadCount)
        {
            List<Reserve> list = new List<Reserve>();
            for (int j = 0; j < packageCount; j++)
            {
                Reserve r = CreateTestReserve(j);
                list.Add(r);
            }

            ThriftPool pool = new ThriftPool(new ThriftConfig()
            {
                #region 配置连接池

                Host = svrAddr,
                Port = 9090,
                Timeout = 60,
                MaxActive = 100,
                MaxIdle = 20,
                MinIdle = 5,
                Encode = Encoding.UTF8

                #endregion
            });

            using (FileStream fs = new FileStream(".\\output.log", FileMode.Create, FileAccess.Write))
            {
                PerformanceTestHelper helper = new PerformanceTestHelper((index) =>
                {
                    TTransport transport = pool.BorrowInstance();
                    //TTransport transport = new TFramedTransport(new TSocket(svrAddr, 9090));
                    //TProtocol protocol = new TBinaryProtocol(transport);
                    TProtocol protocol = new TCompactProtocol(transport);
                    //transport.Open();
                    Serv.Client client = new Serv.Client(protocol);

                    client.createBatch(list);

                    pool.ReturnInstance(transport);
                    //transport.Close();

                }, threadCount, 1000, true, fs);
                helper.Run();
            }
        }

        static void TestSearilize()
        {
            MemoryStream inStream = new MemoryStream();
            MemoryStream outStream = new MemoryStream();
            var streamTrans = new Thrift.Transport.TStreamTransport(inStream, outStream);
            var jsonProto = new Thrift.Protocol.TJSONProtocol(streamTrans);
            var obj = CreateTestReserve(0);
            obj.Write(jsonProto);

            byte[] buffer = new byte[outStream.Length];
            outStream.Position = 0;
            outStream.Read(buffer, 0, buffer.Length);

            using (FileStream fs = new FileStream(".\\1.json", FileMode.Create, FileAccess.Write))
            {
                fs.Write(buffer, 0, buffer.Length);
            }

            inStream.Close();
            outStream.Close();
        }


        static void WorkFunc(object obj)
        {
            int index = (int)obj;
            try
            {
                //TTransport transport = new TSocket(svrAddr, 9090);
                TTransport transport = new TFramedTransport(new TSocket(svrAddr, 9090));
                TProtocol protocol = new TBinaryProtocol(transport);
                //TProtocol protocol = new TCompactProtocol(transport);

                transport.Open();
                Serv.Client client = new Serv.Client(protocol);
                Stopwatch watch = new Stopwatch();

                //Test One by One
                //watch.Start();
                //CreateReserveOneByOne(client);
                //watch.Stop();
                //Console.WriteLine("Create reseve one by one used {0}mss", watch.Elapsed.TotalMilliseconds);

                //Test Batch
                watch = new Stopwatch();
                watch.Start();
                CreateReserveBatch(client);
                watch.Stop();
                Console.WriteLine("Create reseve batch used {0}ms", watch.Elapsed.TotalMilliseconds);

                statResults[index] = watch.Elapsed.TotalMilliseconds;

                transport.Close();
            }
            catch (Exception ex)
            {
                Console.WriteLine("Thread {0} error!", index);
                Console.WriteLine(ex.Message);
                Console.WriteLine(ex.StackTrace);
            }
            finally
            {
                manualEvents[index].Set();
                Console.WriteLine("Thread {0} finished!", index);
            }
        }

        static void OutputStatResult()
        {
            double sum = 0;
            for (int i = 0; i < statResults.Length; i++)
            {
                sum += statResults[i];
            }

            double avg = sum / threadCount;
            Console.WriteLine("Avg thread timespan is {0}ms", avg);

            sum = 0;
            for (int i = 0; i < packageLog.Count; i++)
            {
                sum += packageLog[i];
            }
            avg = sum / packageLog.Count;
            Console.WriteLine("Avg invoke timespan is {0}ms", avg);
        }

        static void CreateReserveOneByOne(Serv.Client client)
        {
            for (int i = 0; i < invokeCount; i++)
            {
                Reserve r = CreateTestReserve(i);
                client.create(r);
            }
        }

        static void CreateReserveBatch(Serv.Client client)
        {
            for (int i = 0; i < invokeCount; i++)
            {
                List<Reserve> list = new List<Reserve>();
                for (int j = 0; j < packageCount; j++)
                {
                    Reserve r = CreateTestReserve(j);
                    list.Add(r);
                }

                Stopwatch watch = new Stopwatch();
                watch.Start();
                client.createBatch(list);
                watch.Stop();
                packageLog.Add(watch.Elapsed.TotalMilliseconds);
            }
        }

        static Reserve CreateTestReserve(int index)
        {
            Reserve r = new Reserve();
            r.Reser_no = index;
            r.Guest_name = "guest" + index.ToString();
            r.Contacter_mobile = (13800138000 + index).ToString();
            r.Sum_price = (500 + index % 50).ToString();
            r.Other = GetStringFillings(200);

            return r;
        }

        static string GetStringFillings(int size)
        {
            string pack = "测试字符串";
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < size; i++)
            {
                sb.Append(pack);
            }
            return sb.ToString();
        }
    }
}
