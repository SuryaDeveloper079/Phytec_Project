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
OUTPUT ON CHATAPP
    ![image](https://github.com/user-attachments/assets/a910868e-f48a-46f2-814a-e63b69b2c60a)

#RB A5D2X to PC Chat APP

    1)To Connect the Board on your PC Through the USB
    2)Give me the Ethernet connection on your board 
 	    i)To create the Ethernet Profile
 ![image](https://github.com/user-attachments/assets/c33722b1-deff-4ed9-8ba7-24e0fd3b44d3)
 	    ii)Then to select the Profile
Run the Host Side  

	i) To Compaile the server.c
		gcc server.c -o server
	ii)To Run the Object File with give me the PORT Also
		./server 8080
Run the Board side

	Host side task:
		i) To Enable the Toolchain
			. /opt/poky-tiny/2.5.2/environment-setup-cortexa5hf-neon-poky-linux-musleabi
		ii) To cross Compaile the client.c fileon your host 
			* ${cc} client.c -o client
  			* echo $cc #outout ""
  			* cc=gcc
			* echo $cc #"output "gcc"
	
				(or)
	
			* sudo apt update
  			* sudo apt install gcc-arm-linux-gnueabihf
			* arm-linux-gnueabihf-gcc -static -o client client.c
 		iii) To Copy the Object file on tftpboot
 			* sudo cp client /var/lib/tftpboot/ # copy the object file
			* sudo ls client /var/lib/tftpboot/ # To check the file is copy or not
	
	RB Board side Task:
		i) To config the Ethernet connection
			* ifconfig eth0
		ii) To check this link status
			* cat /sys/class/net/eth0/carrier
				1 = Link detected (connected)
				0 = No link (disconnected or no signal)
		iii) Ping the server your IPv4 Address
			* ping 192.168.1.1
		iv) Then Copy the Client Object file in Rugged Board
			* tftp -g -r client 192.168.1.1
		v) To change the File Permision
			* chmod +x client (or) chmod 777 client
			* give me "ls" command to check the file is Executable formate
		vi) To run the file
			* ./filename address poart
				./client 192.168.1.1 8080   
OUT PUT
        ![PC_to_Board](https://github.com/user-attachments/assets/86707ac6-a091-4c52-9445-6096f924d687)




