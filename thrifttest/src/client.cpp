#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
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
    boost::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
    boost::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));
    
    transport->open();
    
    //Your Codes
    int i = 0;
    const char* front = "student";
    for(int i = 0; i < INVOKE_TIMES; i++)
    {
        Student* s = new Student();
        s->__set_sno(i);
        string sname = string(front);
        sname = sname + ConvertToString(i);
        s->__set_sname(sname);
        s->__set_ssex(false);
        s->__set_sage((i+1)*2);
        
        ServClient client(protocol);
        client.put(*s);
        delete s;
    }
    
    transport->close();
    printf("client exit!\r\n");
    
    return 0;
}

template <class T>
std::string ConvertToString(T value)
{
    std::stringstream ss;
    ss << value;
    return ss.str();
}