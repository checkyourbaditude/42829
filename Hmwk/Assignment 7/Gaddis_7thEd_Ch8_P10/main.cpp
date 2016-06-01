/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: chris
 *
 * Created on May 30, 2016, 3:04 PM
 */

#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;
//functional prototypes
void fillArr(int [], int);
void printArr(int [], int);

//sorting functions
void bubSort(int [], int);
void selSort(int [], int);

int main(int argc, char** argv) {
    //set random number seed
    srand(static_cast<int>(time(NULL)));
    
    //declare variables
    const int SIZE=8;
    int Num1[SIZE];
    int Num2[SIZE];
    
    //fill the arrays
    fillArr(Num1,SIZE);
    fillArr(Num2,SIZE);
    
    //call sorting functions
    bubSort(Num1, SIZE);
    selSort(Num2,SIZE);
    
    return 0;
}
void fillArr(int a[], int b){
    for(int i=0;i<=b;i++){
        a[i]=rand()%10000+1;
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
                cout<<"Array after "<<counter<<" exchanges with Bubble Sort: "<<endl;
                printArr(a,b);
            }
        }
    }while(swap);
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
                cout<<"Array after "<<counter<<" exchanges with Selection Sort: "<<endl;
                printArr(a,b);
            }
        }
        a[minIndex]=a[startScan];
        a[startScan]=minValue;
    }
}

