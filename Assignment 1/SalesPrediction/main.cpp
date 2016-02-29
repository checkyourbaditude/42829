/* 
 * File:   main.cpp
 * Author: Chris Schaefer
 * Chapter 2 Problem 2 Gladdis 7th Edition
 * Created on January 9, 2016, 11:30 AM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //the percentage that the east coast sells relative to the rest of the
    //company
    float saleper=6.2e-1;
    
    //total sales volume
    int totsale=4600000;
    
    //Calculations
    int toteast=saleper*totsale;
    
    //Output
    cout<<"The east coast sales division has "<<saleper;
    cout<<" of the total sales of the entire company";
    cout<<"\nThe total sales of the company is casted to be "<<totsale;
    cout<<" next year the east coast division's forecast is "<<toteast;
    return 0;
}

