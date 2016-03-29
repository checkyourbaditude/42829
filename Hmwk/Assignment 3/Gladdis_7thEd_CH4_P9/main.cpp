/* 
 * File:   main.cpp
 * Author: Chris Schaefer
 * Gladdis Chapter 4 Problem 9
 * Created on January 22, 2016, 9:11 PM
 */

#include <iostream>
#include <stdlib.h>
using namespace std;

int main(int argc, char** argv) {
    //Declare Variables
    int sans,r1,r2,ans=r1+r2;
    do{
        r1=rand()%50;
        r2=rand()%50;
        cout<<"Student lets do some math!"<<endl;
        cout<<"What is "<<r1<<" + "<<r2<<" = ?"<<endl;
        cin>>sans;
    }
    while(sans==ans);
    //logic
    cout<<"Correct!"<<endl;
    return 0;
}

