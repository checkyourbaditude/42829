/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: chris
 *
 * Created on May 23, 2016, 9:40 AM
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
    int lotVal[SIZE]={
        13579,26791,26792,33445,55555,62483,77777,79422,85647,93121,
    };
    int choice=0;
    
    /*
    //print the array
    for(int i=0;i<=SIZE;i++){
        cout<<"Charge card #"<<i+1<<": "<<ChrgVal[i]<<endl;
    }
    */
    
    cout<<"Enter the winning lottery number, and we will check to see if your are a winner!"<<endl;
    cin>>choice;
    
    //use linear search to see if the entered data matches
    if(searchArr(lotVal, SIZE, choice)){
        cout<<"Winner!"<<endl;
    }
    else{
        cout<<"Not a Winner!"<<endl;
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

