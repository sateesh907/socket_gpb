CC = g++
WARNINGS = -Wall
SER_FILES = RHMI_API.cpp MesgBuff.pb.cc server_tcp.cpp
SER_OUT = server_tcp
CLI_FILES = MesgBuff.pb.cc client_tcp.cpp
CLI_OUT = client_tcp
CFLAGS = --std=c++11 $(WARNINGS) -g
INCLUDES = -I /cygdrive/c/cygwin64/usr/local/include/
LIBS = -L /cygdrive/c/cygwin64/usr/local/lib/
LNKS = -lprotobuf -lpthread

server: 
		@echo "============compiling server================"
		$(CC) $(CFLAGS) $(INCLUDES) $(LIBS) $(SER_FILES) -o $(SER_OUT) $(LNKS)
		@echo "=============running server================="
		./server_tcp
	
client:
		@echo "============compiling client================"
		$(CC) $(CFLAGS) $(INCLUDES) $(LIBS) $(CLI_FILES) -o $(CLI_OUT) $(LNKS)
		@echo "=============running client================="
		./client_tcp
		
clean:
		rm *.exe
