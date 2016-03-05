/* 
 * File:   main.cpp
 * Author: Chris Schaefer
 * Chapter 2 Problem 10 Gladdis 7th Edition
 * Calcuate the MPG of a car
 * Created on January 9, 2016, 2:03 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //number of gallons the car holds, and number of miles driven
    short gal=12, miles=350;
            
    //Calculations
    short MPG=miles/gal;
    
    //Output
    cout<<"Your Car has a "<<gal<<" gallon tank\n";
    cout<<"You have driven "<<miles<<" miles before your need to stop and refuel\n";
    cout<<"Your MPG is "<<MPG<<" miles per gallon";
    return 0;
}

