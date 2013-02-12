prelable = -DHAVE_NETINET_IN_H -I/usr/local/include/thrift -L/usr/local/lib/
thrftlib = -lthrift -lthriftnb -levent
clientlib = -lm -pthread -lz -lssl

all : server client

server : ./src/Serv.cpp\
		./src/reserve_types.cpp\
		./src/reserve_constants.cpp\
		./src/Serv_server.skeleton.cpp
		
		g++ -g $(prelable) ./src/Serv.cpp ./src/reserve_types.cpp ./src/reserve_constants.cpp ./src/Serv_server.skeleton.cpp $(thrftlib) -o ./output/server
client : ./src/Serv.cpp\
		./src/reserve_types.cpp\
		./src/reserve_constants.cpp\
		./src/client.cpp
		
		g++ -g $(prelable) $(clientlib) ./src/Serv.cpp ./src/reserve_types.cpp ./src/reserve_constants.cpp ./src/client.cpp $(thrftlib) -o ./output/client
clean : 
		rm -rf ./output/*