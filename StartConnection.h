//
//  StartConnection.h
//  chat- Server
//
//  Created by Travis Haycock on 2017-02-09.
//  Copyright © 2017 Travis Haycock. All rights reserved.
//

#ifndef StartConnection_h
#define StartConnection_h

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/uio.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>


void check_running();
void start_server();
char print_error(char *);
void wait_for_connection();

void send_file();

#endif /* StartConnection_h */
