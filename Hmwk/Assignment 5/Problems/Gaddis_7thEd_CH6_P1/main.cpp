/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Christopher Schaefer
 * Write a program that asks the user to enter an item's wholesale cost
 * and its markup percentage. Display the retail price.
 * Do not accept negative values
 *
 * Created on April 23, 2016, 3:21 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

//Function Prototypes
float calculateRetail(float num, float perc);

int main(int argc, char** argv) {
    //variables
    float rCost=0.00f, mPerc=0.00f, wCost=0.00f;
    
    //inputs
    cout<<"Lets calculate the retail cost of a good."<<endl;
    cout<<"What is the wholesale cost of the good?"<<endl;
    cin>>rCost;
    
    cout<<"What is the markup? (This should be in %)"<<endl;
    cin>>mPerc;
    
    //Convert to a decimal
    mPerc/=100.00f;
    
    //send to function
    wCost = calculateRetail(rCost, mPerc);
    
    //output result
    cout<<"This good costs "<<setprecision(2)<<fixed<<rCost<<" wholesale.";
    cout<<" With a "<<setprecision(2)<<fixed<<mPerc*100<<"% markup it costs:"<<endl;
    cout<<setprecision(2)<<fixed<<wCost;
    return 0;
}

//variables
float calculateRetail(float num, float perc){
    return (num+(num*perc));
}

