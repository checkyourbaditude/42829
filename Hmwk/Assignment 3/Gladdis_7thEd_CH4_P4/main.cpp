/* 
 * File:   main.cpp
 * Author: Chris Schaefer
 * Gladdis Chapter 4 Problem 4
 * Compare the area of two rectangles and determine which is bigger
 * Created on January 22, 2016, 9:20 AM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //l is length, w is width, a is for area
    short l1, w1, l2, w2, a1, a2;
    
    //inputs, ask user for values to compare
    cout<<"Enter the length and width of two rectangles, we will calculate"<<endl;
    cout<<"which rectangle has more area"<<endl;
    cout<<"Enter the length of the first rectangle"<<endl;
    cin>>l1;
    cout<<"Enter the width of the first rectangle"<<endl;
    cin>>w1;
    cout<<"Enter the length of the second rectangle"<<endl;
    cin>>l2;
    cout<<"Enter the width of the second rectangle"<<endl;
    cin>>w2;
    
    //Calculations
    a1=l1*w1;
    a2=l2*w2;
    cout<<"Area of rectangle 1 is "<<a1<<endl;
    cout<<"Area of rectangle 2 is "<<a2<<endl;
    
    //logic, which is bigger?
    if (a1>a2){
        cout<<"Area of Rectangle 1 is larger";
    }
    else{
        cout<<"Area of Rectangle 2 is larger";
    }
    return 0;
}

