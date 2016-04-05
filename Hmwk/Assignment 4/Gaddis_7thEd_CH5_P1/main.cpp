/* 
 * File:   main.cpp
 * Author: Christopher Schaefer
 * Gladdis Chapter 5 Problem 1
 * Ask user for a number and sum all of the numbers up to that number
 * Created on January 23, 2016, 4:27 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

int main(int argc, char** argv) {
    //Declare Variables
    int uinput,rtot,i=0;
    
    //Input
    cout<<"This program will add up every number up to the number you enter"<<endl;
    cin>>uinput;
    
    //Make sure the number is entered correctly
    while(uinput<=0){
        cout<<"Please enter a number greater than zero"<<endl;
        cin>>uinput;
    }
    //loop and logic portion
    //Sums the numbers all up until uinput+1
    do{
        rtot=i+1;
        i++;
    }while(i!=(uinput+1));
    cout<<"This is the total: "<<rtot<<endl;
    return 0;
}

