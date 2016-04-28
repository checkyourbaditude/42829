/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Christopher
 *
 * Created on April 23, 2016, 4:18 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

//functional prototypes
void getscore(int &score);
void calcAverage(int score1, int score2, int score3, int score4, int score5);
int findLowest(int l1, int l2, int l3, int l4, int l5);

int main(int argc, char** argv) {
    //variables
    int s1=0,s2=0,s3=0,s4=0,s5=0,average=0;
    
    cout<<"We are going to take in five scores, calculate the average";
    cout<<" of the four highest scores. Scores must be between 0 and 100."<<endl;
    
    getscore(s1);
    cout<<"The first score is "<<s1<<endl;;
    
    getscore(s2);
    cout<<"The second score is "<<s2<<endl;
    
    getscore(s3);
    cout<<"The third score is "<<s3<<endl;
    
    getscore(s4);
    cout<<"the fourth score is "<<s4<<endl;
    
    getscore(s5);
    cout<<"the fifth score is "<<s5<<endl;
    
    calcAverage(s1,s2,s3,s4,s5);
    return 0;
}

//get the scores
void getscore(int &score){
    //first try 
    cout<<"Please enter a score!";
    cin>>score;
    
    //if the user did not follow the rules
    while(score<=-1 || score>=101){
        
        //get valid user input
        cout<<"The score must be between 0 and 100"<<endl;
        cout<<"Please enter a valid score!"<<endl;
        cin>>score;
    }
}

//calculating the average
void calcAverage(int score1, int score2, int score3, int score4, int score5){
    
    //declare local variables
    int drop=0,sum=0,avg=0;
    
    //figure out what value is the lowest, then put into variable drop
    drop=findLowest(score1, score2, score3, score4, score5);
    
    cout<<drop<<endl;
    //sum all of the inputs, then subtract the smallest with variable drop
    sum=(score1+score2+score3+score4+score5)-drop;
    
    //calculate the average
    avg=sum/4;
    
    //output the average
    cout<<"The average of the five scores is: "<<avg<<endl;
}

//finding the lowest number of the bunch
int findLowest(int l1, int l2, int l3, int l4, int l5){

    //assign the lowest value to the first
    int lowest=l1;
    
    //compare to the second value
    if(lowest>l2){
        lowest=l2;
    }
    
    //compare to the third value
    if(lowest>l3){
        lowest=l3;
    }
    
    //compare to the fourth value
    if(lowest>l4){
        lowest=l4;
    }
    
    //compare to the fifth value
    if(lowest>l5){
        lowest=l5;
    }
    
    //output the lowest value
    cout<<"The smallest score is "<<lowest<<endl;
    
    //return the lowest value
    return lowest;
}

