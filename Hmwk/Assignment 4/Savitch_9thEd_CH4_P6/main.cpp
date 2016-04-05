/* 
 * File:   main.cpp
 * Author: Christopher Schaefer
 * You have a vending machine that deep fries twinkies. Write a program to
 * simulate the vending machine, prompt user for coins: dollar, quarter, dime, or
 * nickel. Prompt the user continually until they need change, and output
 * "enjoy your twinkie".
 * Created on April 4, 2016, 7:45 AM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;
float total(char c){
    switch(c){
        case 'o':{
            return 1.00;
        }
        case 'q':{
            return 0.25;
        }
        case 'd':{
            return 0.10;
        }
        case 'n':{
            return 0.05;
        }
        default:{
            return 0.00;
        }
    }
}
int main(int argc, char** argv) {
    //variables
    char coin;
    float sum=0.00,cOut=0.00, cost=3.50;
    
    //outline the rules of the interaction with user
    cout<<"You approach a vending machine that outputs deep fried twinkies!"<<endl;
    cout<<"The cost is 3.50$."<<endl;
    cout<<"You only have the following coins: Dollar (1.00$), Quarter (0.25$)"<<endl;
    cout<<"Dime (0.10$), and Nickel (0.05$)"<<endl;
    
    //continually prompt until the user reaches 3.50$
    while(sum<cost){
        
        //input
        cout<<"Enter o for dollar, q for quarter, d for dime, and n for nickel"<<endl;
        cin>>coin;
        
        //call function to determine the coin type
        cOut=total(coin);
        
        //if its not valid, it will output 0
        if(cOut == 0){
            cout<<"Not valid Input!"<<endl;
        }
        
        //if its valid the process continues
        else{
            sum=sum+cOut;
            cout<<"Your total so far is:"<<setprecision(2)<<fixed<<sum<<"$"<<endl;
        }
    }
    cout<<"You got your twinkie!"<<endl;
    cout<<"You entered:"<<sum<<" and you are due "<<setprecision(2)<<fixed<<sum-cost<<" $ in change"<<endl;
    
    return 0;
}

