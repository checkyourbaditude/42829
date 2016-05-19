/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: chris
 *
 * Created on May 15, 2016, 6:28 PM
 */

#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

void fill(unsigned int [], int NUMB);
void compare(unsigned int [], unsigned int []);

int main(int argc, char** argv) {
    //set random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //variables
    const int SIZE=5;
    unsigned int lotArr[SIZE];
    unsigned int userArr[SIZE];
    
    //fill the arrays
    fill(lotArr, SIZE);
    fill(userArr, SIZE);
    
    //print the arrays
    cout<<"The lottery numbers are:     ";
    for(int j=0;j<SIZE;j++){
        cout<<lotArr[j];
    }
    cout<<endl;
    
    cout<<"The user numbers are:        ";
    for(int j=0;j<SIZE;j++){
        cout<<userArr[j];
    }
    cout<<endl;
    
    //compare the arrays to see if there is a winner
    compare(lotArr,userArr);
    
    return 0;
}

//filling each array with a function
void fill(unsigned int a[], int NUMB){
    for(int i=0;i<NUMB;i++){
        a[i]=rand()%10;
    }
}

//compare the two arrays to see what digits they have in common
void compare(unsigned int l[], unsigned int u[]){
    int counter=0;
    
    for(int k=0;k<5;k++){
        if(l[k]==u[k]){
            cout<<"The number "<<k+1<<" is matching!"<<endl;
            counter++;
        }
    }
    
    if(counter==5){
        cout<<"YOU WON THE LOTTERY!"<<endl;
    }
    
}

