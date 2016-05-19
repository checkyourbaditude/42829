/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: chris
 *
 * Created on May 18, 2016, 10:08 AM
 */

#include <cstdlib>
#include <iostream>
#include <ctime> 
using namespace std;

//variables
const int rSIZE=3;
const int cSIZE=3;

//functions
int getTotal(int [rSIZE][cSIZE], int, int);
int getAverage(int [rSIZE][cSIZE] , int, int);
int getRowTotal(int [rSIZE][cSIZE], int);
int getColumnTotal(int [rSIZE][cSIZE], int);
int getHighestInRow(int [rSIZE][cSIZE], int);
int getLowestInRow(int [rSIZE][cSIZE], int);

int main(int argc, char** argv) {
    //Set the random number seed for variability
    srand(static_cast<unsigned int>(time(0)));
    
    //variables
    const int rSIZE=3;
    const int cSIZE=3;
    int Array[rSIZE][cSIZE];
    int rChoice=0,cChoice=0, total=0,average=0,rowTotal=0,colTotal=0, getRowH=0, getRowL=1000;
    
    //fill the array
    for(int i=0;i<rSIZE;i++){
        for(int j=0;j<cSIZE;j++){
            Array[i][j]=rand()%90+10;
            cout<<Array[i][j]<<" ";
        }
        cout<<endl;
    }
    
    //get the user input on the row they would like to do operations on
    cout<<"What row would you like to do operations on?"<<endl;
    cin>>rChoice;
    while(rChoice<rSIZE||rChoice>rSIZE){
        cout<<"Invalid Input!"<<endl;
        cout<<"What row would you like to do operations on?"<<endl;
        cin>>rChoice;
    }
    
    //get the column they would like to do operations on
    cout<<"What column would you like to do operations on?"<<endl;
    cin>>cChoice;
    while(cChoice<cSIZE||cChoice>cSIZE){
        cout<<"Invalid Input!"<<endl;
        cout<<"What row would you like to do operations on?"<<endl;
        cin>>cChoice;
    }
    
    //make sure it translate to an actually array index
    rChoice-=1;
    cChoice-=1;
    
    //calling functions
    total=getTotal(Array, rSIZE, cSIZE);
    average=getAverage(Array, rSIZE, cSIZE);
    rowTotal=getRowTotal(Array, rChoice);
    colTotal=getColumnTotal(Array, cChoice);
    getRowH=getHighestInRow(Array, rChoice);
    getRowL=getLowestInRow(Array, rChoice);
            
    //output the functions 
    cout<<"Total: "<<total<<endl;
    cout<<"Average: "<<average<<endl;
    cout<<"Row "<<rChoice+1<<" Total: "<<rowTotal<<endl;
    cout<<"Column "<<cChoice+1<<" Total: "<<colTotal<<endl;
    cout<<"Row "<<rChoice+1<<" Highest: "<<getRowH<<endl;
    cout<<"Row "<<rChoice+1<<" Lowest: "<<getRowL<<endl;
    
    /*
    ColTotal=0, getRowH=0, getRowL=1000;*/
    return 0;
}

int getTotal(int a[rSIZE][cSIZE], int r, int c){
    int tot=0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            tot+=a[i][j];
        }
    }
    return tot;
}
int getAverage(int a[rSIZE][cSIZE], int r, int c){
    int avg=0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            avg+=a[i][j];
        }
    }
    avg=avg/(r*c);
    return avg;
}

int getRowTotal(int a[rSIZE][cSIZE], int c){
    int rtot=0;
    for(int i=0;i<cSIZE;i++){
        rtot+=a[c][i];
    }
    return rtot;
}

int getColumnTotal(int a[rSIZE][cSIZE], int c){
    int ctot=0;
    for(int i=0;i<rSIZE;i++){
        ctot+=a[i][c];
    }
    return ctot;
}
int getHighestInRow(int a[rSIZE][cSIZE], int h){
    int large=a[h][0];
    for(int i=0;i<rSIZE;i++){
        if(a[h][i]>large)large=a[h][i];
    }
    return large;
}

int getLowestInRow(int a[rSIZE][cSIZE], int h){
    int small=a[h][0];
    for(int i=0;i<rSIZE;i++){
        if(a[h][i]<small)small=a[h][i];
    }
    return small;
}

