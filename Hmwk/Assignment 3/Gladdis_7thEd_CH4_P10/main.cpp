/* 
 * File:   main.cpp
 * Author: Chris Schaefer
 * Gladdis Chapter 4 Problem 10
 * Calculate the Discounts given when buying a certian range of quantities
 * 10-19 is 20%
 * 20-49 is 30%
 * 50-99 is 40%
 * 100+ is 50%
 * Created on January 22, 2016, 10:21 AM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //deglcare Variables
    //q is quantity
    //d1 is discount 1, d2 is discount 2 etc.
    short q,cost=99,totp, totd;
    float d1=0.20f, d2=0.30f, d3=0.40f, d4=0.50f;
    
    //input
    cout<<"What is the amount of software that you would like to buy?"<<endl;
    cout<<"Each package costs 99$, and our discounts are as follows:"<<endl;
    cout<<"10-19 is 20% \n20-49 is 30%\n50-99 is 40%\n100+ is 50%"<<endl;
    cin>>q;
    
    //logic/calculations
    if(q>=10 && q<=19){
        totd=q*cost*d1;
        totp=q*cost-totd;
        cout<<"Your discount is "<<totd<<endl;
        cout<<"Your total purchase is "<<totp<<endl;
    }
    else if(q>=20 && q<=49){
        totd=q*cost*d2;
        totp=q*cost-totd;
        cout<<"Your discount is "<<totd<<endl;
        cout<<"Your total purchase is "<<totp<<endl;
    }
    else if(q>=50 && q<=99){
        totd=q*cost*d3;
        totp=q*cost-totd;
        cout<<"Your discount is "<<totd<<endl;
        cout<<"Your total purchase is "<<totp<<endl;
    }
    else if(q>=100){
        totd=q*cost*d4;
        totp=q*cost-totd;
        cout<<"Your discount is "<<totd<<endl;
        cout<<"Your total purchase is "<<totp<<endl;
    }
    else{
        totp=cost*q;
        cout<<"Your discount is "<<totd<<endl;
        cout<<"Your total purchase is "<<totp<<endl;
    }
    return 0;
}

