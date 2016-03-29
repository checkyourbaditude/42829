/* 
 * File:   main.cpp
 * Author: Chris Schaefer
 * Gladdis Chapter 4 Problem 8
 * Create a Change counting game, the goal being to get one dollar even
 * Output the amount that the user was off
 * Created on January 22, 2016, 10:15 AM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //Declare Variables
    unsigned short q,d,n,p,total,remain;

    //inputs
    cout<<"What is the number of Quarters"<<endl;
    cin>>q;
    cout<<"What is the number of Dimes"<<endl;
    cin>>d;
    cout<<"What is the number of Nickels"<<endl;
    cin>>n;
    cout<<"What is the number of Pennies"<<endl;
    cin>>p;

    //calculations
    total=(q*25)+(d*10)+(n*5)+p;

    //logic
    if(total==100)
    {
        cout<<"Your total is exactly "<<total<<endl;
    }
    else if(total<100)
    {
        remain=100-total;
        cout<<"Your Total was "<<total<<" and you were off by "<<remain<< "cents"<<endl;
    }
    else{
        remain=total-100;
        cout<<"Your Total was "<<total<<" and you were off by "<<remain<<" cents"<<endl;
    }
    return 0;
}

