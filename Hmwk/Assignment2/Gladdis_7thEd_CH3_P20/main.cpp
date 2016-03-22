/* 
 * File:   main.cpp
 * Author: Chris Schaefer
 * Chapter 3 Problem 20 Gladdis 7th Edition
 * Ask for an Angle entered in Radians, display the sin, cos, and tan
 * fix the percision to 4 decimal places
 * Created on January 15, 2016, 7:38 PM
 */

#include <cstdlib>
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(int argc, char** argv) {
    //Declare Variables
    float x;
    
    //input
    cout<<"Please put in a radian value that you would like to find the ";
    cout<<"sin, cos, and tan of!"<<endl;
    cin>>x;
    
    //calculations and output
    cout<<fixed<<setprecision(4);
    cout<<"sin: "<<sin(x)<<endl;
    cout<<"cos: "<<cos(x)<<endl;
    cout<<"tan: "<<tan(x)<<endl;
    return 0;
}

