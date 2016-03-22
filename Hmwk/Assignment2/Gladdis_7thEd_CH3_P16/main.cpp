/* 
 * File:   main.cpp
 * Author: Chris Schaefer
 * Chapter 3 Problem 16 Gladdis 7th Edition
 * Calculate the Principal of the savings account using the equasion 
 * Created on January 14, 2016, 1:43 AM
 */

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;


int main(int argc, char** argv) {
    //Declare Variables
    float IR, P, IT, Total, NCP;
    
    //input
    cout<<"Enter the Interest Rate you have(as a decimal, not %)"<<endl;
    cin>>IR;
    cout<<"Enter the Number of times it is compounded in a year"<<endl;
    cin>>NCP;
    cout<<"Enter the Principal in the account"<<endl;
    cin>>P;
    
    //calculations
    Total=P*pow(1+(IR/NCP),NCP);
    IT=Total-P;
    std::cout <<std::fixed;
    std::cout <<std::setprecision(2);
    
    //output
    cout<<"\nInterest Rate:           "<<IR<<endl;
    cout<<"Times Compounded:        "<<NCP<<endl;
    cout<<"Principal:               "<<P<<endl;
    cout<<"Interest:                "<<IT<<endl;
    cout<<"Amount In Savings:       "<<Total<<endl;
    return 0;
}

