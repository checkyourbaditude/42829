/* 
 * File:   main.cpp
 * Author: Christopher Schaefer
 * 
 * Calculate the monthly payment 
 * Loan Amount = 10000
 * Interest rate 12%/yr
 * 36 monthly payment periods
 * formula = r *(1+r)^n/((1+r)^2-1) * l
 * 
 * This could be written better by entering it:
 * temp=pow(1+r,n)
 * p = (r*temp*L)/(temp-1)
 * Created on March 7, 2016, 9:41 AM
 */

#include <cstdlib>
#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //variables
    int loanAmt, n;
    float rate, ans,lnChck;
    
    //inputs
    cout<<"Enter the principal on the loan"<<endl;
    cin>>loanAmt;
    
    cout<<"How many payment peroids?"<<endl;
    cin>>n;
    
    cout<<"What interest rate? (enter in 0.xx please)"<<endl;
    cin>>rate;
    
    //calculating the monthly payment
    
    ans=((rate/12*pow(1+(rate/12),n))/(pow(1+(rate/12),n)-1))*loanAmt;
    
    //calculating the loan principal based off the monthly payments
    
    lnChck = (ans*12*(pow(1+(rate/12),n)-1))/(rate*pow(1+(rate/12),n));
    
    //outputs
    
    cout<<"Principal:          "<<loanAmt<<"$"<<endl;
    cout<<"# Payment Peroids:  "<<n<<endl;
    cout<<"Interest Rate:      "<<rate<<"%"<<endl;
    cout<<"Monthly Payment:    "<<setprecision(5)<<ans<<"$"<<endl;
    cout<<"Loan Check:         "<<lnChck<<"$"<<endl;
    return 0;
}

