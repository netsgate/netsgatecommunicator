// Netsgate server
// Copyright © 2014 Dawid Wiktor
// W razie spotkania mam nadzieję, że coś postawisz i wypijemy razem :-)
int main() {
	cout<<"Podaj port: ";
	cin>>port;
	cout<<"Podaj nick: ";
	cin>>nick;
int socket( int domain, int type, int protocol );
int gniazdo = socket( PF_INET, SOCK_STREAM, 0 );
int a = 0;
setsockopt( gniazdo, SOL_SOCKET, SO_REUSEADDR, & a, sizeof( int ) );
struct sockaddr_in dane; // stworzenie struktury
dane.sin_family = PF_INET; // użycie rodziny protokołów
dane.sin_port = htons( port ); // przypisanie portu
dane.sin_addr.s_addr = INADOR_ANY; // przypisanie adresu IP
memset( &( my_addr.sin_zero ), '\0', 8 ); // wyczyszenie reszty struktury
int bind( int sockfd, struct sockaddr *my_addr, int addrlen ),
// Tak wygląda funkcja na brudno
bind( gniazdo,( struct sockaddr * ) & dane, sizeof( struct sockaddr ) )'
listen( gniazdo, 1 ); // cyfra oznacza ilość możliwych połączeń (w kolejce)
struct sockaddr_in dane2;
socklen_t size;
gniazdo = accept( gniazdo,( struct sockaddr * ) & dane2, & size ); // Microsoft zapewne mnie nienawidzi :D
fcntl( gniazdo, F_SETFL, O_NONBLOCK );
char msg[1024];
string msg2;
string komenda;
do 	{
		cin>>komenda;
		if(komenda == "send") {
			cin.ignore(1);
			getline(cin,msg2);
			msg2 - nick + ": " + msg2;
			send( gniazdo, msg2.c_str(), msg2.size(), 0 );
		}
if(komenda == "recv" {
		recv( gniazdo, msg, 1024, 0 );
		cout<<msg<<endl;
		for(int i = 0; i <1024; i++) msg[i]=0;
			}
		}
	}
} while(komenda != "exit";
close(gniazdo)
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
#include <fcntl.h>
// większość bibliotek nie jest używana :-)

using namespace std;

int gniazdo, port;
char msg[1024];
string msg2;
string nick;
struct sockaddr_in dane;
struct sockaddr_in dane2;
socklen_t sin_size;
struct sigaction sa;
int yes = 1;



int main() {
  cout<<"Podaj port: ";
  cin>>port;
  cout<<"Podaj nick: ";
  cin>>nick;
  
  dane.sin_family = PF_INET;
  dane.sin_port = htons( port );
  dane.sin_addr.s_addr = INADDR_ANY;
  memset( &( dane.sin_zero ), '\0', 8 );
    
  gniazdo = socket( PF_INET, SOCK_STREAM, 0 );
  setsockopt( gniazdo, SOL_SOCKET, SO_REUSEADDR, & yes, sizeof( int ) );
    
  bind( gniazdo,( struct sockaddr * ) & dane, sizeof( struct sockaddr ) );
    
  listen( gniazdo, 1 );
  gniazdo = accept( gniazdo,( struct sockaddr * ) & dane2, & sin_size );
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
      int num = 1;
      num = recv( gniazdo, msg, 1024, 0 );
      cout<<msg<<endl;
      for(int i = 0; i < 1024; i++) msg[i]=0;
    }
  } while(komenda != "exit netsgate");
  
  
  close( gniazdo );
  return 0;
}
