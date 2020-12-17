# **TCP Socket Using C Programming**

Socket Programing for Details Update Application

Implement simple client and server Socket using TCP protocol which performs below operation:

1. On Connection with Server, Client Shall be prompted to Input last 3 digits of Your prn No:
2. After I/P Client Will Prompt to Provide Marks in 3 Subjects: Physics, Chemistry & Mathematics 
3. After Updating the Details, Confirmation on successful update must come from server: 

goto bash run **first run server**

Run Server:

$gcc server.c -o server.out


Run client:

$gcc client.c -o client.out

$./client.out <Server IP>  9000  

**Note: port bind to default 9000 in given sample code**
  
Sample output after running client:

Server: Enter Your PRN No:

012

Server: Enter your Physics Marks:

80

Server: Enter your Chemistry Marks:

80

Server: Enter your Mathematics Marks:

80

Server: Details Updated Successfully 

Your Details:

PRN:012

Percentage:80
