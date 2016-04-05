/* 
 * File:   main.cpp
 * Author: Chris Schaefer
 * Gladdis Chapter 5 Problem 11
 * Write a program to predict the growth of organisms
 * Created on January 25, 2016, 9:48 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

int main(int argc, char** argv) {
    //Declare Variables
    int spop,epop,days;
    float grate;
    
    //Input
    cout<<"What is the starting population?"<<endl;
    cin>>spop;
    cout<<"What is the growth rate?(by percentage)"<<endl;
    cin>>grate;
    grate/=100.00;
    cout<<"How many days will the population grow?"<<endl;
    cin>>days;
    
    //loops and output
    for(int i=0;i<=days;i++){
        cout<<"Day "<<i<<": "<<spop<<"\n";
        spop=(spop*grate)+spop;
    }
    return 0;
}

