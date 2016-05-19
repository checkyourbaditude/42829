/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: chris
 *
 * Created on May 9, 2016, 9:34 AM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

//declare the function
void countNum2s(int a[], int size);

int main(int argc, char** argv) {
    //variables
    int userInput[5], howBig=5;
    unsigned short nTwos=0;
    
    //call the function
    countNum2s(userInput, howBig);
    
    return 0;
}

//function contents
void countNum2s(int a[], int size){
    
    //local variables
    unsigned short nTwos=0;
    
    for(int i=0;i<=(size-1);i++){
        //get user input, and check to see if anything is a 2
        cout<<"Enter a score"<<endl;
        cin>>a[i];
        if(a[i]==2) nTwos++;
    }
    cout<<"The number of 2s: "<<nTwos<<endl;
}

