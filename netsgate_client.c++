// Netsgate client
// Copyright © 2014 Dawid Wiktor
// Wejdź: lunalinx.wordpress.com
int gniazdo = socket( PF_INET, SOCK_STREAM, 0 );

struct hostent * dane_host;
struct sockaddr_in dane;

dane_host = gethostbyname( host.c_str() );

dane.sin_family = PF_INET;
dane.sin_port = htons( port );
dane.sin_addr = *(( struct in_addr * ) dane_host->h_addr );
memset( &( dane.sin_zero ), '\0', 8 );

int connect( int sockfd, struct sockaddr * serv_addr, int addrlen );

if(connect( gniazdo,( struct sockaddr * ) & dane, sizeof( struct sockaddr ) ) == -1) {
    cout<<"Nie połączono!"<<endl;
    return 0;
  } else 
    cout<<"Połączono!"<<endl;
#include <cerrno>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>
#include <netdb.h>
#include <fcntl.h>

using namespace std;

int gniazdo, numbytes, port;
string host, nick;
char msg[1024];
string msg2;
struct hostent * dane_host;
struct sockaddr_in dane;
int main()
{
  cout<<"Podaj port: ";
  cin>>port;
  cout<<"Podaj IP hosta: ";
  cin>>host;
  cout<<"Podaj nick: ";
  cin>>nick;
  dane_host = gethostbyname( host.c_str() );
  dane.sin_family = PF_INET;
  dane.sin_port = htons( port );
  dane.sin_addr = *(( struct in_addr * ) dane_host->h_addr );
  memset( &( dane.sin_zero ), '\0', 8 );
  
  
  gniazdo = socket( PF_INET, SOCK_STREAM, 0 );
    
  if(connect( gniazdo,( struct sockaddr * ) & dane, sizeof( struct sockaddr ) ) == -1) {
    cout<<"Nie połączono!"<<endl;
    return 0;
  } else 
    cout<<"Połączono!"<<endl;
  
  fcntl( gniazdo, F_SETFL, O_NONBLOCK );
  string komenda;
  
  do {
    cin>>komenda;
    if(komenda == "send") {
      cin.ignore(1);
      getline(cin,msg2);
      msg2 = nick + ": " + msg2;
      send( gniazdo, msg2.c_str(), msg2.size(), 0 );
    }
    if(komenda == "recv") {
      recv( gniazdo, msg, 1024, 0 );
      cout<<msg<<endl;
    }
    
  } while(komenda != "exit netsgate");
  
  close( gniazdo );
  return 0;
}
