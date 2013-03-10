prelable = -DHAVE_NETINET_IN_H -I/usr/local/include/ -L/usr/local/lib/
mysqlconn = -l mysqlcppconn
all : server

server : ./src/main.cpp
		
		g++ -g $(prelable) ./src/main.cpp -o ./output/mt $(mysqlconn)

clean : 
		rm -rf ./output/*
