/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Christopher
 *
 * Created on April 23, 2016, 5:38 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

//functional prototypes
void getJudgeData(float &score);
void calcScore(float score1, float score2, float score3, float score4, float score5);
float findLowest(float l1, float l2, float l3, float l4, float l5);
float findHighest(float h1, float h2, float h3, float h4, float h5);

int main(int argc, char** argv) {
    //variables
    float jScore1=0.00f, jScore2=0.00f, jScore3=0.00f, jScore4=0.00f, jScore5=0.00f;
    
    //Get each of the judges scores, and store them into their variables
    getJudgeData(jScore1);
    cout<<"The First judge's score is: "<<jScore1<<endl;
    
    getJudgeData(jScore2);
    cout<<"The Second judge's score is: "<<jScore2<<endl;
    
    getJudgeData(jScore3);
    cout<<"The Third judge's score is: "<<jScore3<<endl;
    
    getJudgeData(jScore4);
    cout<<"The Fourth judge's score is: "<<jScore4<<endl;
    
    getJudgeData(jScore5);
    cout<<"The Fifth judge's score is: "<<jScore5<<endl;
    
    calcScore(jScore1, jScore2, jScore3, jScore4, jScore5);
    
    return 0;
}

//ask the judges for their score
void getJudgeData(float &score){
    //first try 
    cout<<"Please enter a score Judge!";
    cin>>score;
    
    //if the user did not follow the rules
    while(score<0 || score>10){
        
        //get valid user input
        cout<<"The score must be between 0 and 10"<<endl;
        cout<<"Please enter a valid score!"<<endl;
        cin>>score;
    }
}

//calculating the score, requires that we call the findLowest and findHighest 
//functions and remove the highest and lowest scores
void calcScore(float score1, float score2, float score3, float score4, float score5){
    
    //Put the highest and lowest scores into these variables
    float hRemove=0.00f, lRemove=0.00f, avg=0.00f;

    //find the highest and lowest
    hRemove=findHighest(score1, score2, score3, score4, score5);
    lRemove=findLowest(score1, score2, score3, score4, score5);
    
    //calculate the average, subtracting the largest and highest scores
    avg=((score1+score2+score3+score4+score5)-hRemove-lRemove)/(static_cast<float>(3));
    cout<<"The total score is: "<<setprecision(2)<<fixed<<avg<<endl;
}

//find the lowest score
float findLowest(float l1, float l2, float l3, float l4, float l5){
    
    //assign the lowest value to the first
    float lowest=l1;
    
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
    cout<<"The lowest score is: "<<setprecision(2)<<fixed<<lowest<<endl;
    
    //return the lowest value
    return lowest;
}

//find the highest scores
float findHighest(float h1, float h2, float h3, float h4, float h5){
    //assign the lowest value to the first
    float highest=h1;
    
    //compare to the second value
    if(highest<h2){
        highest=h2;
    }
    
    //compare to the third value
    if(highest<h3){
        highest=h3;
    }
    
    //compare to the fourth value
    if(highest<h4){
        highest=h4;
    }
    
    //compare to the fifth value
    if(highest<h5){
        highest=h5;
    }
    
    //output the lowest value
    cout<<"The highest score is: "<<setprecision(2)<<fixed<<highest<<endl;
    
    //return the lowest value
    return highest;
}

