/* 
 * File:   main.cpp
 * Author: Chris Schaefer
 * Chapter 2 Problem 4 Gladdis 7th Edition
 * Calculate the total of a resturant bill with tax and tip
 * Created on January 9, 2016, 12:18 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //Cost of meal, tax, and tip 
    float cost=44.50, tax=6.75e-2, tip=15e-2;
 
    //total amount of tip
    float tottip=cost*tip;
    
    //total amount of tax
    float tottax=cost*tax;
    
    //total amount of bill with tax and tip
    float total=cost+tottip+tottax;
    
    //cute dialog with totals, limit percision of output, because its dollars
    cout<<"Thanks for eating with us this afternoon!";
    cout<<"\nYour bill is "<<cost<<" dollars ";
    cout<<"\nTax is "<<tax<<" percent for a total tax of "<<tottax;
    cout<<"\nTip is "<<tip<<" percent for a total tip of "<<tottip;
    cout<<"\nYour total with including tax and tip is ";
    cout<<setprecision(4)<<total;
    return 0;
}

