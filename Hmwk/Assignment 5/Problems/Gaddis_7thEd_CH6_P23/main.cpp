/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Christopher
 *
 * Created on April 24, 2016, 10:41 AM
 */

#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

//functional prototypes
unsigned short computer();
unsigned short player();
bool winner(unsigned short computer, unsigned int player);
int main(int argc, char** argv) {
    //variables
    //1=rock,2=paper,3=scissors
    unsigned short cChoice=1,uChoice=1;
    bool tie=true;
    
    //enter the loop, if not tie then break the loop
    while(tie==true){
        //get the computers choice
        cChoice=computer();
        uChoice=player();

        //determine winner
        tie=winner(cChoice,uChoice);
    }
    return 0;
}

//generate random number to assign player value
unsigned short computer(){
    //setting random number seed for AI
    srand(static_cast<unsigned int>(time(0)));
    return (rand()%3+1);
}
unsigned short player(){
    
    //make variables to store data and return
    unsigned short choice=0;
    
    //get the user input
    cout<<"Lets play rock paper scissors!"<<endl;
    cout<<"Enter (1)=rock, (2)=paper, and (3)=scissors"<<endl;
    cin>>choice;
    
    //make sure the number is between 1 and 3
    while(choice>=4||choice<=0){
        cout<<"Not a valid input!"<<endl;
        cout<<"Try again: Enter (1)=rock, (2)=paper, and (3)=scissors"<<endl;
        cin>>choice;
    }
    
    //confirm the choice for user's benefit
    switch(choice){
        case 1:
            cout<<"You have chosen Rock"<<endl;
            break;
        case 2:
            cout<<"You have chosen Paper"<<endl;
            break;
        case 3:
            cout<<"You have chosen Paper"<<endl;
            break;
    }
    
    //return value to use in winner function
    return choice;
}
bool winner(unsigned short computer, unsigned int player){
    
    //output computer's choice
    switch(computer){
        case 1:
            cout<<"The computer has chosen Rock"<<endl;
            break;
        case 2:
            cout<<"The computer has chosen Paper"<<endl;
            break;
        case 3:
            cout<<"The computer has chosen Scissors"<<endl;
            break;
    }
    
    //player wins
    if (computer==3&&player==1){
        cout<<"Rock smashes the Scissors!"<<endl;
        cout<<"You win!"<<endl;
        
        //return false to end the loop
        return false;
    }
    
    else if(computer==2&&player==3){
        cout<<"Scissors cuts Paper!"<<endl;
        cout<<"You win!"<<endl;
        
        //return false to end the loop
        return false;
    }
    else if(computer==1&&player==2){
        cout<<"Paper covers Rock!"<<endl;
        cout<<"You win!"<<endl;
        
        //return false to end the loop
        return false;
    }
    
    //computer wins
    else if(computer==3&&player==1){
        cout<<"Rock smashes the Scissors!"<<endl;
        cout<<"Computer wins!"<<endl;
        
        //return false to end the loop
        return false;
    }
    else if(computer==3&&player==2){
        cout<<"Scissors cuts Paper!"<<endl;
        cout<<"Computer wins!"<<endl;
        
        //return false to end the loop
        return false;
    }
    else if (computer==2&&player==1){
        cout<<"Paper covers Rock!"<<endl;
        cout<<"Computer wins!"<<endl;
        
        //return false to end the loop
        return false;
    }
    
    //for a tie
    else{
        cout<<"It is a tie!"<<endl;
        cout<<"Play again!"<<endl;
        
        //output true to continue the loop
        return true;
    }
}

