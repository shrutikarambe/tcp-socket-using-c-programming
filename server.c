
// Server side C/C++ program to demonstrate Socket programming 
#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#define PORT 9000 

void reset(char *buffer){
    for(int i = 0; i < 1024; i++){
        buffer[i] = 0;
    }
}

int main(int argc, char const *argv[]) 
{ 
    int server_fd, new_socket, prn_no, physics_marks,chemistry_marks,maths_marks; 
    struct sockaddr_in address; 
    int opt = 1; 
    int addrlen = sizeof(address); 
    char buffer[1024] = {0}; 
    char *prn = "Enter Your PRN No:"; 
    char *physics = "Enter your Physics Marks:"; 
    char *chemistry = "Enter your Chemistry Marks:"; 
    char *maths = "Enter your Mathematics Marks:";  
    char *msg_1 = "Details Updated Successfully"; 
    char *msg_2 = "Your Details:"; 
    char *msg_3 = "PRN:"; 
    char *msg_4 = "Percentage:"; 

    
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) 
    { 
        perror("socket failed"); 
        exit(EXIT_FAILURE); 
    } 
       
    
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, 
                                                  &opt, sizeof(opt))) 
    { 
        perror("setsockopt"); 
        exit(EXIT_FAILURE); 
    } 
    address.sin_family = AF_INET; 
    address.sin_addr.s_addr = INADDR_ANY; 
    address.sin_port = htons( PORT ); 
       
    
    if (bind(server_fd, (struct sockaddr *)&address,  
                                 sizeof(address))<0) 
    { 
        perror("bind failed"); 
        exit(EXIT_FAILURE); 
    } 
    if (listen(server_fd, 3) < 0) 
    { 
        perror("listen"); 
        exit(EXIT_FAILURE); 
    } 
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address,  
                       (socklen_t*)&addrlen))<0) 
    { 
        perror("accept"); 
        exit(EXIT_FAILURE); 
    } 
    send(new_socket , prn , strlen(prn) , 0 ); 
    read( new_socket , buffer, 1024);
    prn_no = atoi(buffer);
    printf("PRN no: %d\n", prn_no); 

    reset(buffer);
    send(new_socket , physics , strlen(physics) , 0 ); 
    read( new_socket , buffer, 1024);
    physics_marks = atoi(buffer);
    printf("Physics Marks: %d\n", physics_marks); 

    reset(buffer);
    send(new_socket , chemistry , strlen(chemistry) , 0 ); 
    read( new_socket , buffer, 1024);
    chemistry_marks = atoi(buffer);
    printf("Chemistry marks: %d\n", chemistry_marks); 

    reset(buffer);
    send(new_socket , maths , strlen(maths) , 0 ); 
    read( new_socket , buffer, 1024);
    maths_marks = atoi(buffer);
    printf("maths marks: %d\n", maths_marks); 

    int average = ((physics_marks + chemistry_marks + maths_marks) * 100) / 300 ;
    send(new_socket , msg_1 , strlen(msg_1) , 0 ); 
    send(new_socket , msg_2 , strlen(msg_2) , 0 );
    send(new_socket , msg_3 , strlen(msg_3) , 0 );
    char* msg;
    sprintf(msg, "%d", prn_no);
    send(new_socket , msg , strlen(msg) , 0 );
    send(new_socket , msg_4 , strlen(msg_4) , 0 );    
    sprintf(msg, "%d", average);
    send(new_socket , msg , strlen(msg) , 0 );

    return 0; 
} 
