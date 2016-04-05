/* 
 * File:   main.cpp
 * Author: Chris Schaefer
 * Gladdis Chapter 5 Problem 19
 * Write a program that asks the user for a budget and their expenses and tells
 * them if they are over or under budget
 * Created on January 25, 2016, 9:58 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

int main(int argc, char** argv) {
    //Declare Variables
    int budget, exp;
    
    //Inputs
    cout<<"What is your budget for the month?"<<endl;
    cin>>budget;
    
    //loop
    do{
        cout<<"Press 0 when you are finished with the program!";
        cout<<"Expense: ";
        cin>>exp;
        exp+=exp;
        
    }while(exp!=0);
    
    //Calcualte totals
    cout<<"Your budget was:         $"<<budget<<endl;
    budget-=exp;
    cout<<"Your total expenses are: $"<<exp<<endl;
    return 0;
}

