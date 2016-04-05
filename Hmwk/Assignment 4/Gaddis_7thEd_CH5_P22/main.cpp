/* 
 * File:   main.cpp
 * Author: Chris Schaefer
 * Gladdis Chapter 5 Problem 22
 *
 * Created on January 25, 2016, 10:49 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //Declare Variables
    int num,tnum;
    
    //Input
    cout<<"Enter the length of the square you would like to make"<<endl;
    cin>>num;
    
    //limit for the for loop
    tnum=num*num;
    
    //loop
    cout<<"This is your output!:\n"<<endl;
    for(int i=1;i<=tnum;i++){
        cout<<"x";
        if(i%num==0){
            cout<<"\n";
        }
    }
    return 0;
}

