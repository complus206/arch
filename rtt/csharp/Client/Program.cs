using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Diagnostics;
using Thrift.Transport;
using Thrift.Protocol;
using ClientConsole;

namespace Client
{
    class Program
    {
        static readonly int invokeCount = 10000;

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

                string svrAddr = "localhost";
                if (args.Length > 0)
                {
                    svrAddr = args[0];
                }
                string clientID = "#1#";
                if (args.Length > 1)
                {
                    clientID = "#" + args[1] + "#";
                }

                Console.WriteLine("Connect to server {0} ...", svrAddr);

                //TTransport transport = new TSocket(svrAddr, 9090);
                TTransport transport = new TFramedTransport(new TSocket(svrAddr, 9090));
                TProtocol protocol = new TBinaryProtocol(transport);

                transport.Open();
                Serv.Client client = new Serv.Client(protocol);

                //Test One by One
                Stopwatch watch = new Stopwatch();
                watch.Start();
                //CreateReserveOneByOne(client);
                watch.Stop();
                Console.WriteLine("Create reseve one by one used {0}mss", watch.Elapsed.TotalMilliseconds);

                //Test Batch
                watch = new Stopwatch();
                CreateReserveBatch(client);
                watch.Stop();
                Console.WriteLine("Create reseve batch used {0}ms", watch.Elapsed.TotalMilliseconds);

                transport.Close();
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
            List<Reserve> list = new List<Reserve>();
            for (int i = 0; i < invokeCount; i++)
            {
                Reserve r = CreateTestReserve(i);
                list.Add(r);
            }
            client.createBatch(list);
        }

        static Reserve CreateTestReserve(int index)
        {
            Reserve r = new Reserve();
            r.Reser_no = index;
            r.Guest_name = "guest" + index.ToString();
            r.Contacter_mobile = (13800138000 + index).ToString();
            r.Sum_price = (500 + index % 50).ToString();

            return r;
        }
    }
}
