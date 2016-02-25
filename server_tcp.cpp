#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <thread>
#include <fstream>
#include "MesgBuff.pb.h"
#include "RHMI_API.hpp"

using namespace std;

void rcvs();
void snds();

int sock, connected, bytes_received , yes = 1;
char send_data [1024] , recv_data[1024];
struct sockaddr_in server_addr,client_addr;
int sin_size;
MesgBuff *mb = new MesgBuff();
string srz_snd,srz_rcv;

char imageid[]="image1";
char imgurl[]="imgurl";
int main()
{
		//check RHMI is ready/not
		if(RHMI_Ready()){
			cout<<"RHMI is running"<<endl;
		}

        //connect to socket
        if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
            cerr<<"Socket error"<<endl;
            exit(1);
        }


        if (setsockopt(sock,SOL_SOCKET,SO_REUSEADDR,&yes,sizeof(int)) == -1) {
            cerr<<"Setsockopt"<<endl;
            exit(1);
        }
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(8001);
        server_addr.sin_addr.s_addr = INADDR_ANY;
        bzero(&(server_addr.sin_zero),8);

		//bind to ipaddress to port
        if (bind(sock, (struct sockaddr *)&server_addr, sizeof(struct sockaddr)) == -1) {
            cerr<<"Unable to bind"<<endl;
            exit(1);
        }

		if (listen(sock, 5) == -1) {
            cerr<<"unable to listen for clients"<<endl;
            exit(1);
        }

		cout<<"TCPServer Waiting for client on port 8001"<<endl;

		GOOGLE_PROTOBUF_VERIFY_VERSION;

            sin_size = sizeof(struct sockaddr_in);

            connected = accept(sock, (struct sockaddr *)&client_addr,&sin_size);

            cout<<"connected to client : "<<inet_ntoa(client_addr.sin_addr)<<":"<<ntohs(client_addr.sin_port)<<endl;
			cout<<"SEND (q or Q to quit)"<<endl;
				thread sds(snds),rvs(rcvs);
				if(sds.joinable()){
					sds.join();
				}
				if(rvs.joinable()){
					rvs.join();
				}
	  close(sock);
      return 0;
}

inline void closeSock(){
		if(shutdown(connected,SHUT_RDWR)==0 && close(sock)==0){
			cout<<"connection closed"<<endl;
		}
		else{
			cout<<"connection closing error"<<endl;
		}
		exit(1);
}

void rcvs(){
	while(1){
				bytes_received = recv(connected,recv_data,1024,0);
				recv_data[bytes_received] = '\0';
				srz_rcv=recv_data;
				mb->ParseFromString(srz_rcv);
				srz_rcv=mb->msg();
              if (strcmp(srz_rcv.c_str() , "q") == 0 || strcmp(srz_rcv.c_str() , "Q") == 0){
				closeSock();
              }
			  else if(strcmp(srz_rcv.c_str() , "deleteimage") == 0){
				  if(FSA_DeleteImage(imageid,imgurl)){
					  cout<<"image delete"<<endl;
				  }
				  else{
					  cout<<"image not deleted"<<endl;
				  }
			  }
			  else{
              	cout<<inet_ntoa(client_addr.sin_addr)<<" : "<<srz_rcv<<endl;
              }
			   mb->Clear();
	}
}

void snds(){
	while(1){
				 cout<<"sent : ";
				 cin>>send_data;
				 mb->set_msg(send_data);
				 mb->SerializeToString(&srz_snd);
              if (strcmp(srz_snd.c_str() , "q") == 0 || strcmp(srz_snd.c_str() , "Q") == 0){
                send(connected, srz_snd.c_str(),1024, 0);
					closeSock();
              }
              else{
                 send(connected, srz_snd.c_str(),mb->ByteSize(), 0);
			  }
			  mb->Clear();
	}
}
