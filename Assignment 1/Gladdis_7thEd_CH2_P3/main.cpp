/* 
 * File:   main.cpp
 * Author: Chris Schaefer
 * Chapter 2 Problem 3 Gladdis 7th Edition
 * calculate the sales tax on the purchase
 * Created on January 9, 2016, 11:58 AM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //The amount the item costs
    short pur=52;
    
    //Tax rates
    float tstate=4e-2, tcount=2e-2;
    
    //Calculations for total cost
    float ttax=tstate+tcount, taxpaid=ttax*pur, total=taxpaid+pur;
    
    //Output
    cout<<"You have bought a "<<pur<<" dollar item";
    cout<<"\nstate sales tax is "<<tstate;
    cout<<"\ncounty sales tax is "<<tcount;
    cout<<"\nthe total tax on your purchase is "<<taxpaid;
    cout<<"\nYour total is "<<total;
    return 0;
}

