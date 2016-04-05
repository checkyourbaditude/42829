/* 
 * File:   main.cpp
 * Author: Chris Schaefer
 * Gladdis Chapter 5 Problem 3
 * Write a program that will show how much the ocean will rise over the next
 * 25 years
 * Created on January 25, 2016, 11:02 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

int main(int argc, char** argv) {
    //Variables
    int years=25;
    float  rate;
    
    //loop
    cout<<"Year     Running total"<<endl;
    for(int i=0;i<=years;i++){
        rate+=1.5f;
        cout<<i<<"      "<<rate<<endl;
    }
    return 0;
}

