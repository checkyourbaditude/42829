/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Christopher Schaefer
 * Write a function name celsius that accepts a fahrenheit temperature as an 
 * arguement. It should return the temp converted to celsius. Use a loop to 
 * display 20 values.
 * Created on April 23, 2016, 4:02 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

//functional prototypes
float celsius(float conv);

int main(int argc, char** argv) {
    //variables
    float fTemp=0.00f, cTemp=0.00f;
    
    //output
    cout<<"Lets convert a range of Fahrenheit temps to Celsius!"<<endl;
    cout<<"What is the first temp you would like like to see?"<<endl;
    cin>>fTemp;
    
    cout<<"Here are the converted temperatures:"<<endl;

    //loop for multiple conversions 
    for(int i=0;i<=20;i++){
        //call the function and assign return to cTemp
        cTemp = celsius(fTemp+i);
        
        //output the results
        cout<<setprecision(2)<<fixed<<fTemp+i;
        cout<<" degree Fahrenheit is ";
        cout<<setprecision(2)<<fixed<<cTemp<<" degree celsius."<<endl;
    }
    return 0;
}

//conversion function
float celsius(float conv){
    return  ((5.00/9.00)*(conv-32)); 
}
