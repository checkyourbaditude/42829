/* 
 * File:   main.cpp
 * Author: Chris Schaefer
 * Gladdis Chapter 4 Problem 21
 * Write a program with a menu to calculate the area of a circle, rectangle
 * and triangle. 
 * Created on January 22, 2016, 12:26 PM
 */

#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char** argv) {
    //Declare Variables
    short choice, r, l, w, b, h, areac, arear, areat;
    float pi=atan(1)*4; 
    
    //Menu and input
    cout<<"1. Calculate the Area of a Circle"<<endl;
    cout<<"2. Calculate the Area of a Rectangle"<<endl;
    cout<<"3. Calculate the Area of a Triangle"<<endl;
    cout<<"4. End"<<endl;
    cin>>choice;
    
    //switch statement, logic
    switch(choice){
        //calculate the area of the circle, with user input
        case 1:
            cout<<"What is the radius of the Circle"<<endl;
            cin>>r;
            areac=pi*r*r;
            cout<<"The area of the circle with radius "<<r<<" is "<<areac<<endl;
            break;
        //calculate the area of the rectangle, with user input
        case 2:
            cout<<"What is the length of the rectangle?"<<endl;
            cin>>l;
            cout<<"What is the width of the rectangle?"<<endl;
            cin>>w;
            arear=l*w;
            cout<<"The area of the rectangle with length "<<l<<" and width "
                  <<w<<" is "<<arear;
            break;
        //calculate the area of the circle, with user input
        case 3:
            cout<<"What is the base length of the Triangle?"<<endl;
            cin>>b;
            cout<<"What is the height of the triangle?"<<endl;
            cin>>h;
            areat=.5*b*h;
            cout<<"The area of the triangle with height "<<h<<"and base" <<b<<
                  " is "<<areat<<endl;
            break;
        case 4:
            cout<<"Exit";            
    }
    return 0;
}

