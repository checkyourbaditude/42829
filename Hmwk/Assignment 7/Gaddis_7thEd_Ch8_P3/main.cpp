/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: chris
 * Same program as P2 but with binary search
 * Created on May 23, 2016, 9:46 AM
 */
#include <cstdlib>
#include <iostream>
using namespace std;
//array sizes
const int SIZE=18;

//function to search
bool biSearchArr(int [], int, int);
void mrkSort(int a[], int n);

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
    if(biSearchArr(lotVal, SIZE, choice)){
        cout<<"Winner!"<<endl;
    }
    else{
        cout<<"Not a Winner!"<<endl;
    }
    return 0;
}

bool biSearchArr(int a[], int S, int Num){
    int first=0;
    int last=S-1;
    int middle;
    bool found=false;
    
    mrkSort(a,S);
    
    while(first<=last&&!found){
        middle=(first+last)/2;
        if(a[middle]==Num){
            found=true;
            return found;
        }
        else if(a[middle]>Num){
            last=middle-1;
        }
        else{
            first=middle+1;
        }
    }
    
    return found;
}

void mrkSort(int a[], int n){
    //nested for loop 
    for(int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if(a[i]<a[j]){
                a[i]=a[i]^a[j];
                a[j]=a[i]^a[j];
                a[i]=a[i]^a[j];
            }
        }
    }
}
