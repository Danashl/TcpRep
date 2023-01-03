# TcpRep
This code is a client-server implementation of the K-Nearest Neighbors (KNN) classification algorithm. It allows the client to send input data to the server, which will then classify the data using the KNN algorithm and return the result to the client.

We created two cpp files - client.cpp and server.cpp - each one with its own main. 
The server gets in the arguments a file with classified vectors and a port number for it to bind and listen. 
The client gets in the arguments the IP address and the port number of the server.
First, our client checks if the ip address and the port are valid. If not - it will not be able to connect to the server so it prints an error and exit the program. If they are valid - it creates a socket and a socket_addr with all the needed information of the socket for connecting the server and try to connect the server. If the creation of the socket or the connection with the server didn't work - it will print an error and exit the program.  
If the connection was successful, the client will start an infinite loop for getting input from the user. The input the client gets from the user is a vector to classify, a distance method and a K- the number of nearest neighbors - to use for classification. Our client will check that the input is in the form of double - string - int and if not it will print "invalid input" and will get a new input from the user. If the input is valid, it will send it to the server for classification.

The server checks if the file and the port are valid. If not - it will not be able to calssify the input or bind the port so it prints an error and exit the program. If they are valid - it create a socket and a socket_addr with all the needed information of the socket for the server to bind it and listen to it. If the binding of the socket or the listening didn't work - it will print an error and exit the program.  
If the connection was successful, the server will start an infinite loop for getting the user input from the client, check if it is valid and if so - classifing it and send the result to the client. In addition to what the client checked, the server will also check if the string is one of the distance methods and the k is positive and not bigger then the number of vectors in the file. If the input is not valid it will send the client "invalid input". If it is valid, it will classify it using the KNN algorithm from the previous exercises and send the result to the client.

The client will receive the message from the sever and print it, then it will start another loop with new input from the user to classify.
If there were any problem with the transfer of information from the client ot the server - the program will print an error and start another loop with new input.

You can see more information about the KNN algorithm in our previous exercises.

For executing the code we need to run the following command: make

The server will be activated by: server.out file port
The client will be activated by: client.out ip port
and then insert input of vector, dustance method and a k to the client.

For example: server.out iris_classified.csv 5555 , client.out 127.0.0.1 5555 , 1 2 3 4 MAN 3
The sever and the client will connect via port 5555. The client will send the sever the user input (1 2 3 4 MAN 3) and the server will classify it using the 3 closest neighbors in iris_classified file. Then the server will send the result to the client who will print it and take new input from user.
