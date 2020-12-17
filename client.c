
// Client side C/C++ program to demonstrate Socket programming 
#include <stdio.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <unistd.h> 
#include <string.h> 
#include <stdio.h>
#include <stdlib.h>
 #include <unistd.h>
#include <string.h>

void reset(char *buffer){
    for(int i = 0; i < 1024; i++){
        buffer[i] = 0;
    }
}

int main(int argc, char const *argv[]) 
{ 
    if (argc < 3)
	{	// using command line argument
		printf("Usage: %s <serv_ip> <serv_port>\n", argv[0]);
		exit(1);
	}

    int sock = 0, valread; 
    struct sockaddr_in serv_addr; 
    char buffer[1024] = {0}; 
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
    { 
        printf("\n Socket creation error \n"); 
        return -1; 
    } 
    int PORT = strtoul(argv[2], NULL, 10);
    serv_addr.sin_family = AF_INET; 
    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
       
    
    if(inet_pton(AF_INET, argv[1], &serv_addr.sin_addr)<=0)  
    { 
        printf("\nInvalid address/ Address not supported \n"); 
        return -1; 
    } 
   
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
    { 
        printf("\nConnection Failed \n"); 
        return -1; 
    } 
    int input;
    char input_str[3];
    valread = read( sock , buffer, 1024); 
    printf("Server: %s\n",buffer ); 
    scanf("%d", &input);
    //printf("Input: %d", input);
    sprintf(input_str, "%d", input);
    send(sock , input_str , strlen(input_str) , 0 ); 

    reset(buffer);
    valread = read( sock , buffer, 1024); 
    printf("Server: %s\n",buffer ); 
    scanf("%d", &input);
    //printf("Input: %d", input);
    sprintf(input_str, "%d", input);
    send(sock , input_str , strlen(input_str) , 0 ); 

    reset(buffer);
    valread = read( sock , buffer, 1024); 
    printf("Server: %s\n",buffer ); 
    scanf("%d", &input);
    //printf("Input: %d", input);
    sprintf(input_str, "%d", input);
    send(sock , input_str , strlen(input_str) , 0 ); 

    reset(buffer);
    valread = read( sock , buffer, 1024); 
    printf("Server: %s\n",buffer ); 
    scanf("%d", &input);
    //printf("Input: %d", input);
    sprintf(input_str, "%d", input);
    send(sock , input_str , strlen(input_str) , 0 );
    reset(buffer);
    valread = read( sock , buffer, 1024); 
    printf("Server: %s",buffer );
    printf("\n");
    reset(buffer);
    valread = read( sock , buffer, 1024); 
    printf("%s",buffer );
    printf("\n");
    reset(buffer);
    valread = read( sock , buffer, 1024); 
    printf("%s",buffer ); 
    reset(buffer);
    valread = read( sock , buffer, 1024); 
    printf("%s",buffer ); 
    printf("\n");
    reset(buffer);
    valread = read( sock , buffer, 1024); 
    printf("%s",buffer ); 
    reset(buffer);
    valread = read( sock , buffer, 1024); 
    printf("%s",buffer ); 
    printf("\n");

    return 0; 
}


