/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Christopher
 *
 * Created on May 14, 2016, 2:40 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;


int main(int argc, char** argv) {
    //variables
    const int SIZE=10;
    int getVal[SIZE];
    int Large, Small;
    
    //get the user to fill the array
    for (int i=0;i<=(SIZE-1);i++){
        cout<<"Enter the "<<i+1<<" element in the Array"<<endl;
        cin>>getVal[i];
    }
    //initialize the smallest and largest values
    Large=getVal[0];
    Small=getVal[0];
    
    for(int j=0;j<SIZE;j++){
        if(getVal[j]>Large)Large=getVal[j];
        if(getVal[j]<Small)Small=getVal[j];
    }
    cout<<"This is the smallest number:"<<Small<<endl;
    cout<<"This is the largest number:"<<Large<<endl;
    return 0;
}

