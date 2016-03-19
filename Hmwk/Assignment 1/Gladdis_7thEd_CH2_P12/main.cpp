/* 
 * File:   main.cpp
 * Author: Chris Schaefer
 * Chapter 2 Problem 12 Gladdis 7th Edition
 * Calculate the amount of land in x number of acres
 * Created on January 9, 2016, 2:53 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //1 acre is equal to 43560 square ft
    int x=43560, y=389767;
    
    //the amount we want to convert to acres
    int con=y/x;
    
    //Output
    cout<<con<<" acres";
    return 0;
}

