/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: chris
 *
 * Created on May 23, 2016, 10:10 AM
 */

#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;
//constant for array size
const int NUM_NAMES=20;

//functions
void showArry(string [], int);
void selectSort(string [], int);

int main(int argc, char** argv) {
    //variables
    string names[NUM_NAMES]={
        "Collins, Bill", "Smith, Bart", "Allen, Jim", "Griffin, Jim",
        "Stamey, Marty", "Rose, Geri", "Taylor, Terri", "Johnson, Jill",
        "Allison, Jeff", "Looney, Joe", "Wolfe, Bill", "James, Jean",
        "Weaver, Jim", "Pore, Bob", "Butherfod, Greg", "Javens, Renee",
        "Harrison, Rose", "Setzer, Cathy", "Pike, Gordon", "Holland, Beth"};
    
    cout<<"Unstorted String Array"<<endl;
    showArry(names, NUM_NAMES);
    cout<<endl;
    
    //sort the string array
    selectSort(names, NUM_NAMES);
    
    cout<<"Sorted String Array"<<endl;
    showArry(names, NUM_NAMES);
    cout<<endl;
    return 0;
}

void showArry(string arr[], int S){
    for(int i=0;i<S;i++){
        cout<<"Name #"<<i+1<<": "<<arr[i]<<endl;
    }
}
    
void selectSort(string str[], int S){
    int startScan, minIndex, minValue;
    string strMinIndex, strMinValue;
    
    for(startScan=0;startScan<(S-1);startScan++){
        minIndex=startScan;
        minValue=startScan;
        strMinIndex=str[startScan];
        strMinValue=str[startScan];
        for(int index=startScan+1;index<S;index++){
            if(str[index]<=strMinValue){
                minValue=index;
                minIndex=index;
                strMinValue=str[index];
                strMinIndex=str[index];
            }
        }
        str[minIndex]=str[startScan];
        str[startScan]=strMinValue;
    }
}

