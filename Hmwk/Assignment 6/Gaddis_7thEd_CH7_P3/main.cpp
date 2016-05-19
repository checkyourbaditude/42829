/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: chris
 *
 * Created on May 18, 2016, 9:24 AM
 */

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv) {
    //variables
    const int SIZE=5;
    string salsas[]={"mild", "medium", "sweet", "hot", "zesty"};
    int jars[SIZE];
    int nLar=-1, nSmall=10000;
    string large=" ", small=" ";
    
    //use for loop to get the variables
    cout<<"Lets see which of the following salsas had the most jars sold!"<<endl;
    for(int i=0;i<SIZE;i++){
        cout<<"How many jars of "<<salsas[i]<<" were sold?"<<endl;
        cin>>jars[i];
        while(jars[i]<0){
            cout<<"Incorrect Input! No Negative Numbers"<<endl;
            cout<<"Try again..."<<endl;
            cin>>jars[i];
        }
        
        //determine the largest and smallest
        if(jars[i]>nLar){
            large=salsas[i];
            nLar=jars[i];
        }
        if(jars[i]<nSmall){
            small=salsas[i];
            nSmall=jars[i];
        }
    }
    
    //print the data
    for(int j=0;j<SIZE;j++){
        cout<<salsas[j]<<":     "<<jars[j]<<endl;
    }
    cout<<"The best seller: "<<large<<endl;
    cout<<"The worst seller: "<<small<<endl;
    return 0;
}