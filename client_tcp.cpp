#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <thread>
#include "MesgBuff.pb.h"

using namespace std;

void snd();
void rcv();
int sock, bytes_recieved;  
char send_data[1024],recv_data[1024];
struct hostent *host;
struct sockaddr_in server_addr;
MesgBuff mbc;
string crz_snd,crz_rcv;  
static int exit_flag=0;
int main()

{
		 host = gethostbyname("127.0.0.1");

        if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
           cerr<<"Socket error"<<endl;
            exit(1);
        }

        server_addr.sin_family = AF_INET;     
        server_addr.sin_port = htons(5000);   
        server_addr.sin_addr = *((struct in_addr *)host->h_addr);
        bzero(&(server_addr.sin_zero),8); 

        if (connect(sock, (struct sockaddr *)&server_addr,sizeof(struct sockaddr)) != 0) 
        {
            cerr<<"unable to Connect, server not avaible"<<endl;
            exit(1);
        }
		cout<<"SEND (q or Q to quit)"<<endl;
		thread sd(snd),rv(rcv);
		if(sd.joinable()){
				sd.join();
			}
			if(rv.joinable()){
				rv.join();
			}   
	return 0;
	}
void snd(){
	while(1){
			cout<<"sent : ";
			cin>>send_data;
            mbc.set_msg(send_data);
		    mbc.SerializeToString(&crz_snd);
          if (strcmp(crz_snd.c_str() , "q") == 0 || strcmp(crz_snd.c_str() , "Q") == 0){
			  exit_flag=1;
          	send(sock, crz_snd.c_str(),1024, 0);
			goto FINISH;
			}
           else{
           send(sock, crz_snd.c_str(),mbc.ByteSize(), 0);
        }
		mbc.Clear();
	}
	FINISH:
		close(sock);
		exit(0);
}
void rcv(){
	while(1){
			if(exit_flag==1){
				goto FINISH;
			}
			bytes_recieved=recv(sock,recv_data,1024,0);
			recv_data[bytes_recieved] = '\0';
			mbc.ParseFromString(recv_data);
			crz_rcv=mbc.msg();
          if (strcmp(crz_rcv.c_str() , "q") == 0 || strcmp(crz_rcv.c_str() , "Q") == 0){
			  goto FINISH;
          }
		   else{
		   		cout<<"Recieved : "<<crz_rcv<<endl;
       		}
			mbc.Clear();
	}
	FINISH:
		 //close(sock);
		 exit(0);
}
