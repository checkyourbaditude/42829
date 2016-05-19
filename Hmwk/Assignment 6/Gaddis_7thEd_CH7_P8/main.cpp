/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: chris
 *
 * Created on May 18, 2016, 9:47 AM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //variables
    const int SIZE=7;
    long int empID[SIZE]={5658845, 4520125, 7895122, 8777541, 8451277, 1302850, 7580489};
    int hours[SIZE];
    int payRate[SIZE];
    int wages[SIZE];
    
    cout<<"Lets calculate employee wages!"<<endl;
    
    //for loop to get the wages
    for(int i=0;i<SIZE;i++){
        cout<<"Employee ID #: "<<empID[i]<<endl;
        cout<<"Enter number of hours: "<<endl;
        cin>>hours[i];
        cout<<"Enter the pay rate per hour"<<endl;
        cin>>payRate[i];
        wages[i]=hours[i]*payRate[i];
    }
    
    cout<<"Wages for Employees"<<endl;
    
    for(int j=0;j<SIZE;j++){
        cout<<empID[j]<<": "<<wages[j]<<endl;;
    }
    return 0;
}

