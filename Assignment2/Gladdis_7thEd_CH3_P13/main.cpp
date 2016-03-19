/* 
 * File:   main.cpp
 * Author: Chris Schaefer
 * Chapter 3 Problem 8 Gladdis 7th Edition
 * Calculate the Property Tax from user input, they collect taxes on 60% of the 
 * actual value of the property. The tax is 64 cents per 100$ in value.
 * Created on January 14, 2016, 1:33 AM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char** argv) {
    //Declare Variables
    float Pvalue, taxtot;
    
    //input
    cout<<"What is your property value, we need to take your taxes!"<<endl;
    cin>>Pvalue;
    
    //calculations
    taxtot=((0.6*Pvalue)/100)*0.64;
    std::cout <<std::fixed;
    std::cout <<std::setprecision(2);
    
    //output
    cout<<"You owe: "<<taxtot<<" dollars in taxes"<<endl;
    return 0;
}

