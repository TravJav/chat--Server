//
//  StartConnection.c
//  chat- Server
//
//  Created by Travis Haycock on 2017-02-09.
//  Copyright © 2017 Travis Haycock. All rights reserved.
//

#include "StartConnection.h"


//  Created by Travis Haycock on 2017-02-09.
//  Copyright © 2017 Travis Haycock. All rights reserved.
//


/*---8----------------8-----------8---------------8--------------------8-----------------------8--
 
 SERVER SIDE OF THE CHAT PROGRAM- COMMAND LINE NO UI
 
 
 
 
 ----8--------------8---------------8--------------8---------------------8---------------------8-*/




#define FILENAME "/Users/travishaycock/Desktop/numbers.txt"
#define LENGTH (512)
#define TRUE (1)
#define FALSE (0)
#define PORT_NUMBER (20022)
int welcomeSocket, newSocket;
struct sockaddr_in serverAddr;
struct sockaddr_storage serverStorage;
socklen_t addr_size;
 const char buffer [LENGTH];





void start_server(){
    
    
    
    
    /*---- Create the socket. The three arguments are: ----*/
    /* 1) Internet domain 2) Stream socket 3) Default protocol (TCP in this case) */
    welcomeSocket = socket(PF_INET, SOCK_STREAM, 0);
    
    /*---- Configure settings of the server address struct ----*/
    /* Address family = Internet */
    
    serverAddr.sin_family = AF_INET;
    
    
    
    /* Set port number, using htons function to use proper byte order */
    serverAddr.sin_port = htons(PORT_NUMBER);
    
    
    
    /* Set IP address to localhost */
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    
    /* Set all bits of the padding field to 0 */
    memset(serverAddr.sin_zero, '\0', sizeof serverAddr.sin_zero);
    
    /*---- Bind the address struct to the socket ----*/
    bind(welcomeSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr));
    
    
    
    
    
    /*---- Listen on the socket, with 5 max connection requests queued ----*/
    if(listen(welcomeSocket,5)==0)
        printf("Listening\n");
    else
        printf("Error\n");
    
    /*---- Accept call creates a new socket for the incoming connection ----*/
    addr_size = sizeof serverStorage;
    
    
    
    
    
    newSocket = accept(welcomeSocket, (struct sockaddr *) &serverStorage, &addr_size);
    
    
    
    
    /*---- Send message to the socket of the incoming connection ----*/
    
    
    printf("\n OK PRINT MESSAGE");
    char info[100];
    scanf("%s",&info);
    
   // strcpy(buffer,info);
    
   // send(newSocket,buffer,13,0);
    
   send_file();
    
    close(welcomeSocket);

}


/*
 Send file method open file and send it
 
 */
void send_file(){
    
    
    
    char recv_str[LENGTH]; /* to store received string */
    ssize_t rcvd_bytes; /* bytes received from socket */
    /* read name of requested file from socket */

    int sent_count; /* how many sending chunks, for debugging */
    ssize_t read_bytes, /* bytes read from local file */
    sent_bytes, /* bytes sent to connected socket */
    sent_file_size;
    char send_buf[LENGTH]; /* max chunk size for sending file */
    char * errmsg_notfound = "File not found On Computer\n";
    int f; /* file handle for reading local file*/
    sent_count = 0;
    sent_file_size = 0;
    
    
    /* attempt to open requested file for reading */
    if( (f = open(FILENAME, O_RDONLY)) < 0) /* can't open requested file */
    {
        perror(FILENAME);
        if( (sent_bytes = send(newSocket, errmsg_notfound , strlen(errmsg_notfound), 0)) < 0 )
        {
            perror("send error");
           
        }
    }
    else /* open file successful */
    {
        printf("Sending file: %s\n", FILENAME);
        while( (read_bytes = read(f, send_buf, LENGTH)) > 0 )
        {
            if( (sent_bytes = send(newSocket, send_buf, read_bytes, 0))
               < read_bytes )
            {
                perror("send error");
            
            }
            sent_count++;
            sent_file_size += sent_bytes;
        }
        close(f);
    } /* end else */
    printf("Done with this client. Sent %d bytes in %d send(s)\n\n",sent_file_size, sent_count);

}
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    













