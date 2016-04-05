/* 
 * File:   main.cpp
 * Author: Chris Schaefer
 * Gladdis Chapter 5 Problem 9
 * Calculate how much a person would earn over a period of time if his of her
 * salary is one penny the first day and two pennies the second day, and
 * continues to double each day
 * Created on January 24, 2016, 7:37 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char** argv) {
    //Declare Variables
    int ndays;
    float np=0.01;
    
    //Inputs
    cout<<"How many days do you want to work?"<<endl;
    cin>>ndays;
    
    //loop
    for(int i=1;i<=ndays;i++){
        //set the precision, put the operation after the output
        //this allowsthe day 1 to be at 0.01 cents
        
        cout<<fixed<<setprecision(2);
        cout<<"Day "<<i<<": $"<<np<<endl;
        np*=2;
    }
    return 0;
}

