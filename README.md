#PHYTEC TRAINEE PROJECT 

Week1 :

TOPIC:  
    
    1) C Core Concept
    2) OSI Model
    3) StateMachine
    4) Array,Pointer,Event
    5) Queue, Linked List, Circular Buffer
TASKS: 
https://www.notion.so/Embedded-Software-Trainee-Project-21da2c234f678020b9faea42f8105aa2?source=copy_link

    1) Documentation of OSI Model 
    2) Implementation of Queue, Linked List, Circular Buffer
    3) UDP Chat App
        i) Send/Receive Message
        ii) Using CommandLine Arugments
        
CHAT APP STEP BY STEP RUNNING PROCESS :
    
    1) To Compaile the Both Server and Client Source file
        i) gcc server.c -o server
        ii) gcc client.c -o client
    2) To run the both Object file with the Port and Loopback IP address
        i) ./server 8080
        ii) ./client 127.0.0.1 8080
    3) To Pass the Message Client to Server and Server to Client
PORT:

    1) Poart Address 0 - 1023 it's Reserverd port for service and standard Protocol(HTTP,HTTPS)
    2) 1024 - 49151 Registerd Ports 
    3) 49152 - 65535 Private and tempory Port

OUTPUT on the ChatApp
    ![image](https://github.com/user-attachments/assets/a910868e-f48a-46f2-814a-e63b69b2c60a)


