/* 
 * File:   main.cpp
 * Author: Chris Schaefer
 * Chapter 3 Problem 7 Gladdis 7th Edition
 * A bag has 40 cookies, with a total serving size of 10 per bag
 * Each bag has 300 calories
 * Ask user how many cookies they ate, and calculate the amount of calories
 * consumed
 * Created on January 14, 2016, 12:02 AM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //40 cookies in a package
    //10 servings per package
    //300 calories per serving
    //CpC is Calorie per cookie
    //CpS is Calories per Serving
    //TC is total calories
    //UN is number of cookies entered by user
    float CpC,UN,CpS=10.0/40.0;
    int TC;
    
    //Input
    cout<<"Enter the number of cookies that you have eaten:\n";
    cin>>UN;
    
    //calculate calories per cookie, and amount user has consumed
    CpC=CpS*300;
    TC=CpC*UN;
    
    //Output
    cout<<"You have consumed "<<TC<<" calories"<<endl;
        
    return 0;
}

