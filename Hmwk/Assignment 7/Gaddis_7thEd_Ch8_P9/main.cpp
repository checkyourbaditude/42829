/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: chris
 *
 * Created on May 30, 2016, 2:40 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

//functional prototypes
void fillArr(int [], int);
void printArr(int [], int);

//sorting functions
void bubSort(int [], int);
void selSort(int [], int);

int main(int argc, char** argv) {
    //declare arrays
    const int SIZE=20;
    int choice;
    int NumbersB[SIZE];
    int NumbersS[SIZE];
    
    //fill the arrays
    fillArr(NumbersB,SIZE);
    fillArr(NumbersS,SIZE);
    
    //print the arrays
    printArr(NumbersB, SIZE);
    printArr(NumbersS, SIZE);
    
    //call sorting functions
    bubSort(NumbersB,SIZE);
    selSort(NumbersS,SIZE);
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
void bubSort(int a[], int b){
    bool swap;
    int temp;
    int counter=0;
    
    do{
        swap=false;
        for(int count=0; count<(b);count++){
            if(a[count]>a[count+1]){
                temp=a[count];
                a[count]=a[count+1];
                a[count+1]=temp;
                swap=true;
                counter++;
            }
        }
    }while(swap);
    
    cout<<"Bubble Sort used "<<counter<<" exchanges."<<endl;
}

void selSort(int a[], int b){
    int startScan, minIndex, minValue;
    int counter=0;
    
    for(startScan=0;startScan<(b-1);startScan++){
        minIndex=startScan;
        minValue=a[startScan];
        for(int index=startScan+1;index<b;index++){
            if(a[index]<minValue){
                minValue=a[index];
                minIndex=index;
                counter++;
            }
        }
        a[minIndex]=a[startScan];
        a[startScan]=minValue;
    }
    cout<<"Selection Sort used "<<counter<<" exchanges"<<endl;
}

