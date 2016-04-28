/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Christopher
 *
 * Created on April 23, 2016, 7:58 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

//functional prototypes
bool isPrime21(int num);

int main(int argc, char** argv) {
    //variables
    int input=0;
    bool result=true;
    
    //get the number from the user
    cout<<"This program is going to check to see a number is a prime number"<<endl;
    cout<<"What number would you like to check?"<<endl;
    cin>>input;
    
    //call the funtion
    result=isPrime21(input);
    
    //let user know the result
    if (result=1){
        cout<<input<<" is not a prime number!"<<endl;
    }
    else {
        cout<<input<<" is not a prime number!"<<endl;
    }
    return 0;
}

bool isPrime21(int num){
    //set the first divisable number to n-1, subtract until it goes to 2
    for (int i=(num-1);i>1;i--){
        if(num%i==0){
            return false;
        }
    }
    return true;
}

