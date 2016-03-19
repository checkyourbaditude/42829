/* 
 * File:   main.cpp
 * Author: Chris Schaefer
 * Chapter 3 Problem 3 Gladdis 7th Edition
 * Write program to average five test scores, with 1 decimal point percision
 * Created on January 13, 2016, 11:45 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //declare Variables
    short one, two, three, four, five;
    float average;
    
    //Inputs
    cout<<"Please enter five test scores, within the range of 0-100: "<<endl;
    cin>>one>>two>>three>>four>>five;
    
    //Calculation
    average=(one + two + three + four +five)/5.0;
    //cout<<setprecision(3)<<average;
    
    //Output
    cout<<
        "This is the average of the test scores you entered: "<<average<<endl;
    return 0;
}

