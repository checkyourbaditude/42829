/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: chris
 *
 * Created on May 28, 2016, 4:36 PM
 */

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <fstream>

using namespace std;

//constants for Arrays
const unsigned short hSIZE=5;
const unsigned short nSCORES=13;
const unsigned short sSIZE=2;

//functional prototypes
void getnTurn(int &);

//for hand validation
unsigned short roll();
int number_of_dice(int);
void mrkSort(unsigned short [], unsigned short);
bool valnKeep(unsigned short []);
void prntHand(unsigned short [], unsigned short);

//giving the user their options
void viewOptions(bool [], unsigned short [], unsigned short);

//for grade validation
bool isNotUsed(bool [], int);
bool isLowerSection(unsigned short [], int, unsigned short);
unsigned short totUpper(unsigned short [], int);
unsigned short Sum(unsigned short []);
bool is3Kind(unsigned short []);
bool is4Kind(unsigned short []);
bool isFull(unsigned short []);
bool isSS(unsigned short [], unsigned short);
bool isLS(unsigned short []);
bool isY(unsigned short []);
void prntScrCrd(unsigned short [nSCORES][sSIZE]);

//output card to file
void fileoutScrCrd(unsigned short [nSCORES][sSIZE]);

//print boolean array
void prntArr(bool [], unsigned short);

int main(int argc, char** argv) {
    //Set the random number seed for variability
    srand(static_cast<unsigned int>(time(NULL)));
    
    //boolean array to not allow users to score multiple times
    bool sChk[nSCORES]={false,false,false,false,
                        false,false,false,false,
                        false,false,false,false,false};
    
    //two demensional array to hold the scores
    unsigned short pSCard[nSCORES][sSIZE]={
                                            {1,0},
                                            {2,0},
                                            {3,0},
                                            {4,0},
                                            {5,0},
                                            {6,0},
                                            {7,0},
                                            {8,0},
                                            {9,0},
                                            {10,0},
                                            {11,0},
                                            {12,0},
                                            {13,0},};
    unsigned short pHand[hSIZE];
    int nTurn=0;
    
    //get the nTurn variable
    getnTurn(nTurn);
    
    //greeting
    cout<<"Lets Play Yahtzee!"<<endl;
    cout<<"Rules:"<<endl;
    cout<<"-You must enter the  sequential code corresponding to the dice #s"<<endl;
    cout<<" you would like to re-roll.\n-Enter a zero if you would like to ";
    cout<<" roll all of the dice again."<<endl;
    cout<<"-Sequences with zeros are not allowed."<<endl;
    cout<<"     For Example: 325 is valid, however 2035 is not.\n"<<endl;
    cout<<"Here is the first roll!(enter anything and press enter)"<<endl;
    cin.get();
    cin.ignore();
    
    //start the game
    for(int turn=1;turn<=nTurn;turn++){
        //tell user what turn they are on
        cout<<"\nTurn #"<<turn<<"\n"<<endl;
        
        //re-itialize pHand with zeros
        for(int allZs=0;allZs<hSIZE;allZs++){
            pHand[allZs]=0;
        }
    
        //first roll, no user input needed
        for(int i=0;i<hSIZE;i++){
            pHand[i]=roll();
            cout<<"Dice #"<<i+1<<": "<<pHand[i]<<endl;
        }
 
        //begin validation loop for user choices of which dice to re-roll
        for(int rollCnt=2;rollCnt<4;rollCnt++){
            //boolean to let user out of loop
            bool is1to5=false;
            unsigned short nKeepAr[hSIZE]={0,0,0,0,0};

            do{
                //local variables
                unsigned short choice1=0;
                unsigned short choice2=0;
                unsigned short choice3=0;
                unsigned short choice4=0;
                unsigned short choice5=0;
                int nDice=0;
                int nKeep=0;
                //make sure nKeepAr has all zeros
                for(int h=0;h<hSIZE;h++){
                    nKeepAr[h]=0;
                }
                //user instructions
                cout<<"Enter the numbers of the dice you would like to re-roll!"<<endl;
                cout<<"If you would like to keep your entire roll, just press zero (0)"<<endl;
                cout<<"All digits must be between 1 and 5"<<endl;
                cin>>nKeep;
                //cout<<"Number chosen:"<<nKeep<<endl;

                //if the user chooses to keep everything
                if(nKeep==0){
                    rollCnt=3;
                    break;
                }
                else{

                    //validate the number of Dice selected is ok 
                    nDice=number_of_dice(nKeep);
                    while(nDice>=6||nDice<0){
                        cout<<"That is not a valid input for the number of dice!"<<endl;
                        cout<<"Enter a valid number: This must be a code using the rolled dice"<<endl;
                        cin>>nKeep;
                        nDice=number_of_dice(nKeep);
                    }

                    //split the data up into parts, so it can be inserted into the nKeepArray
                    switch(nDice){
                        case 5:{
                            choice5=(nKeep-nKeep%10000)/10000;  //number in 10000 place
                            nKeep=(nKeep-choice5*10000);
                            nKeepAr[4]=choice5;
                        }
                        case 4:{
                            choice4=(nKeep-nKeep%1000)/1000;    //number of 1000s
                            nKeep=(nKeep-choice4*1000);
                            nKeepAr[3]=choice4;
                        }
                        case 3:{
                            choice3=(nKeep-nKeep%100)/100;      //number in the 100s place
                            nKeep=(nKeep-choice3*100);
                            nKeepAr[2]=choice3;
                        }
                        case 2:{
                            choice2=(nKeep-nKeep%10)/10;
                            nKeepAr[1]=choice2;
                        }
                        case 1:{
                            choice1=(nKeep-choice2*10);
                            nKeepAr[0]=choice1;
                            break;
                        }
                        default:{
                            cout<<"Something went wrong!"<<endl;
                        }
                    }

                    //sort the array
                    mrkSort(nKeepAr,hSIZE);

                    /*
                    //print array to see if everything was inserted correctly
                    for(int k=0;k<5;k++){
                        cout<<nKeepAr[k]<<endl;
                    }

                    cout<<"Boolean: "<<is1to5<<endl;
                    */
                    //make sure there are no repeated numbers or numbers greater than 5
                    if(valnKeep(nKeepAr)==false){
                        //communication with user
                        cout<<"TRY AGAIN\n"<<endl;

                    }
                    else{
                        //cout<<"valnKeep is now true"<<endl;
                        is1to5=true;
                    }
                }
            }while(is1to5==false);
            
            cout<<endl;
            
            //re-roll the dice that the user has chosen
            for(int k=0;k<hSIZE;k++){
                switch(nKeepAr[k]){
                    case 5:{
                        cout<<"You re-rolled Dice # 5"<<endl;
                        pHand[4]=roll();
                        break;
                    }
                    case 4:{
                        cout<<"You re-rolled Dice # 4"<<endl;
                        pHand[3]=roll();
                        break;
                    }
                    case 3:{
                        cout<<"You re-rolled Dice # 3"<<endl;
                        pHand[2]=roll();
                        break;
                    }
                    case 2:{
                        cout<<"You re-rolled Dice # 2"<<endl;
                        pHand[1]=roll();
                        break;
                    }
                    case 1:{
                        cout<<"You re-rolled Dice # 1"<<endl;
                        pHand[0]=roll();
                        break;
                    }
                }
            }
            
            cout<<endl;
            
            //print the array so the user can see their hand
            prntHand(pHand,hSIZE);
        }

        //begin grading
        bool okScore=false;

        do{
            //Sort Array
            mrkSort(pHand, hSIZE);
            
            cout<<"\nGrading Stage\n"<<endl;
            
            //display view of user options
            viewOptions(sChk, pHand, hSIZE);

            unsigned int pSel=0;
            
            //get user input 
            cout<<"Enter the number for the way you want your hand to be graded"<<endl;
            cin>>pSel;

            //validate the input
            while(pSel>=14&&pSel!=0){
                cout<<"TRY AGAIN: Invalid Input"<<endl;
                cout<<"Enter the number for the way you want your hand to be graded"<<endl;
            }

            //grading switch statement if user input is valid, get out of loop
            switch(pSel){
                //Upper section grading
                case 1:{
                    if(isNotUsed(sChk, pSel)){
                        //if the value is not use, change the boolean value
                        sChk[pSel-1]=true;

                        //then assign the appropriate value to the hand
                        pSCard[pSel-1][1]=totUpper(pHand,pSel);

                        //Inform the player
                        cout<<"Player chooses to grade their Aces!"<<endl;
                        cout<<"Aces: "<<pSCard[pSel-1][1]<<endl;

                        //lets the user out of the loop
                        okScore=true;

                        //break from the switch statement
                        break;
                    }
                    else{
                        //Inform player
                        cout<<"Aces have already been used!"<<endl;

                        break;
                    }
                }
                case 2:{
                    if(isNotUsed(sChk, pSel)){
                        //if the value is not use, change the boolean value
                        sChk[pSel-1]=true;

                        //then assign the appropriate value to the hand
                        pSCard[pSel-1][1]=totUpper(pHand,pSel);

                        //Inform the player
                        cout<<"Player chooses to grade their Twos!"<<endl;
                        cout<<"Twos: "<<pSCard[pSel-1][1]<<endl;

                        //lets the user out of the loop
                        okScore=true;

                        //break from the switch statement
                        break;
                    }
                    else{
                        //Inform player
                        cout<<"Twos have already been used!"<<endl;

                        break;
                    }
                }
                case 3:{
                    if(isNotUsed(sChk, pSel)){
                        //if the value is not use, change the boolean value
                        sChk[pSel-1]=true;

                        //then assign the appropriate value to the hand
                        pSCard[pSel-1][1]=totUpper(pHand,pSel);

                        //Inform the player
                        cout<<"Player chooses to grade their Threes!"<<endl;
                        cout<<"Threes: "<<pSCard[pSel-1][1]<<endl;

                        //lets the user out of the loop
                        okScore=true;

                        //break from the switch statement
                        break;
                    }
                    else{
                        //Inform player
                        cout<<"Threes have already been used!"<<endl;

                        break;
                    }
                }
                case 4:{
                    if(isNotUsed(sChk, pSel)){
                        //if the value is not use, change the boolean value
                        sChk[pSel-1]=true;

                        //then assign the appropriate value to the hand
                        pSCard[pSel-1][1]=totUpper(pHand,pSel);

                        //Inform the player
                        cout<<"Player chooses to grade their Fours!"<<endl;
                        cout<<"Fours: "<<pSCard[pSel-1][1]<<endl;

                        //lets the user out of the loop
                        okScore=true;

                        //break from the switch statement
                        break;
                    }
                    else{
                        //Inform player
                        cout<<"Fours have already been used!"<<endl;

                        break;
                    }
                }
                case 5:{
                    if(isNotUsed(sChk, pSel)){
                        //if the value is not use, change the boolean value
                        sChk[pSel-1]=true;

                        //then assign the appropriate value to the hand
                        pSCard[pSel-1][1]=totUpper(pHand,pSel);

                        //Inform the player
                        cout<<"Player chooses to grade their Fives!"<<endl;
                        cout<<"Fives: "<<pSCard[pSel-1][1]<<endl;

                        //lets the user out of the loop
                        okScore=true;

                        //break from the switch statement
                        break;
                    }
                    else{
                        //Inform player
                        cout<<"Fives have already been used!"<<endl;

                        break;
                    }
                }
                case 6:{
                    if(isNotUsed(sChk, pSel)){
                        //if the value is not use, change the boolean value
                        sChk[pSel-1]=true;

                        //then assign the appropriate value to the hand
                        pSCard[pSel-1][1]=totUpper(pHand,pSel);

                        //Inform the player
                        cout<<"Player chooses to grade their Sixes!"<<endl;
                        cout<<"Sixes: "<<pSCard[pSel-1][1]<<endl;

                        //lets the user out of the loop
                        okScore=true;

                        //break from the switch statement
                        break;
                    }
                    else{
                        //Inform player
                        cout<<"Sixes have already been used!"<<endl;

                        break;
                    }
                }
                //3 of a kind
                case 7:{
                    if(isNotUsed(sChk, pSel)&&is3Kind(pHand)){
                        //if the value is not use, change the boolean value
                        sChk[pSel-1]=true;

                        //then assign the appropriate value to the hand
                        pSCard[pSel-1][1]=Sum(pHand);

                        //Inform the player
                        cout<<"Player chooses 3 of a kind"<<endl;
                        cout<<"3 of a kind: "<<pSCard[pSel-1][1]<<endl;

                        //lets the user out of the loop
                        okScore=true;

                        //break from the switch statement
                        break;
                    }
                    else if(isNotUsed(sChk, pSel)&&!is3Kind(pHand)){
                        //if the value is not use, change the boolean value
                        sChk[pSel-1]=true;

                        //then assign the appropriate value to the hand
                        pSCard[pSel-1][1]=0;

                        cout<<"Scratch 3 of a kind"<<endl;

                        //lets the user out of the loop
                        okScore=true;

                        //break from the switch statement
                        break;
                    }
                    else{
                        //Inform player
                        cout<<"3 of a Kind has already been used!"<<endl;

                        //break from the switch statement
                        break;
                    }
                }
                //4 of a kind
                case 8:{
                    if(isNotUsed(sChk, pSel)&&is4Kind(pHand)){
                        //if the value is not use, change the boolean value
                        sChk[pSel-1]=true;

                        //then assign the appropriate value to the hand
                        pSCard[pSel-1][1]=Sum(pHand);

                        //Inform the player
                        cout<<"Player chooses 4 of a kind"<<endl;
                        cout<<"4 of a kind: "<<pSCard[pSel-1][1]<<endl;

                        //lets the user out of the loop
                        okScore=true;

                        //break from the switch statement
                        break;
                    }
                    else if(isNotUsed(sChk, pSel)&&!is4Kind(pHand)){
                        //if the value is not use, change the boolean value
                        sChk[pSel-1]=true;

                        //then assign the appropriate value to the hand
                        pSCard[pSel-1][1]=0;

                        cout<<"Scratch 4 of a kind"<<endl;

                        //lets the user out of the loop
                        okScore=true;

                        //break from the switch statement
                        break;
                    }
                    else{
                        //Inform player
                        cout<<"4 of a Kind has already been used!"<<endl;

                        //break from the switch statement
                        break;
                    }
                }
                //full house
                case 9:{
                    if(isNotUsed(sChk, pSel)&&isFull(pHand)){
                        //if the value is not used, change the boolean value
                        sChk[pSel-1]=true;

                        //then assign the appropriate value to the hand
                        pSCard[pSel-1][1]=25;

                        //Inform the player
                        cout<<"Player chooses Full House"<<endl;
                        cout<<"Full House: "<<pSCard[pSel-1][1]<<endl;

                        //lets the user out of the loop
                        okScore=true;

                        //break from the switch statement
                        break;
                    }
                    else if(isNotUsed(sChk, pSel)&&!isFull(pHand)){
                        //if the value is not use, change the boolean value
                        sChk[pSel-1]=true;

                        //then assign the appropriate value to the hand
                        pSCard[pSel-1][1]=0;

                        cout<<"Scratch Full House"<<endl;

                        //lets the user out of the loop
                        okScore=true;

                        //break from the switch statement
                        break;
                    }
                    else{
                        //Inform player
                        cout<<"Full House has already been used!"<<endl;

                        //break from the switch statement
                        break;
                    }
                }
                //Small Straight
                case 10:{
                    if(isNotUsed(sChk, pSel)&&isSS(pHand,hSIZE)){
                        //if the value is not use, change the boolean value
                        sChk[pSel-1]=true;

                        //then assign the appropriate value to the hand
                        pSCard[pSel-1][1]=30;

                        //Inform the player
                        cout<<"Player chooses Small Straight"<<endl;
                        cout<<"Small Straight: "<<pSCard[pSel-1][1]<<endl;

                        //lets the user out of the loop
                        okScore=true;

                        //break from the switch statement
                        break;
                    }
                    else if(isNotUsed(sChk, pSel)&&!isSS(pHand,hSIZE)){
                        //if the value is not use, change the boolean value
                        sChk[pSel-1]=true;

                        //then assign the appropriate value to the hand
                        pSCard[pSel-1][1]=0;

                        cout<<"Scratch Small Straight"<<endl;

                        //lets the user out of the loop
                        okScore=true;

                        //break from the switch statement
                        break;
                    }
                    else{
                        //Inform player
                        cout<<"Small Straight has already been used!"<<endl;

                        //break from the switch statement
                        break;
                    }
                }
                //Large Straight
                case 11:{
                    if(isNotUsed(sChk, pSel)&&isLS(pHand)){
                        //if the value is not use, change the boolean value
                        sChk[pSel-1]=true;

                        //then assign the appropriate value to the hand
                        pSCard[pSel-1][1]=40;

                        //Inform the player
                        cout<<"Player chooses Large Straight"<<endl;
                        cout<<"Large Straight: "<<pSCard[pSel-1][1]<<endl;

                        //lets the user out of the loop
                        okScore=true;

                        //break from the switch statement
                        break;
                    }
                    else if(isNotUsed(sChk, pSel)&&!isLS(pHand)){
                        //if the value is not use, change the boolean value
                        sChk[pSel-1]=true;

                        //then assign the appropriate value to the hand
                        pSCard[pSel-1][1]=0;

                        cout<<"Scratch Large Straight"<<endl;

                        //lets the user out of the loop
                        okScore=true;

                        //break from the switch statement
                        break;
                    }
                    else{
                        //Inform player
                        cout<<"Large Straight has already been used!"<<endl;

                        //break from the switch statement
                        break;
                    }
                }
                //Yahtzee
                case 12:{
                    if(isNotUsed(sChk, pSel)&&isY(pHand)){
                        //if the value is not use, change the boolean value
                        sChk[pSel-1]=true;

                        //then assign the appropriate value to the hand
                        pSCard[pSel-1][1]=50;

                        //Inform the player
                        cout<<"Player chooses Yahtzee!"<<endl;
                        cout<<"Yahtzee: "<<pSCard[pSel-1][1]<<endl;

                        //lets the user out of the loop
                        okScore=true;

                        //break from the switch statement
                        break;
                    }
                    else if(isNotUsed(sChk, pSel)&&!isY(pHand)){
                        //if the value is not use, change the boolean value
                        sChk[pSel-1]=true;

                        //then assign the appropriate value to the hand
                        pSCard[pSel-1][1]=0;

                        cout<<"Scratch Yahtzee"<<endl;

                        //lets the user out of the loop
                        okScore=true;

                        //break from the switch statement
                        break;
                    }
                    else{
                        //Inform player
                        cout<<"Large Straight has already been used!"<<endl;

                        //break from the switch statement
                        break;
                    }
                }
                //Chance
                case 13:{
                    if(isNotUsed(sChk, pSel)){
                        //if the value is not use, change the boolean value
                        sChk[pSel-1]=true;

                        //then assign the appropriate value to the hand
                        pSCard[pSel-1][1]=Sum(pHand);

                        //Inform the player
                        cout<<"Player chooses Chance!"<<endl;
                        cout<<"Chance: "<<pSCard[pSel-1][1]<<endl;

                        //lets the user out of the loop
                        okScore=true;

                        //break from the switch statement
                        break;
                    }
                    else{
                        //Inform player
                        cout<<"Chance has already been used!"<<endl;

                        //break from the switch statement
                        break;
                    }
                }
            }
        }while(okScore==false);

        prntScrCrd(pSCard);
        
        //prntArr(sChk, nSCORES);
    
    }
    
    //ouput the score card after the game is finished
    fileoutScrCrd(pSCard);
    
    return 0;
}

void getnTurn(int &a){
    ifstream in;
    in.open("inYahtzee.dat");
    in>>a;
    in.close();
}

//roll function
unsigned short roll(){
    //set the random number seed,  give random die
    unsigned short value=rand()%6+1;//[1,6]
    return value;
}

//figure out the number of dice
int number_of_dice(int number){
    int diceNumber=1;
    
    while(number/=10){
        diceNumber++;
    }
    
    cout<<"Number of Dice Selected: "<<diceNumber<<endl;
    
    return diceNumber;
}

//the famous Mark sort 
void mrkSort(unsigned short a[], unsigned short n){
    //nested for loop 
    for(int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if(a[i]<a[j]){
                a[i]=a[i]^a[j];
                a[j]=a[i]^a[j];
                a[i]=a[i]^a[j];
            }
        }
    }
}

//check to make sure all of the digits are valid, and there are no multiples
bool valnKeep(unsigned short chk[]){
    bool x=true;
    
    for(int j=0;j<5;j++){
        if(chk[j]==chk[j+1]&&chk[j]!=0){
            cout<<"You entered multiples of the same numbers, NOT VALID!"<<endl;
            cout<<"You can't re-roll the same dice multiple times!"<<endl;
            x=false;
        }
        if(chk[j]>=6){
            cout<<chk[j]<<" is too large!"<<endl;
            x=false;
        }
    }
    return x;
}

void prntHand(unsigned short Arr[], unsigned short SIZE){
    for(int i=0;i<SIZE;i++){
        cout<<"Dice #"<<i+1<<": "<<Arr[i]<<endl;
    }
}

//Grading functions

//checking to see if a specific score has been used yet
bool isNotUsed(bool Arr[], int Index){//fix, logic error
    if(Arr[Index-1]==false){
        return true;
    }
    return false;
}

//checks to see if a player has a specific value in their hand
bool isLowerSection(unsigned short chk[], int Num, unsigned short SIZE){
    //checks to see if a player has a specific value in their hand
    for(int i=0;i<SIZE;i++){
        if(chk[i]==Num){
            return true;
        }
    }
    return false;
}


//totals specific values for the lower section
unsigned short totUpper(unsigned short tChk[], int tNum){
    unsigned short total=0;
    
    for(int i=0;i<5;i++){
        if(tChk[i]==tNum){
            total+=tChk[i];
        }
    }
    return total;
}

unsigned short Sum(unsigned short tChk[]){
    unsigned short total=0;
    
    for(int i=0;i<5;i++){
        total+=tChk[i];
    }
    
    return total;
}

bool is3Kind(unsigned short Arry[]){
    if ((Arry[0]==Arry[1]&&Arry[1]==Arry[2])||
            (Arry[2]==Arry[3]&&Arry[3]==Arry[4])){
        return true;
    }
    else{
        return false;
    }
}

bool is4Kind(unsigned short Arry[]){
    if ((Arry[0]==Arry[1]&&Arry[1]==Arry[2]&&Arry[2]==Arry[3])||
            (Arry[1]==Arry[2]&&Arry[2]==Arry[3]&&Arry[3]==Arry[4])){
        return true;
    }
    else{
        return false;
    }
}

bool isFull(unsigned short Arry[]){
    if (((Arry[0]==Arry[1]&&Arry[1]==Arry[2])&&(Arry[3]==Arry[4]))||
            ((Arry[2]==Arry[3]&&Arry[3]==Arry[4])&&(Arry[0]==Arry[1]))){
        return true;
    }
    else{
        return false;
    }
}

bool isSS(unsigned short Arry[], unsigned short S){
    unsigned short temp[S];
    bool isOk=false;
    
    //create temp array
    for(int i=0;i<S;i++){
        temp[i]=Arry[i];
    }
    
    //move any doubles to the back of the array
    for(int j=0;j<(S-1);j++){
        int Zero=0;
        if(temp[j]==Arry[j+1]){
            temp[j]=Zero;
        }
        mrkSort(temp,S);
    }
    
    
    if((temp[1]==(temp[2]-1))&&(temp[1]==(temp[3]-2))&&(temp[1]==(temp[4]-3))){
        isOk=true;
    }
    return isOk;
}

bool isLS(unsigned short Arry[]){
    if(((Arry[0]+1)==Arry[1])&&((Arry[0]+2)==Arry[2])&&
            ((Arry[0]+3)==Arry[3])&&((Arry[0]+4)==Arry[4])||
            (((Arry[1]+1)==Arry[2])&&((Arry[1]+2)==Arry[3])&&
            ((Arry[1]+3)==Arry[3])&&((Arry[1]+4)==Arry[4]))){
        return true;
    }
    return false;
}

bool isY(unsigned short Arry[]){
    if(Arry[0]==Arry[1]&&Arry[1]==Arry[2]&&Arry[2]==Arry[3]&&Arry[3]==Arry[4]){
        return true;
    }
    return false;
}

void viewOptions(bool chkAr[], unsigned short hand[], unsigned short S){
    for(int i=1;i<=7;i++){
        //prints out Upper section options
        if(i<=6&&isLowerSection(hand,i,hSIZE)&&isNotUsed(chkAr, i)){
            cout<<i<<")The total of your "<<i<<"s: "<<totUpper(hand, i)<<endl;
        }
        else if(i<=6&&isNotUsed(chkAr, i)){
            cout<<i<<")Scratch your "<<i<<"s"<<endl;
        }
        else if(i<=6&&!(isNotUsed(chkAr, i))){
            cout<<i<<")Already used your"<<i<<"s"<<endl;
        }
        //for Lower section options
        else{
            switch(i){
                //3 of a kind
                case 7:{
                    if(isNotUsed(chkAr, i)&&is3Kind(hand)){
                        cout<<"7)You have a 3 of a kind"<<endl;
                    }
                    else if(isNotUsed(chkAr, i)&&!is3Kind(hand)){
                        cout<<"7)You can scratch 3 of a kind"<<endl;
                    }
                    else{
                        cout<<"7)You have used 3 of a kind"<<endl;
                    }

                }
                //4 of a kind
                case 8:{
                    if(isNotUsed(chkAr, i+1)&&is4Kind(hand)){
                        cout<<"8)You have a 4 of a kind"<<endl;
                    }
                    else if(isNotUsed(chkAr, i+1)&&!is4Kind(hand)){
                        cout<<"8)You can scratch 4 of a kind"<<endl;
                    }
                    else{
                        cout<<"8)You have used 4 of a kind"<<endl;
                    }
                }
                //Full House
                case 9:{
                    if(isNotUsed(chkAr, i+2)&&isFull(hand)){
                        cout<<"9)You have a Full House"<<endl;
                    }
                    else if(isNotUsed(chkAr, i+2)&&!isFull(hand)){
                        cout<<"9)You can scratch Full House"<<endl;
                    }
                    else{
                        cout<<"9)You have used Full House"<<endl;
                    }
                }
                //Small Straight
                case 10:{
                    if(isNotUsed(chkAr, i+3)&&isSS(hand,S)){
                        cout<<"10)You have a Small Straight"<<endl;
                    }
                    else if(isNotUsed(chkAr, i+3)&&!isSS(hand,S)){
                        cout<<"10)You can scratch Small Straight"<<endl;
                    }
                    else{
                        cout<<"10)You have used Small Straight"<<endl;
                    }
                }
                //Large Straight
                case 11:{
                    if(isNotUsed(chkAr, i+4)&&isLS(hand)){
                        cout<<"11)You have a Large Straight"<<endl;
                    }
                    else if(isNotUsed(chkAr, i+4)&&!isLS(hand)){
                        cout<<"11)You can scratch Large Straight"<<endl;
                    }
                    else{
                        cout<<"11)You have used Large Straight"<<endl;
                    }
                }
                //Yahtzee
                case 12:{
                    if(isNotUsed(chkAr, i+5)&&isY(hand)){
                        cout<<"12)You have a Yahtzee"<<endl;
                    }
                    else if(isNotUsed(chkAr, i+5)&&!isY(hand)){
                        cout<<"12)You can scratch Yahtzee"<<endl;
                    }
                    else{
                        cout<<"12)You have used Yahtzee"<<endl;
                    }
                }
                //Chance
                case 13:{
                    if(isNotUsed(chkAr, i+6)){
                        cout<<"13)You can use Chance"<<endl;
                    }
                    else{
                        cout<<"13)You have used Chance"<<endl;
                    }
                }
            }
        }
    }
}

//prints out the score card after each round!
void prntScrCrd(unsigned short Arr[nSCORES][sSIZE]){
    int uTotal=0;
    int uBonus=0;
    int lTotal=0;
    int oTotal=0;
    
    uTotal=Arr[0][1]+Arr[1][1]+Arr[2][1]+Arr[3][1]+Arr[4][1]+Arr[5][1];
    lTotal=Arr[6][1]+Arr[7][1]+Arr[8][1]+Arr[9][1]+Arr[10][1]+Arr[11][1]+Arr[12][1];
    oTotal=uTotal+lTotal;
    
    if(uTotal>=63){
        uBonus=36;
        oTotal+=uBonus;
    }
    
    cout<<"Upper Section\r\n"<<endl;
    cout<<Arr[0][0]<<") Aces:               "<<Arr[0][1]<<endl;
    cout<<Arr[1][0]<<") Twos:               "<<Arr[1][1]<<endl;
    cout<<Arr[2][0]<<") Threes:             "<<Arr[2][1]<<endl;
    cout<<Arr[3][0]<<") Fours:              "<<Arr[3][1]<<endl;
    cout<<Arr[4][0]<<") Fives:              "<<Arr[4][1]<<endl;
    cout<<Arr[5][0]<<") Sixes:              "<<Arr[5][1]<<"\r\n"<<endl;
    cout<<"Upper Total:                     "<<uTotal<<endl;
    cout<<"Bonus:                           "<<uBonus<<"\r\n"<<endl;
    cout<<"Lower Section\r\n"<<endl;
    cout<<Arr[6][0]<<") 3 of a Kind:        "<<Arr[6][1]<<endl;
    cout<<Arr[7][0]<<") 4 of a Kind:        "<<Arr[7][1]<<endl;
    cout<<Arr[8][0]<<") Full House:         "<<Arr[8][1]<<endl;
    cout<<Arr[9][0]<<") Small Straight:    "<<Arr[9][1]<<endl;
    cout<<Arr[10][0]<<") Large Straight:    "<<Arr[10][1]<<endl;
    cout<<Arr[11][0]<<") Yahtzee:           "<<Arr[11][1]<<endl;
    cout<<Arr[12][0]<<") Chance:            "<<Arr[12][1]<<"\r\n"<<endl;
    cout<<"Lower Total:                     "<<lTotal<<endl;
    cout<<"Score:                           "<<oTotal<<"\r\n"<<endl;
}

void fileoutScrCrd(unsigned short Arr[nSCORES][sSIZE]){
    int uTotal=0;
    int uBonus=0;
    int lTotal=0;
    int oTotal=0;
    
    //open output stream to file
    ofstream out;
    
    uTotal=Arr[0][1]+Arr[1][1]+Arr[2][1]+Arr[3][1]+Arr[4][1]+Arr[5][1];
    lTotal=Arr[6][1]+Arr[7][1]+Arr[8][1]+Arr[9][1]+Arr[10][1]+Arr[11][1]+Arr[12][1];
    oTotal=uTotal+lTotal;
    
    if(uTotal>=63){
        uBonus=36;
        oTotal+=uBonus;
    }
    
    //print the output to the screen
    out.open("Yahtzee.dat");
    
    out<<"Yahtzee Score Card\nCIS 5 Spring 2016 by\nChristopher Schaefer\n\n"<<endl;
    out<<"Upper Section\r\n"<<endl;
    out<<Arr[0][0]<<") Aces:               "<<Arr[0][1]<<endl;
    out<<Arr[1][0]<<") Twos:               "<<Arr[1][1]<<endl;
    out<<Arr[2][0]<<") Threes:             "<<Arr[2][1]<<endl;
    out<<Arr[3][0]<<") Fours:              "<<Arr[3][1]<<endl;
    out<<Arr[4][0]<<") Fives:              "<<Arr[4][1]<<endl;
    out<<Arr[5][0]<<") Sixes:              "<<Arr[5][1]<<"\r\n"<<endl;
    out<<"Upper Total:                     "<<uTotal<<endl;
    out<<"Bonus:                           "<<uBonus<<"\r\n"<<endl;
    out<<"Lower Section\r\n"<<endl;
    out<<Arr[6][0]<<") 3 of a Kind:        "<<Arr[6][1]<<endl;
    out<<Arr[7][0]<<") 4 of a Kind:        "<<Arr[7][1]<<endl;
    out<<Arr[8][0]<<") Full House:         "<<Arr[8][1]<<endl;
    out<<Arr[9][0]<<") Small Straight:    "<<Arr[9][1]<<endl;
    out<<Arr[10][0]<<") Large Straight:    "<<Arr[10][1]<<endl;
    out<<Arr[11][0]<<") Yahtzee:           "<<Arr[11][1]<<endl;
    out<<Arr[12][0]<<") Chance:            "<<Arr[12][1]<<"\r\n"<<endl;
    out<<"Lower Total:                     "<<lTotal<<endl;
    out<<"Score:                           "<<oTotal<<"\r\n"<<endl;
    
    out.close();
}

void prntArr(bool Arr[], unsigned short SIZE){
    for(int i=0;i<SIZE;i++){
        cout<<i+1<<") Value: "<<Arr[i]<<endl;
    }
}

