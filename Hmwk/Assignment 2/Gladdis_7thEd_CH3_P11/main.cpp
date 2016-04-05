/* 
 * File:   main.cpp
 * Author: Chris Schaefer
 * Chapter 3 Problem 8 Gladdis 7th Edition
 * Write a program to convert US dollar amounts to Japanese yen and to euros
 * must have global constants 
 * Created on January 14, 2016, 1:15 AM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

//Global Constants as of 1/14
const float YEN_PER_DOLLAR = 117.72f;
const float EUROS_PER_DOLLAR = 0.92f;

int main(int argc, char** argv) {
    //declare variables
    float cYen, cEuro;
    int Ndlr;
    
    
    //input
    cout<<"How many dollars would you like to convert to Yen and Euros\n$";
    cin>>Ndlr;
    
    //calculations
    cYen=Ndlr*YEN_PER_DOLLAR;
    cEuro=Ndlr*EUROS_PER_DOLLAR;
    std::cout <<std::fixed;
    std::cout <<std::setprecision(2);
    
    //output
    cout<<cEuro<<" Euros\n"<<cYen<<" Yen"<<endl;
    return 0;
}

