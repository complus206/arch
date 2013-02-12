// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.

#include "Serv.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/concurrency/PosixThreadFactory.h>
#include <thrift/server/TNonblockingServer.h>
#include <thrift/server/TThreadPoolServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>
#include "stdio.h"
#include "stdlib.h"
#include "time.h"

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;
using namespace ::apache::thrift::concurrency;
using boost::shared_ptr;


class ServHandler : virtual public ServIf {
public:
    ServHandler() {
        // Your initialization goes here
        invokeTimes = 0;
        
        clock_t t1 = clock();
        sleep(0);
        clock_t t2 = clock();
        double diff = (double)(t2 - t1) / CLOCKS_PER_SEC * 10;
        printf("CLOCKS_PER_SEC = %d\r\n", CLOCKS_PER_SEC);
        printf("sleep %f seconds!\r\n", diff);
        
    }
    
    bool create(const Reserve& s) {
        // Your implementation goes here
        if(this->invokeTimes == 0)
        {
            this->start = clock();
        }
        this->invokeTimes++;
        
        if(this->invokeTimes % INVOKE_TIMES == 0)
        {
            clock_t finish = clock();
            double duration = (double)(finish - this->start);
            printf("received %d times, used %fseconds, data is reser_no=%d;guest_name='%s';mobile=%s;sum_price=%s;\r\n",
                   this->invokeTimes, duration, s.reser_no, s.guest_name.c_str(), s.contacter_mobile.c_str(), s.sum_price.c_str());
            
            //reset clock
            this->start = clock();
        }
    }
private:
    uint invokeTimes;
    clock_t start;
};

int main(int argc, char **argv) {
    const int port = 9090;
    shared_ptr<ServHandler> handler(new ServHandler());
    shared_ptr<TProcessor> processor(new ServProcessor(handler));
    
    shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
    shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
    shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());
    
    //TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
    
    // using thread pool with maximum 15 threads to handle incoming requests
    shared_ptr<ThreadManager> threadManager = ThreadManager::newSimpleThreadManager(15);
    shared_ptr<PosixThreadFactory> threadFactory = shared_ptr<PosixThreadFactory>(new PosixThreadFactory());
    threadManager->threadFactory(threadFactory);
    threadManager->start();
    
    //TThreadPoolServer server(processor, serverTransport, transportFactory, protocolFactory, threadManager);
    TNonblockingServer server(processor, protocolFactory, port, threadManager);
    printf("server started...\r\n");
    server.serve();
    return 0;

}
