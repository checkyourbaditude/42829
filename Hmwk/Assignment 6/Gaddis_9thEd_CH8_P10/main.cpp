/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: chris
 * In class working on 5/10/2016
 * Created on May 11, 2016, 8:16 AM
 */

#include <cstdlib>
#include <fstream>
#include <iostream>
using namespace std;

void prntAry(char [], int, int);
int readFile(char [], char []);
int score(char [], int, char [], int);

int main(int argc, char** argv) {
    //variables
    const int SIZE=100;
    char answers[SIZE];
    char user[SIZE];
    
    //open the file
    char fnAns[]="answerKey.dat";
    int nAnswers=readFile(fnAns, answers);
    char fnUser[]="UserAns.dat";
    int nUser=readFile(fnUser, user);
    
    //print the array
    cout<<"The Answer Key"<<endl;
    prntAry(answers, nAnswers, 10);
    
    cout<<"The User Answers"<<endl;
    prntAry(user, nUser, 10);
    
    //calculate the results
    int results=score(answers, nAnswers, user, nUser);
    
    //output the scores
    cout<<"Score="<<results<<" right -> "<<1.0f*results/nAnswers*100<<"%"<<endl;
    return 0;
}

void prntAry(char a[], int nIna, int perLine){
    //loop and out the array
    for(int i=0;i<nIna;i++){
        cout<<a[i];
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

int readFile(char fn[], char dat[]){
    //variables
    ifstream ansKey;
    
    //open the file
    ansKey.open(fn);
    
    //read from the file
    int n=0;
    while(ansKey>>dat[n]){dat[n++];}
    
    
    //close the file
    ansKey.close();
    
    //return the size
    return n;
}
int score(char answers[], int nAnswers, char user[], int nUser){
    int results=0;
    for(int ques=0;ques<nAnswers&&ques<nUser;ques++){
        if(answers[ques]==user[ques])results++;
    }
    return results;
}


