g++ -g -I/usr/local/include/thrift -L/usr/local/lib/ -lthrift ./src/Serv.cpp ./src/student_types.cpp ./src/student_constants.cpp ./src/Serv_server.skeleton.cpp -o ./output/server
  
g++ -g -I/usr/local/include/thrift -L/usr/local/lib/ -lthrift -lm -pthread -lz -lssl ./src/Serv.cpp ./src/student_types.cpp ./src/student_constants.cpp ./src/client.cpp -o ./output/client