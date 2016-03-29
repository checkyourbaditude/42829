/* 
 * File:   main.cpp
 * Author: Chris Schaefer
 * Gladdis Chapter 4 Problem 22
 * Calculate the rate that the phone company charges for long distance calls
 * Validate the time to make sure it is in hh.mm format
 * Created on January 22, 2016, 3:07 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(int argc, char** argv) {
    //Declare Variables
    //int mins;
    float mins,tot,stime,chrg1=0.12f,chrg2=0.55f,chrg3=0.35f;
    
    //Input
    cout<<"I see you are going to make a long distance call"<<endl;
    cout<<"Here are the rates for such a call:"<<endl;
    cout<<"starting time of call    Rate per Minute"<<endl;
    cout<<"0-6:59                   0.12 cents"<<endl;
    cout<<"7-19:00                  0.55 cents"<<endl;
    cout<<"19:01-23:59              0.35 cents"<<endl;
    cout<<"Enter the start time of the call in HH.MM format"<<endl;
    cin>>stime;
    cout<<"How long was the call in minutes"<<endl;
    cin>>mins;
    
    //Validate data, make sure the number is no greater than 0.59
    //and no larger than 23.59, using modf to split number
    //logic
    if(stime<07.00){
        tot=mins*chrg1;
        cout<<"You Have been charged "<<chrg1<<" per minute for your "<<endl;
        cout<<" call of "<<mins<<" minutes for a total charge of "<<tot<<endl;
        cout<<" dollars"<<endl;
    }
    else if (stime>=07.00&&stime<=19.00){
        tot=mins*chrg2;
        cout<<"You Have been charged "<<chrg2<<" per minute for your "<<endl;
        cout<<" call of "<<mins<<" minutes for a total charge of "<<tot<<endl;
        cout<<" dollars"<<endl;
    }
    else{
        tot=mins*chrg3;
        cout<<"You Have been charged "<<chrg3<<" per minute for your "<<endl;
        cout<<"call of "<<mins<<"minutes for a total charge of "<<tot<<endl;
        cout<<" dollars"<<endl;
    }
    return 0;
}

