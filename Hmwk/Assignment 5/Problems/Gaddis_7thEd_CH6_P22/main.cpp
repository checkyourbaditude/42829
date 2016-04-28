/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Christopher
 *
 * Created on April 23, 2016, 8:10 PM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

//functional prototypes
void isPrime(int num);

int main(int argc, char** argv) {
    //variables
    int input=0;
    bool result=true;
    
    //open the output file and create the file stream object
    ofstream outputFile;
    outputFile.open("primes.txt");
    
    //get the number from the user
    cout<<"This program is going to output all of the prime numbers up to"<<endl;
    cout<<"the number that you give it into a file called prime.txt!"<<endl;
    cout<<"What is the upper limit you would like to check for prime numbers?"<<endl;
    cin>>input;
    
    //call the function
    isPrime(input);
    
    return 0;
}

void isPrime(int num){
    //set the first divisable number to n-1, subtract until it goes to 2
    ofstream outputFile;
    outputFile.open("primes.txt");
    
    //begin the loop
    start:while(num>=1){
        for(int i=(num-1);i>1;i--){
            if(num%i==0){
                num--;
                goto start;
            }
        }
        outputFile<<num<<" ";
        num--;
    }
    outputFile.close();
}

