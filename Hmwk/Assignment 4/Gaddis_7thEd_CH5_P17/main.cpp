/* 
 * File:   main.cpp
 * Author: Chris Schaefer
 * Gladdis Chapter 5 Problem 17
 * Sales Bar Chart
 * write a program that asks the user to enter today's sales for five stores
 * and output a bar chart for each 100=*
 * Created on January 25, 2016, 6:07 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

int main(int argc, char** argv) {
    //Declare Variables
    int sales1,sales2,sales3,sales4,sales5,nstar1,nstar2,nstar3,nstar4,nstar5;
    
    //inputs
    cout<<"What is the total sales volume for today at store 1?"<<endl;
    cin>>sales1;
    nstar1=sales1/100;
    cout<<"What is the total sales volume for today at store 2?"<<endl;
    cin>>sales2;
    nstar2=sales2/100;
    cout<<"What is the total sales volume for today at store 3?"<<endl;
    cin>>sales3;
    nstar3=sales3/100;
    cout<<"What is the total sales volume for today at store 4?"<<endl;
    cin>>sales4;
    nstar4=sales4/100;
    cout<<"What is the total sales volume for today at store 5?"<<endl;
    cin>>sales5;
    nstar5=sales5/100;
    
    //outputs, using loops to determine the amount of stars
    cout<<"\nStore 1:";
    while(nstar1!=0){
        cout<<"*";
        nstar1-=1;
    }
    cout<<"\nStore 2:";
    while(nstar2!=0){
        cout<<"*";
        nstar2-=1;
    }
    cout<<"\nStore 3:";
    while(nstar3!=0){
        cout<<"*";
        nstar3-=1;
    }
    cout<<"\nStore 4:";
    while(nstar4!=0){
        cout<<"*";
        nstar4-=1;
    }
    cout<<"\nStore 5:";
    while(nstar5!=0){
        cout<<"*";
        nstar5-=1;
    }
    return 0;
}

