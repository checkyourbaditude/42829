/* 
 * File:   main.cpp
 * Author: Christopher Schaefer
 * Gladdis Chapter 5 Problem 5
 * Create a loop to calculate the amount of increase in fees at a country club
 * 2500 are the current fees, they will go up by 0.04 for six years
 * Created on January 23, 2016, 4:39 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

int main(int argc, char** argv) {
    //Delcare Variables
    int years=6;
    float mfeeup=0.04f, mfee=2500;
    
    //Loop in order to output the values of the increase per year
    for(int i=0;i<=years;i++){
        mfee=(mfeeup*mfee)+mfee;
        cout<<"In year "<<i<<" The increase will be to "<<mfee<<" dollars"<<endl;
    }
    return 0;
}

