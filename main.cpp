/*
#include <string>
#include <string.h>
#include <iostream>
#include <vector>
#include <float.h>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include "Knn.h"

using namespace std;

*/
/**
 * check that the user added values and that all the values are numbers.
 * if not - it prints an error to the user and changes a flag so later the code will not go to the knn part.
 * @param str1 - the vector from the user.
 * @param flag - an indicator for the validate of the vector.
 * @return the values that the user entered in a vector.
 *//*

vector<double> checkingInput(string str1, int& flag) {
    vector<double> v1;
    double num;
    stringstream stringstream1(str1);
    //entering the numbers into a vector.
    while(stringstream1 >> num) {
        v1.push_back(num);
    }
    //checking if it is the end of the values that the user entered. if it is not the end - the input is not valid.
    if(!stringstream1.eof()) {
        cout << "Input not valid!" << endl;
        flag = 1;
    }
    //checking that the user added values.
    if (v1.empty()) {
        cout << "No parameters added!" << endl;
        flag = 1;
    }
    return v1;
}

*/
/**
 * check that the arguments in the line command are valid
 * (that k is an positive number and that the distance is one of the distance options from the previous exercise).
 * if not - it prints an error to the user and exit the code.
 * @param argv - the arguments in the line command.
 *//*

void checkingArgv(char *argv[]) {
    if((stoi(argv[1])<=0) ||
            ((strcmp(argv[3],"AUC")!=0) && (strcmp(argv[3],"MAN")!=0) && (strcmp(argv[3],"CHB")!=0)
            && (strcmp(argv[3],"CAN")!=0) && (strcmp(argv[3],"MIN")!=0))) {
        cout << "Input not valid!" << endl;
        exit(0);
    }
}

*/
/**
 * the main function - get arguments from the line command and a vector from the user,
 * check validate and call the knn methods.
 * @param argc - the number of the values in argv.
 * @param argv - the arguments in the line command - k - the k nearest neighbors, file - the file with all the vector
 * for comparing, and distance - the distance method that the user want to compare by.
 *//*

int main (int argc, char *argv[]) {
    int flag = 0;
    vector<double> vecInput;
    //checking that the arguments in the line command are valid.
    checkingArgv(argv);
    int k = stoi(argv[1]);
    string file = argv[2];
    string dis = argv[3];
    string input1;
    while (true) {
        //getting a vector from the user.
        getline(cin, input1);
        if ((double) input1.size() >= log(DBL_MAX) - 1) {
            input1 = input1.substr(0, sizeof(double));
        }
        //check if the vector that the user entered is valid.
        vecInput = checkingInput(input1,flag);
        if(flag!=1) {
            //calling knn methods.
            Knn *knn = new Knn(k, dis, vecInput);
            knn->uploadFiles(file);
            delete knn;
        }
        flag = 0;
    }
}
*/
