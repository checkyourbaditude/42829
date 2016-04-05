/* 
 * File:   main.cpp
 * Author: Chris Schaefer
 * Chapter 3 Problem 1 Gladdis 7th Edition
 * Write a program that calculates a car's MPG with user inputs
 * Created on January 13, 2016, 11:35 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

/*
 * None
 */
int main(int argc, char** argv) {
    //This is the variables
    short gals, miles, MPG;
    
    //Ask user the questions
    cout<<"How many gallons of gas can your car hold?"<<endl;
    cin>>gals;
    cout<<"How many miles can you drive on a full tank?"<<endl;
    cin>>miles;
    
    //Calculation
    MPG=miles/gals;
    
    //Output
    cout<<"Here is your MPG(Miles per Gallon): "<<MPG<<endl;
    return 0;
}

