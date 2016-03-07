/* 
 * File:   main.cpp
 * Author: Chris Schaefer
 * Chapter 2 Problem 6 Gladdis 7th Edition
 * Calculate the annual pay for an employee
 * Created on January 9, 2016, 12:41 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //Pay per period and number of periods in a year
    short payamnt=1700, periods=26;
    
    //Calculation
    unsigned short yrspay=payamnt*periods;
    
    //results
    cout<<"Employee gets paid "<<payamnt<< " per pay period";
    cout<<"\nThe number of pay periods in a year is "<<periods;
    cout<<"\nEmployee makes "<<yrspay<<" in a year";
    return 0;
}

