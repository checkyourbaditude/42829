/* 
 * File:   main.cpp
 * Author: Chris Schaefer
 * Gladdis Chapter 4 Problem 12
 * Calculate the charges for checks being processed for commercial accounts
 * $0.10 for fewer than 20 checks
 * $0.08 for 20-39 checks
 * $0.06 for 40-59 checks
 * $0.04 for 60+
 * 10$ per month flat fee
 * if balance below 400$ extra 15$
 * Created on January 22, 2016, 10:40 AM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char** argv) {
    //variables, c1 is charge one
    int balance, stdchrg=10.00, q, totchrg;
    float c1=.10, c2=.08, c3=.06, c4=0.04;
    
    //Inputs
    cout<<"What is the amount of your initial bank account?"<<endl;
    cout<<"If your balance falls below 400$ then its an extra 15$"<<endl;
    cin>>balance;
    cout<<"A 10$ flat fee is charged for checks plus the following:"<<endl;
    cout<<"$0.10 for fewer than 20 checks\n$0.08 for 20-39 checks\n"
          "$0.06 for 40-59 checks\n$0.04 for 60+"<<endl;
    cout<<"How many checks are you depositing with us?"<<endl;
    cin>>q;
    
    //Logic/Calculations
    //must use ternary operator for extra 15$ charge
    if(q>=20 && q<=39){
        totchrg=stdchrg+q*c2;
        (balance-totchrg)<=400?(totchrg+=25):(totchrg+=0);
        cout<<"Your total charges are "<<totchrg<<endl;
    }
    else if(q>=40 && q<=59){
        totchrg=stdchrg+q*c3;
        (balance-totchrg)<=400?(totchrg+=25):(totchrg+=0);
        cout<<"Your total charges are "<<totchrg<<endl;
    }
    else if(q>=100){
        totchrg=stdchrg+q*c4;
        (balance-totchrg)<=400?(totchrg+=25):(totchrg+=0);
        cout<<"Your total charges are "<<totchrg<<endl;
    }
    else{
        totchrg=stdchrg+q*c1;
        (balance-totchrg)<=400?(totchrg+=25):(totchrg+=0);
        cout<<"Your total charges are "<<totchrg<<endl;
    }
    return 0;
}

