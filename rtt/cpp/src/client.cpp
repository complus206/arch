#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <iostream>
#include <sstream>
#include <string>

#include "Serv.h"  // Your .h File
#include <thrift/protocol/TBinaryProtocol.h>

#include <sys/socket.h>
#include <arpa/inet.h>
#include <thrift/transport/TSocket.h>

#include <transport/TBufferTransports.h>
#include <thrift/transport/TTransportUtils.h>

using namespace std;
using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;

using namespace boost;
using boost::shared_ptr;

template <class T>
std::string ConvertToString(T);
void CreateReserveOneByOne(string svrAddr, ServClient client);
void CreateReserveBatch(string svrAddr, ServClient client);
Reserve* CreateTestReserve(int index);
void PrintDiffClock(const char* name, clock_t t1, clock_t t2);

int main(int argc, char **argv) {
    
    const char* defaultSvrAddr = "localhost";
    string svrAddr;
    
    if(argc > 1)
    {
        **argv++;
        svrAddr = string(*argv);
    }
    else
    {
        svrAddr = string(defaultSvrAddr);
    }
    
    printf("connect to %s...\r\n", svrAddr.c_str());
    
    boost::shared_ptr<TSocket> socket(new TSocket(svrAddr, 9090));
    boost::shared_ptr<TTransport> transport(new TFramedTransport(socket));
    boost::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));

    transport->open();
    ServClient client(protocol);
    
    clock_t t1, t2;
    //Test One by One
    t1= clock();
    CreateReserveOneByOne(svrAddr, client);
    t2 = clock();
    double diff = t2 - t1;
    printf("Finished t1=%f, t2=%f, diff=%f ...\r\n", (double)t1, (double)t2, diff / CLOCKS_PER_SEC);
    
    //Test Batch
    t1= clock();
    CreateReserveBatch(svrAddr, client);    
    t2 = clock();
    diff = t2 - t1;
    printf("Finished t1=%f, t2=%f, diff=%f ...\r\n", (double)t1, (double)t2, diff / CLOCKS_PER_SEC);
    
    transport->close();
    printf("client exit!\r\n");
        
    return 0;
}

void CreateReserveOneByOne(string svrAddr, ServClient client)
{
    int i = 0;
    for(int i = 0; i < INVOKE_TIMES; i++)
    {
        Reserve* r = CreateTestReserve(i);

        client.create(*r);
        delete r;
    }
}

void CreateReserveBatch(string svrAddr, ServClient client)
{   
	clock_t t1, t2, t3, t4;
	
	t1 = clock();
    std::vector<Reserve> lst(INVOKE_TIMES);
    t2 = clock();
    printf("vector size is %d\r\n", (int)lst.size());
    
    int i = 0;
    for(int i = 0; i < INVOKE_TIMES; i++)
    {
        Reserve* r = CreateTestReserve(i);
		lst[i] = *r;
    }
    
    t3 = clock();
    printf("vector size is %d\r\n", (int)lst.size());
    
    client.createBatch(lst);
    
    t4 = clock();
    printf("vector size is %d\r\n", (int)lst.size());
    
    PrintDiffClock("declare vector", t1, t2);
    PrintDiffClock("fill vector", t2, t3);
    PrintDiffClock("invoke createBatch", t3, t4);
}

Reserve* CreateTestReserve(int index)
{
	const char* front = "guest";
	
	Reserve* r = new Reserve();
	r->__set_reser_no(index);
	string guest_name = string(front);
	guest_name = guest_name + ConvertToString(index);
	r->__set_guest_name(guest_name);
	r->__set_contacter_mobile(ConvertToString(13800138000 + index));
	r->__set_sum_price(ConvertToString(500 + index % 50));
	
	return r;
}

void PrintDiffClock(const char* name, clock_t t1, clock_t t2)
{
	double diff = (double)(t2 - t1);
	printf("%s: t1=%f, t2=%f, diff=%f ...\r\n", name, (double)t1, (double)t2, diff / CLOCKS_PER_SEC);
}

template <class T>
std::string ConvertToString(T value)
{
    std::stringstream ss;
    ss << value;
    return ss.str();
}