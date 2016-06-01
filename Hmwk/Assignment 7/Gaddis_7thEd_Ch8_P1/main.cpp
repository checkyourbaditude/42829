/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: chris
 * //creating a linear search
 *
 * Created on May 23, 2016, 9:28 AM
 */

#include <cstdlib>
#include <iostream>
using namespace std;
//array sizes
const int SIZE=18;

//function to search
bool searchArr(int [], int, int);

int main(int argc, char** argv) {
    //variables
    int ChrgVal[SIZE]={
        5658845,4520125,7895122,8777541,8451277,1302850,8080152,4562555,5552012,
        5050552,7825877,1250255,1005231,6545231,3852085,7576651,7881200,4581002,
    };
    int choice=0;
    
    /*
    //print the array
    for(int i=0;i<=SIZE;i++){
        cout<<"Charge card #"<<i+1<<": "<<ChrgVal[i]<<endl;
    }
    */
    
    cout<<"Enter a card number so we can see if it matches the list"<<endl;
    cin>>choice;
    
    //use linear search to see if the entered data matches
    if(searchArr(ChrgVal, SIZE, choice)){
        cout<<"This is a valid number!"<<endl;
    }
    else{
        cout<<"Number is not valid!"<<endl;
    }
    return 0;
}

bool searchArr(int a[], int S, int Num){
    for(int i=0;i<=S;i++){
        if(a[i]==Num){
            return true;
        }
    }
    return false;
}

