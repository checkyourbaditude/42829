/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: chris
 *
 * Created on May 15, 2016, 5:05 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;



int main(int argc, char** argv) {
    //Declare the arrays that will hold the information
    const int N_MONKS=3, N_DAYS=7,N_OUTPUTS=3;
    int lbsFood[N_MONKS][N_DAYS];
    int OUTPUTS[N_OUTPUTS]={0, 10000, 0};
    
    cout<<"Lets calculate the number of lbs of food that the Monkies are eating!"<<endl;
    cout<<"Monkey 1: George\nMonkey 2: Marvin\nMonkey 3: Al"<<endl;
    
    for(int i=0;i<N_MONKS;i++){
        
        //re-initialize j so we can fill the array properly
        int j=0;
        
        for(;j<N_DAYS;j++){
            
            //make user know which monkey's data is being entered
            switch(i){
                
                case 0:{
                    cout<<"Enter the number of lbs of food George ate on day "<<j+1<<endl;
                    cin>>lbsFood[i][j];

                    //data validation
                    while(lbsFood[i][j]<0){
                        cout<<"Invalid Input.... Try again!";
                        cin>>lbsFood[i][j];
                    }
                    break;
                }
                case 1:{
                    cout<<"Enter the number of lbs of food Marvin ate on day "<<j+1<<endl;
                    cin>>lbsFood[i][j];

                    //data validation
                    while(lbsFood[i][j]<0){
                        cout<<"Invalid Input.... Try again!";
                        cin>>lbsFood[i][j];
                    }
                    break;
                }
                case 2:{
                    cout<<"Enter the number of lbs of food Al ate on day "<<j+1<<endl;
                    cin>>lbsFood[i][j];

                    //data validation
                    while(lbsFood[i][j]<0){
                        cout<<"Invalid Input.... Try again!";
                        cin>>lbsFood[i][j];
                    }
                    break;
                }
                default:{
                    cout<<"Something went wrong..."<<endl;
                    break;
                }
            }
            
            //check to see if the inputs qualify as smallest or largest respectively
            OUTPUTS[0]+=lbsFood[i][j];
            if(lbsFood[i][j]<OUTPUTS[1])OUTPUTS[2]=lbsFood[i][j];
            if(lbsFood[i][j]>OUTPUTS[2])OUTPUTS[2]=lbsFood[i][j];
        }
    }
    
    //outputs
    cout<<"The average amount of food consumed was: "<<OUTPUTS[0]/21<<endl;
    cout<<"The smallest amount of food consumed was: "<<OUTPUTS[1]<<endl;
    cout<<"The largest amount of food consumed was: "<<OUTPUTS[2]<<endl;
    return 0;
}

