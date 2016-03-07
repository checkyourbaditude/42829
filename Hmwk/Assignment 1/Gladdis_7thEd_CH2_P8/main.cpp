/* 
 * File:   main.cpp
 * Author: Chris Schaefer
 * Chapter 2 Problem 8 Gladdis 7th Edition
 * Calculate the total of the five items that are being bought by customer
 * then calculate the sales tax
 * Created on January 9, 2016, 1:51 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //delcare iteams bought and costs of items
    float a=12.95, b=24.95, c=6.95, d=14.95, e=3.95;
    
    //tax
    float tax=6e-2;
    
    //total without tax
    float total1=a+b+c+d+e;
    
    //total with tax, with percision
    float total2=(total1*tax)+total1;
    
    //Output
    cout<<a<<"\n"<<b<<"\n"<<c<<"\n"<<d<<"\n"<<e<<"\n";
    cout<<"tax is "<<tax<<"\n";
    cout<<"The total with tax is ";    
    cout<<setprecision(4)<<total2;
    return 0;
}

