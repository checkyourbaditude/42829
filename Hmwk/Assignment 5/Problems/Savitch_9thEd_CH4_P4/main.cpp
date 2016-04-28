/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on April 27, 2016, 9:20 AM
 */

#include <cstdlib>
#include <iostream>
using namespace std;
//inflation function 
float calcInflation(float past, float current);

int main(int argc, char** argv) {
    //variables
    float inflation=0.00f,cPrice=0, pPrice=0;
    
    //get the current price 1 year ago
    cout<<"We are going to calculate the inflation of a good in this game"<<endl;
    cout<<"What was the price of the good 1 year ago?"<<endl;
    cin>>pPrice;
    
    //get the current price of the good
    cout<<"What was the price of the good today?"<<endl;
    cin>>cPrice;
    
    //call the function
    inflation=calcInflation(pPrice,cPrice);
    
    cout<<"Inflation on this good is "<<inflation<<"%"<<endl;
    return 0;
}

//figure out the inflation rate
float calcInflation(float past, float current){
    return (current-past)*100;
}

