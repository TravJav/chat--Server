//
//  main.cpp
//  chat- Server
//
//  Created by Travis Haycock on 2017-02-09.
//  Copyright © 2017 Travis Haycock. All rights reserved.
//



/*---8----------------8-----------8---------------8--------------------8-----------------------8--
 
SERVER SIDE OF THE CHAT PROGRAM- COMMAND LINE NO UI
 
 
 
 
 ----8--------------8---------------8--------------8---------------------8---------------------8-*/

#include <iostream>


#define PORT_NUMBER (800)


extern  "C" {
#include "StartConnection.h"
}


int main(int argc, const char * argv[]) {
   
    start_server();
    
 
    return 0;
}
