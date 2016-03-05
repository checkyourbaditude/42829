/* 
 * File:   main.cpp
 * Author: Chris Schaefer
 * Chapter 2 Problem 10 Gladdis 7th Edition
 * calculate the stock commission
 * Created on January 9, 2016, 3:01 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //number of shares bought
    short shares=600;
    
    //price per share
    float price=21.77;
    
    //percent she must give to the broker
    float bpay=2e-2;
    
    //calculations
    float amtpyd=shares*price;
    float amtb=amtpyd*bpay;
    float totpyd=amtpyd+amtb;
    
    //Output of Results
    cout<<"Chris Bought "<<shares<<" shares of stock at "<<price<<" per share\n";
    cout<<"The broker gets "<<bpay<<" from the purchase price\n";
    cout<<"Chris payed "<<amtpyd<<" for the stock plus "<<amtb<< " to the broker\n";
    cout<<"Chris payed "<<totpyd<<" in total";
    
    return 0;
}

