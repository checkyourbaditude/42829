/* 
 * File:   main.cpp
 * Author: Chris Schaefer
 * Gladdis Chapter 4 Problem 1
 * Ask user for two numbers and output the max number
 * Created on January 22, 2016, 9:00 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

int main(int argc, char** argv) {
    //Declare Variables
    int a,b,max;
    
    //get input
    cout<<"Input two numbers"<<endl;
    cin>>a;
    cin>>b;
    
    //logic
    (a>b)?(max=a):(max=b);
    
    //Output
    cout<<max<<" is bigger";
    return 0;
}

