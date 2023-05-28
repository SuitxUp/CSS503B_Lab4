//Brandon St Pierre
//Lab4

#include "udp_multicast.h" 
#include <iostream>     
using namespace std;

#define SIZE 1024    

int main(int argc, char *argv[]) 
{
  // validate arguments                                                                             
  if (argc < 3) 
  {
	  cerr << "usage: lab4 group port [message]" << endl;
	  return -1;
  }

  char *group = argv[1];
  int port = atoi(argv[2]);

  if (port < 5001) 
  {
	  cerr << "usage: lab4 group port [message]" << endl;
	  return -1;
  }
  char *message = (argc == 4) ? argv[3] : NULL;

  // if message is null, the program should behave as a server,
  // otherwise as a client.
  UdpMulticast udp(group, port);

  if (message != NULL) 
  { 
	  // client
	  // implement  yourself
      int clientSD = udp.getClientSocket();

      if(clientSD == NULL_SD){
         cerr << "failed to create client" << endl;
         return -1;
      }

     if(udp.multicast(message)){
      //do nothing
     } else{
      cout << "Failed to send message" << endl;
     }
     
  }
  else 
  {
	  int serverSD = udp.getServerSocket();
     if(serverSD == NULL_SD){
         cerr << "failed to create server" << endl;
         return -1;
      }

	  while (true) 
	  {
	   // server
      // implement  yourself
      char buf[SIZE];

      if(udp.recv(buf, SIZE)){
         
         string receieved = buf;
         cout << receieved << endl;
      }else{
         cerr << "Failed to get message" << endl;
      }
	  }
  }
  return 0;
}
