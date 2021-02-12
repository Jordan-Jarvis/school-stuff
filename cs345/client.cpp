/****************************************************************************
* Program:
*    Lab RockClientT2, Rock/Paper/Scissors with Sockets - Client Code
*    Brother Jones, CSE354
* Author:
*    Jordan Jarvis
* Summary:
*    This is a client for a Rock Paper Scissors game which runs over TCP.
*
*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <iostream>
#include <arpa/inet.h>
#include <iostream>
#include <string.h>
using namespace std;

#define PORT "3490" // the port client will be connecting to 

#define MAXDATASIZE 120 // max number of bytes we can get at once 
#define MAXSENDSIZE 8 // max send size
/******************************************************************
 * get sockaddr, IPv4 or IPv6:
 *****************************************************************/
void *get_in_addr(struct sockaddr *sa)
{
   if (sa->sa_family == AF_INET)
   {
      return &(((struct sockaddr_in*)sa)->sin_addr);
   }

   return &(((struct sockaddr_in6*)sa)->sin6_addr);
}

/******************************************************************
 * isNumber checks if all the chars in a given array are digits
 * then returns true or false.
 *****************************************************************/
bool isNumber(char number[])
{
    int i = 0;

    //checking for negative numbers
    if (number[0] == '-')
        i = 1;
    for (; number[i] != 0; i++)
    {
        //if (number[i] > '9' || number[i] < '0')
        if (!isdigit(number[i]))
            return false;
    }
    return true;
}

/******************************************************************
 * Main runs a basic rock paper scissors game and send input to 
 * the server application to find a winner.
 *****************************************************************/
int main(int argc, char *argv[])
{
   int sockfd;
   int numbytes;  
   char buf[MAXDATASIZE];
   char sendBuf[MAXDATASIZE];
   struct addrinfo hints;
   struct addrinfo *servinfo;
   struct addrinfo *p;
   int rv;
   char s[INET6_ADDRSTRLEN];

   if (argc != 2 && argc != 3)
   {
      
      fprintf(stderr,"usage: client hostname, port (optional)\n");
      exit(1);
   }
   if (argc == 3)
   {
      if (!isNumber(argv[2]))
      {
         cout << "Invalid port number! Exiting.\n";
         return 0;
      }
   }
   memset(&hints, 0, sizeof hints);
   hints.ai_family = AF_UNSPEC;
   hints.ai_socktype = SOCK_STREAM;
   if (argc != 3)
   {
      cout << "No port specified, defaulting to port: " << PORT << endl;
      if ((rv = getaddrinfo(argv[1], PORT, &hints, &servinfo)) != 0)
      {
         fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
         return 1;
      }
   }
   else
   {
      cout << "Starting client on port: "  << argv[2] << endl;
      if ((rv = getaddrinfo(argv[1], argv[2], &hints, &servinfo)) != 0)
      {
         fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
         return 1;
      }
   }

   // loop through all the results and connect to the first we can
   servinfo = servinfo->ai_next; // correct for extra connection attempt
   for (p = servinfo; p != NULL; p = p->ai_next)
   {
      if ((sockfd = socket(p->ai_family, p->ai_socktype,
            p->ai_protocol)) == -1)
      {
         perror("client: socket");
         continue;
      }
      if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1)
      {
         perror("client: connect");
         close(sockfd);
         continue;
      }
      break;
   }
   if (p == NULL)
   {
      fprintf(stderr, "client: failed to connect\n");
      return 2;
   }
   inet_ntop(p->ai_family, get_in_addr((struct sockaddr *)p->ai_addr),
         s, sizeof s);
   printf("client: connecting to %s\n", s);
   freeaddrinfo(servinfo); // all done with this structure
   memset(buf,0,strlen(buf));
   if ((numbytes = recv(sockfd, buf, MAXDATASIZE, 0)) == -1)
   {
      perror("recv"); // wait for second player
      exit(1);
   }
   char temp[10];
   buf[numbytes] = '\0';   

      
   
   if(buf[0] != 'C' || buf[1] != 'O' || buf[2] != 'N' || buf[3] != 'N')
   {
      cout << "\nERROR! Not a RPS server!\n";
   }
   
   if (send(sockfd, "CONN\n", MAXSENDSIZE, 0) == -1)
      perror("send");


   if ((numbytes = recv(sockfd, buf, MAXDATASIZE, 0)) == -1)
   {
      perror("recv"); // wait for second player
      exit(1);
   }
   buf[numbytes] = '\0';
   if(buf[0] != 'O' || buf[1] != 'P' || buf[2] != 'F' || buf[3] != 'O' || buf[4] != 'U' || buf[5] != 'N' || buf[6] != 'D')
   {
      cout << "\nERROR! No other player found.\n";
      return 0;
   }
   
   if (send(sockfd, "READY\n", MAXSENDSIZE, 0) == -1) // send player response.
         perror("send");

   if ((numbytes = recv(sockfd, buf, MAXDATASIZE, 0)) == -1)
   {
      perror("recv"); // wait for second player
      exit(1);
   }
   buf[numbytes] = '\0';
   if(buf[0] != 'R' || buf[1] != 'O' || buf[2] != 'U' || buf[3] != 'N' || buf[4] != 'D')
   {
      cout << "\nERROR! No other player found.\n";
      return 0;
   }

   cout << "\n------------------------------\n ------ Welcome to Rock Paper Scissors! ------\n------------------------------\n";
   string getResponse;
   char response[1];
   while(true)
   {
      cout << "Please enter r for rock, p for paper, \nand s for scissors. Enter Q for quit.\nInput: ";
      cin >> getResponse; // string to avoid potential overflows
      if (!(getResponse[0] == 'r' || getResponse[0] == 'R' || 
      getResponse[0] == 'p' || getResponse[0] == 'P' ||
      getResponse[0] == 's' || getResponse[0] == 'S' ||
      getResponse[0] == 'q' || getResponse[0] == 'Q'))
      {
         cout << "Invalid input! Please try again.\n";
         continue;
      }
      memset(buf,0,strlen(buf));
      buf[0] = toupper(getResponse[0]); // get char
      buf[1] = '\n';
      if (send(sockfd, buf, MAXSENDSIZE, 0) == -1) // send player response.
         perror("send");
      memset(buf,0,strlen(buf));
      if ((numbytes = read(sockfd, buf, MAXDATASIZE)) == -1) // get winner
      {
         perror("recv");
         exit(1);
      }
      buf[numbytes] = '\0'; // specify the buffer as char
      if (buf[0] == 'W')
      {
         cout << "\033[1;32m\nWe have a winner! You win!\n\n\033[0m";

      }
      else if (buf[0] == 'Q')
      {
         cout << "\nThanks for playing! A player has quit the game. \n";
         close(sockfd);
         return 0;
      }
      else if (buf[0] == 'D')
      {
         cout << "\033[1;33m\nIt was a Tie!\n\n\033[0m";
      }
      else
      {
         cout << "\033[1;31m\nYou Lost!\n\n\033[0m";

      }
   }
   return 0;
}

