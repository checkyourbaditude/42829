/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: chris
 *
 * Created on May 30, 2016, 1:42 PM
 */

#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;

//functional prototypes
void fillArr(int [], int);
void printArr(int [], int);

//function to search
bool biSearchArr(int [], int, int);
void mrkSort(int a[], int n);
bool linSearchArr(int [], int, int);

int main(int argc, char** argv) {
    //declare array
    const int SIZE=20;
    int choice;
    int Numbers[SIZE];
    
    //fill the array
    fillArr(Numbers,SIZE);
    
    //print the array
    printArr(Numbers, SIZE);
    
    //get user input
    cout<<"Pick a number to find in the array"<<endl;
    cin>>choice;
    while(choice<0||choice>=21){
        cout<<"Try again!"<<endl;
        cin>>choice;
    }
    
    //use the binary search
    if(biSearchArr(Numbers,SIZE,choice)){
        cout<<"Number was found using Binary search."<<endl;
    }
    else{
        cout<<"Number was not found using Binary search."<<endl;
    }
    
    //use the linear search
    if(linSearchArr(Numbers,SIZE,choice)){
        cout<<"Number was found using Linear search."<<endl;
    }
    else{
        cout<<"Number was not found using Linear search."<<endl;
    }
    return 0;
}
void fillArr(int a[], int b){
    for(int i=0;i<=b;i++){
        a[i]=i+1;
    }
}
void printArr(int a[], int b){
    for(int i=0;i<=b;i++){
        cout<<a[i]<<endl;
    }
}
bool biSearchArr(int a[], int S, int Num){
    int first=0;
    int last=S-1;
    int middle;
    int count=0;
    bool found=false;
    
    mrkSort(a,S);
    
    while(first<=last&&!found){
        middle=(first+last)/2;
        if(a[middle]==Num){
            found=true;
            cout<<"Binary Search used "<<count<<"comparisons!"<<endl;
            return found;
        }
        else if(a[middle]>Num){
            last=middle-1;
        }
        else{
            first=middle+1;
        }
        count++;
    }
    cout<<"Binary Search used "<<count<<" comparisons!"<<endl;
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
bool linSearchArr(int a[], int S, int Num){
    bool isFound=false;
    int count=0;
    
    for(int i=0;i<=S;i++){
        if(a[i]==Num){
            isFound==true;
            cout<<"Linear Search used "<<count<<" comparisons!"<<endl;
            return isFound;
        }
        count++;
    }
    cout<<"Linear Search used "<<count<<"comparisons!"<<endl;
    return isFound;
}

