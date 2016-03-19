/* 
 * File:   main.cpp
 * Author: Chris Schaefer
 * Chapter 3 Problem 8 Gladdis 7th Edition
 * Ask the user for the cost if they had to completely replace their home
 * then give them a return of 80% of that cost as a recommendation for
 * how much insurance they should buy
 * Created on January 14, 2016, 12:36 AM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //declare variables
    float hvalue,R, IR=8e-2;
    
    //input
    cout<<
        "What is would the total cost to completely replace your home?"<<endl;
    cin>>hvalue;
    
    //calculations
    R=IR*hvalue;
    
    //output
    cout<<"You should get insurance for "<<R<<" $$ about 80% of the value of your home";
    return 0;
}

