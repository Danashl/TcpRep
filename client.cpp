//
// Created by danas on 30/12/2022.
//

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <stdexcept>
#include <cfloat>
#include <valarray>

using namespace std;

/**
 * checking arguments for the client.
 * @param port - the port number - should be between 1 to 65535.
 * @param ip_address - the IP address - should be in IP4 format.
 */
void checkingClientArgv(int port, string ip_address){
    uint32_t sa;
    if(port < 1024 || port > 65535) {
        cout << "invalid port number!" << endl;
        exit(1);
    }
    int checkIP = inet_pton(AF_INET, ip_address.c_str() ,&sa);
    if (checkIP != 1){
        cout << "invalid IP address!" << endl;
        exit(1);
    }
}

/**
 * checking the user input.
 * @param user_input - all the input from the user. if the input is "-1" then it will close the client socket and exit the program.
 * @param sock - the socket of the client.
 * @param check - a flag for knowing in the main if the input is valid or not.
 */
void checkingUserInput(string user_input, int sock, int& check) {
    vector<double> vec;
    double doubleNum;
    string str;
    int intNum;

    //check if the input is -1 and if so close the socket and exit the program.
    if(user_input == "-1"){
        close(sock);
        exit(1);
    }
    //converting a number to a stream
    stringstream ss(user_input);
    //check if there is a vector of double numbers at the beginning of the input
    while (ss >> doubleNum) {
        vec.push_back(doubleNum);
    }
    if (vec.empty()) {
        cout << "invalid input" << endl;
        check = 1;
        return;
    }
    ss.clear();
    //check that there is a string after the vector.
    if(ss >> str){
        ss << str;
    }
    if(str.empty()){
        cout << "invalid input" << endl;
        check = 1;
        return;
    }
    //check that there is an int number.
    ss.clear();
    if(ss >> intNum){
        ss << intNum;
    }
    //check that this is the end of the stream.
    if(!ss.eof()) {
        check = 1;
        return;
    }
}


    int main(int argc, char *argv[]) {
        string user_input;
        const char *ip_address = argv[1];
        const int client_port = atoi(argv[2]);
        //checking that the arguments are valid.
        checkingClientArgv(client_port, ip_address);
        //creating a socket for the client.
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock < 0) {
            cout<< "error creating socket" <<endl;
            exit(1);
        }
        //creating a sockaddr_in with all the information of the socket.
        struct sockaddr_in sin;
        memset(&sin, 0, sizeof(sin));
        sin.sin_family = AF_INET;
        sin.sin_addr.s_addr = inet_addr(ip_address);
        sin.sin_port = htons(client_port);
        //connecting to the server.
        if (connect(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
            cout << "error connecting to server" << endl;
            exit(1);
        }
        //getting an input from the user and sending it to the server.
        while (true) {
            int check = 0;
            //getting a vector, a distance method and the number of neighbors from the user.
            getline(cin, user_input);
            if ((double) user_input.size() >= log(DBL_MAX) - 1) {
                user_input = user_input.substr(0, sizeof(double));
            }
            //checking ig the input from the user is valid and just if it is - sending it to the server.
            checkingUserInput(user_input, sock, check);
            if (check == 0) {
                int data_len = user_input.length();
                const char *data_addr = user_input.c_str();
                int sent_bytes = send(sock, data_addr, data_len, 0);
                if (sent_bytes < 0) {
                    cout << "error sending a message" << endl;
                    break;
                }
                // getting the result from the server.
                char buffer[4096] = {0};
                int expected_data_len = sizeof(buffer);
                int read_bytes = recv(sock, buffer, expected_data_len, 0);
                if (read_bytes == 0) {
                    cout << "no result from the server" << endl;
                    break;
                }
                if (read_bytes < 0) {
                    cout << "error getting a message from the server" << endl;
                    break;
                }
                // convert buffer to a string
                string result(buffer);
                cout << result << endl;
            } else {
                cout << "invalid input" << endl;
            }
        }
    }


