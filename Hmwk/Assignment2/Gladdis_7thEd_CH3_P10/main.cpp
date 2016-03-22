/* 
 * File:   main.cpp
 * Author: Chris Schaefer
 * Chapter 3 Problem 10 Gladdis 7th Edition
 * Convert a Celsius temp to Fahrenheit
 * Created on January 14, 2016, 12:43 AM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //Declare Variables
    short F,C;
    
    //input
    cout<<"Enter a Celsius temp that you want to see be Fahrenheit!"<<endl;
    cin>>C;

    //calculations
    F=(9.0/5.0)*C+32;
    
    //output
    cout<<"It is "<<F<<" degrees fahrenheit"<<endl;
    return 0;
}

