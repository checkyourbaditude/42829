/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: chris
 *
 * Created on April 28, 2016, 6:11 PM
 */

#include <cstdlib>
#include <iostream>
#include <ctime>
#include<fstream>
using namespace std;

//functional prototypes
unsigned short roll();
int number_of_dice(int number);
bool isValid(int vNum, unsigned int vdNum);
bool isValid1(int userIn);
bool isValid2(int userIn);
bool isValid3(int userIn);
bool isValid4(int userIn);
bool isValid5(int userIn);

//the grading portion of the game, after each turn
unsigned int totAces(unsigned short o1,unsigned short o2,unsigned short o3,
        unsigned short o4,unsigned short o5);
unsigned int totTwos(unsigned short o1,unsigned short o2,unsigned short o3,
        unsigned short o4,unsigned short o5);
unsigned int totThrees(unsigned short o1,unsigned short o2,unsigned short o3,
        unsigned short o4,unsigned short o5);
unsigned int totFours(unsigned short o1,unsigned short o2,unsigned short o3,
        unsigned short o4,unsigned short o5);
unsigned int totFives(unsigned short o1,unsigned short o2,unsigned short o3,
        unsigned short o4,unsigned short o5);
unsigned int totSixes(unsigned short o1,unsigned short o2,unsigned short o3,
        unsigned short o4,unsigned short o5);
bool isSS(unsigned short o1,unsigned short o2,unsigned short o3,
        unsigned short o4,unsigned short o5);
bool isLS(unsigned short o1,unsigned short o2,unsigned short o3,
        unsigned short o4,unsigned short o5);
unsigned short findSmallest(unsigned short s1,unsigned short s2,
        unsigned short s3,unsigned short s4,unsigned short s5);
void fileOut(int score1, int score2, int score3, int score4, int score5,
        int score6, int score7, int score8, int score9, int score10,
        int score11, int score12, int score13);

int main(int argc, char** argv) {
    //Set the random number seed for variability
    srand(static_cast<unsigned int>(time(NULL)));
    
    //greeting
    cout<<"Lets Play Yahtzee!"<<endl;
    cout<<"Rules:"<<endl;
    cout<<"-You must enter the  sequential code corresponding to the dice #s"<<endl;
    cout<<" you would like to keep.\n-Enter a zero if you would like to ";
    cout<<"roll all of the dice again."<<endl;
    cout<<"-Sequences with zeros are not allowed."<<endl;
    cout<<"     For Example: 325 is valid, however 2035 is not.\n"<<endl;
    cout<<"Here is the first roll!(enter anything and press enter)"<<endl;
    cin.get();
    cin.ignore();
    
    //variables
    //keeping track if a category has been used
    //upper section
    bool usedAces=0, usedTwos=0, usedThrees=0, usedFours=0, usedFives=0, usedSixes=0;
    
    //lower section
    bool used3Kind=0, used4Kind=0, usedFull=0, usedSS=0, usedLS=0, usedYahtzee=0, usedChance=0;
    
    //keeping track of values in the score sheet
    //upper section
    int SS1=0, SS2=0, SS3=0, SS4=0, SS5=0, SS6=0;
    
    //lower section
    int SS7=0, SS8=0, SS9=0, SS10=0, SS11=0, SS12=0, SS13=0;
    
    //get the file information
    //initiate Game
    for(int j=1;j<=13;j++){
        cout<<"Turn #"<<j<<endl;
        unsigned short die1=roll();//[1,6]
        unsigned short die2=roll();//[1,6]
        unsigned short die3=roll();//[1,6]
        unsigned short die4=roll();//[1,6]
        unsigned short die5=roll();//[1,6]
        
        //output the results
        cout<<"Dice 1:"<<die1<<endl;
        cout<<"Dice 2:"<<die2<<endl;
        cout<<"Dice 3:"<<die3<<endl;
        cout<<"Dice 4:"<<die4<<endl;
        cout<<"Dice 5:"<<die5<<endl;
        
        //initiate a turn
        for(int i=2;i<=3;i++){
            
            //local variables
            bool is1to5=0;
            unsigned int nDice=0;
            int nKeep=0;
            //data validation, make sure all digits are between 1 and 5
            //make sure no numbers greater than 5 are entered
            
            do{
                //ask user what they would like to keep
                cout<<"Enter the numbers of the dice you would like to keep!"<<endl;
                cout<<"If you would like to keep nothing, just press zero (0)"<<endl;
                cout<<"All digits must be between 1 and 5"<<endl;
                cin>>nKeep;
                if(nKeep==0)break;
                else{

                    //figuring out the number of dice, to direct the number kept correctly
                    nDice=number_of_dice(nKeep);
                    while(nDice>=6){
                        cout<<"That is not a valid input for the number of dice!"<<endl;
                        cout<<"Enter a valid number: This must be a code using the rolled dice"<<endl;
                        cin>>nKeep;
                        nDice=number_of_dice(nKeep);
                    }
                    //checking all values are between 1 and 5
                    is1to5=isValid(nKeep,nDice);
                }
            }while(is1to5==0);
            //branching to figure out which dies to roll again. and which to keep
            switch(nDice){
                //if only 1 dice is kept
                case 1:{
                    //if only the dice in 1 position is kept
                    if(nKeep==1){
                        cout<<"You have kept dice number 1"<<endl;

                        //call the dice that were not kept to be rolled
                        die2=roll();//[1,6]
                        die3=roll();//[1,6]
                        die4=roll();//[1,6]
                        die5=roll();//[1,6]
                        break;
                    }
                    if(nKeep==2){
                        cout<<"You have kept dice number 2"<<endl;

                        //call the dice that were not kept to be rolled
                        die1=roll();//[1,6]
                        die3=roll();//[1,6]
                        die4=roll();//[1,6]
                        die5=roll();//[1,6]
                        break;
                    }
                    if(nKeep==3){
                        cout<<"You have kept dice number 3"<<endl;

                        //call the dice that were not kept to be rolled
                        die1=roll();//[1,6]
                        die2=roll();//[1,6]
                        die4=roll();//[1,6]
                        die5=roll();//[1,6]
                        break;
                    }
                    if(nKeep==4){
                        cout<<"You have kept dice number 4"<<endl;

                        //call the dice that were not kept to be rolled
                        die1=roll();//[1,6]
                        die2=roll();//[1,6]
                        die3=roll();//[1,6]
                        die5=roll();//[1,6]
                        break;
                    }
                    if(nKeep==5){
                        cout<<"You have kept dice number 5"<<endl;

                        //call the dice that were not kept to be rolled
                        die1=roll();//[1,6]
                        die2=roll();//[1,6]
                        die3=roll();//[1,6]
                        die4=roll();//[1,6]
                        break;
                    }
                }
                //if 2 dice is kept
                case 2:{
                    if(nKeep==12||nKeep==21){
                        cout<<"You have kept dice number 1 and 2"<<endl;

                        //call the dice that were not kept to be rolled
                        die3=roll();//[1,6]
                        die4=roll();//[1,6]
                        die5=roll();//[1,6]
                        break;
                    }
                    if(nKeep==13||nKeep==31){
                        cout<<"You have kept dice number 1 and 3"<<endl;

                        //call the dice that were not kept to be rolled
                        die2=roll();//[1,6]
                        die4=roll();//[1,6]
                        die5=roll();//[1,6]
                        break;
                    }
                    if(nKeep==14||nKeep==41){
                        cout<<"You have kept dice number 1 and 4"<<endl;

                        //call the dice that were not kept to be rolled
                        die2=roll();//[1,6]
                        die3=roll();//[1,6]
                        die5=roll();//[1,6]
                        break;
                    }
                    if(nKeep==15||nKeep==51){
                        cout<<"You have kept dice number 1 and 5"<<endl;

                        //call the dice that were not kept to be rolled
                        die2=roll();//[1,6]
                        die3=roll();//[1,6]
                        die4=roll();//[1,6]
                        break;
                    }
                    if(nKeep==23||nKeep==32){
                        cout<<"You have kept dice number 2 and 3"<<endl;

                        //call the dice that were not kept to be rolled
                        die1=roll();//[1,6]
                        die4=roll();//[1,6]
                        die5=roll();//[1,6]
                        break;
                    }
                    if(nKeep==24||nKeep==42){
                        cout<<"You have kept dice number 2 and 4"<<endl;

                        //call the dice that were not kept to be rolled
                        die1=roll();//[1,6]
                        die3=roll();//[1,6]
                        die5=roll();//[1,6]
                        break;
                    }
                    if(nKeep==25||nKeep==52){
                        cout<<"You have kept dice number 2 and 5"<<endl;

                        //call the dice that were not kept to be rolled
                        die1=roll();//[1,6]
                        die3=roll();//[1,6]
                        die4=roll();//[1,6]
                        break;
                    }
                    if(nKeep==34||nKeep==43){
                        cout<<"You have kept dice number 3 and 4"<<endl;

                        //call the dice that were not kept to be rolled
                        die1=roll();//[1,6]
                        die2=roll();//[1,6]
                        die5=roll();//[1,6]
                        break;
                    }
                    if(nKeep==35||nKeep==53){
                        cout<<"You have kept dice number 3 and 4"<<endl;

                        //call the dice that were not kept to be rolled
                        die1=roll();//[1,6]
                        die2=roll();//[1,6]
                        die4=roll();//[1,6]
                        break;
                    }
                    if(nKeep==45||nKeep==54){
                        cout<<"You have kept dice number 4 and 5"<<endl;

                        //call the dice that were not kept to be rolled
                        die1=roll();//[1,6]
                        die2=roll();//[1,6]
                        die3=roll();//[1,6]
                        break;
                    }
                }
                //if 3 dice is kept
                case 3:{
                    if(nKeep==123||nKeep==132||nKeep==213||nKeep==231||
                            nKeep==321||nKeep==312){
                        cout<<"You have kept dice number 1, 2, and 3"<<endl;

                        //call the dice that were not kept to be rolled
                        die4=roll();//[1,6]
                        die5=roll();//[1,6]
                        break;
                    }
                    if(nKeep==124||nKeep==142||nKeep==214||nKeep==241||
                            nKeep==421||nKeep==412){
                        cout<<"You have kept dice number 1, 2, and 4"<<endl;

                        //call the dice that were not kept to be rolled
                        die3=roll();//[1,6]
                        die5=roll();//[1,6]
                        break;
                    }
                    if(nKeep==125||nKeep==152||nKeep==215||nKeep==251||
                            nKeep==521||nKeep==512){
                        cout<<"You have kept dice number 1, 2, and 5"<<endl;

                        //call the dice that were not kept to be rolled
                        die3=roll();//[1,6]
                        die4=roll();//[1,6]
                        break;
                    }
                    if(nKeep==134||nKeep==143||nKeep==314||nKeep==341||
                            nKeep==431||nKeep==413){
                        cout<<"You have kept dice number 1, 3, and 4"<<endl;

                        //call the dice that were not kept to be rolled
                        die2=roll();//[1,6]
                        die5=roll();//[1,6]
                        break;
                    }
                    if(nKeep==145||nKeep==154||nKeep==415||nKeep==451||
                            nKeep==541||nKeep==514){
                        cout<<"You have kept dice number 1, 4, and 5"<<endl;

                        //call the dice that were not kept to be rolled
                        die2=roll();//[1,6]
                        die3=roll();//[1,6]
                        break;
                    }
                    if(nKeep==135||nKeep==153||nKeep==315||nKeep==351||
                            nKeep==531||nKeep==513){
                        cout<<"You have kept dice number 1, 3, and 5"<<endl;

                        //call the dice that were not kept to be rolled
                        die2=roll();//[1,6]
                        die4=roll();//[1,6]
                        break;
                    }
                    if(nKeep==234||nKeep==243||nKeep==324||nKeep==342||
                            nKeep==432||nKeep==423){
                        cout<<"You have kept dice number 2, 3, and 4"<<endl;

                        //call the dice that were not kept to be rolled
                        die1=roll();//[1,6]
                        die5=roll();//[1,6]
                        break;
                    }
                    if(nKeep==235||nKeep==253||nKeep==325||nKeep==352||
                            nKeep==532||nKeep==523){
                        cout<<"You have kept dice number 2, 3, and 5"<<endl;

                        //call the dice that were not kept to be rolled
                        die1=roll();//[1,6]
                        die4=roll();//[1,6]
                        break;
                    }
                    if(nKeep==245||nKeep==254||nKeep==425||nKeep==452||
                            nKeep==542||nKeep==524){
                        cout<<"You have kept dice number 2, 4, and 5"<<endl;

                        //call the dice that were not kept to be rolled
                        die1=roll();//[1,6]
                        die3=roll();//[1,6]

                        break;
                    }
                    if(nKeep==345||nKeep==354||nKeep==435||nKeep==453||
                            nKeep==543||nKeep==534){
                        cout<<"You have kept dice number 3, 4, and 5"<<endl;

                        //call the dice that were not kept to be rolled
                        die1=roll();//[1,6]
                        die2=roll();//[1,6]

                        break;
                    }
                    break;
                }
                //if 4 dice is kept
                case 4:{
                    if(nKeep==1234||nKeep==1243||nKeep==1342||nKeep==1324||
                            nKeep==1423||nKeep==1432||nKeep==2134||nKeep==2143||
                            nKeep==2314||nKeep==2341||nKeep==2431||nKeep==2413||
                            nKeep==3124||nKeep==3142||nKeep==3214||nKeep==3241||
                            nKeep==3412||nKeep==3421||nKeep==4123||nKeep==4132||
                            nKeep==4213||nKeep==4231||nKeep==4312||nKeep==4321){
                        cout<<"You have kept dice number 1,2,3, and 4"<<endl;

                        //call the dice that need to be rolled
                        die5=roll();//[1,6]
                        break;
                    }
                    if(nKeep==1345||nKeep==1453||nKeep==1354||nKeep==1345||
                            nKeep==1543||nKeep==1534||nKeep==4135||nKeep==4153||
                            nKeep==4315||nKeep==4351||nKeep==4531||nKeep==4513||
                            nKeep==3145||nKeep==3154||nKeep==3415||nKeep==3451||
                            nKeep==3514||nKeep==3541||nKeep==5143||nKeep==5134||
                            nKeep==5413||nKeep==5431||nKeep==5314||nKeep==5341){
                        cout<<"You have kept dice number 1,3,4, and 5"<<endl;

                        //call the dice that need to be rolled
                        die2=roll();//[1,6]
                        break;
                    }
                    if(nKeep==1235||nKeep==1253||nKeep==1352||nKeep==1325||
                            nKeep==1523||nKeep==1532||nKeep==2135||nKeep==2153||
                            nKeep==2315||nKeep==2351||nKeep==2531||nKeep==2513||
                            nKeep==3125||nKeep==3152||nKeep==3215||nKeep==3251||
                            nKeep==3512||nKeep==3521||nKeep==5123||nKeep==5132||
                            nKeep==5213||nKeep==5231||nKeep==5312||nKeep==5321){
                        cout<<"You have kept dice number 1,2,3, and 5"<<endl;

                        //call the dice that need to be rolled
                        die4=roll();//[1,6]
                        break;
                    }
                    if(nKeep==1245||nKeep==1254||nKeep==1452||nKeep==1425||
                            nKeep==1524||nKeep==1542||nKeep==2145||nKeep==2154||
                            nKeep==2415||nKeep==2451||nKeep==2541||nKeep==2514||
                            nKeep==4125||nKeep==4152||nKeep==4215||nKeep==4251||
                            nKeep==4512||nKeep==4521||nKeep==5124||nKeep==5142||
                            nKeep==5214||nKeep==5241||nKeep==5412||nKeep==5421){
                        cout<<"You have kept dice number 1, 2, 4, and 5"<<endl;

                        //call the dice that need to be rolled
                        die3=roll();//[1,6]
                        break;
                    }
                    if(nKeep==2345||nKeep==5243||nKeep==5342||nKeep==5324||
                            nKeep==5423||nKeep==5432||nKeep==2534||nKeep==2543||
                            nKeep==2354||nKeep==2345||nKeep==2435||nKeep==2453||
                            nKeep==3524||nKeep==3542||nKeep==3254||nKeep==3245||
                            nKeep==3452||nKeep==3425||nKeep==4523||nKeep==4532||
                            nKeep==4253||nKeep==4235||nKeep==4352||nKeep==4325){
                        cout<<"You have kept dice number 2, 3, 4, and 5"<<endl;

                        //call the dice that need to be rolled
                        die1=roll();//[1,6]
                        break;
                    }
                    break;
                }
                //if 5 dice is kept
                case 5:{
                    i=4;
                    break;
                }
                //if 0 dice is kept or bad input from user
                default:{
                    die1=roll();//[1,6]
                    die2=roll();//[1,6]
                    die3=roll();//[1,6]
                    die4=roll();//[1,6]
                    die5=roll();//[1,6]
                    break;
                }
            }
            //output the results
            cout<<"Dice 1:"<<die1<<endl;
            cout<<"Dice 2:"<<die2<<endl;
            cout<<"Dice 3:"<<die3<<endl;
            cout<<"Dice 4:"<<die4<<endl;
            cout<<"Dice 5:"<<die5<<endl;
        }

        //begin grading
        do{
            cout<<"Press enter to continue"<<endl;
            cin.get();
            cin.ignore();

            //local variables, get user input and make sure to signal if it was valid
            bool okScore=0;
            unsigned int pSel=0;
            cout<<"enter the number for the way you want your hand to be graded"<<endl;

            /*for the upper section, give user totals to decide what their best move is
             *The user will know what options they have based off this branching. 
             * This includes scratches!
             * At the end they can choose what option they want
             * The value will be stored in the correct variable based on the
             * switch statement. If they choose an invalid option, they 
             * will be put back to the begining of this loop
             */
             
            if((usedAces==0)&&(die1==1||die2==1||die3==1||die4==1||die5==1)){
                cout<<"1)The total of your aces is:     "<<totAces(die1,die2,die3,die4,die5)<<endl;
            }
            else if(usedAces==0){
                cout<<"1)You can Scratch your Aces"<<endl;
            }
            if((usedTwos==0)&&(die1==2||die2==2||die3==2||die4==2||die5==2)){
                cout<<"2)The total of your twos is:     "<<totTwos(die1,die2,die3,die4,die5)<<endl;
            }
            else if(usedTwos==0){
                cout<<"2)You can Scratch your Twos"<<endl;
            }
            if((usedThrees==0)&&(die1==3||die2==3||die3==3||die4==3||die5==3)){
                cout<<"3)The total of your threes is:   "<<totThrees(die1,die2,die3,die4,die5)<<endl;
            }
            else if(usedThrees==0){
                cout<<"3)You can Scratch your Threes"<<endl;
            }
            if((usedFours==0)&&(die1==4||die2==4||die3==4||die4==4||die5==4)){
                cout<<"4)The total of your fours is:    "<<totFours(die1,die2,die3,die4,die5)<<endl;
            }
            else if(usedFours==0){
                cout<<"4)You can Scratch your Fours"<<endl;
            }
            if((usedFives==0)&&(die1==5||die2==5||die3==5||die4==5||die5==5)){
                cout<<"5)The total of your fives is:    "<<totFives(die1,die2,die3,die4,die5)<<endl;
            }
            else if(usedFives==0){
                cout<<"5)You can Scratch your Fives"<<endl;
            }
            if((usedSixes==0)&&(die1==6||die2==6||die3==6||die4==6||die5==6)){
                cout<<"6)The total of your Sixes is:    "<<totSixes(die1,die2,die3,die4,die5)<<endl;
            }
            else if(usedSixes==0){
                cout<<"6)You can Scratch your Sixes"<<endl;
            }

            //for the lower section
            //three of a kind
            if((used3Kind==0)&&(die1==die2&&die2==die3)||(die1==die2&&die2==die4)||
                    (die1==die2&&die2==die5)||(die1==die3&&die3==die4)||
                    (die1==die3&&die3==die5)||(die1==die4&&die4==die5)||
                    (die2==die3&&die3==die4)||(die2==die3&&die4==die5)||
                    (die2==die3&&die3==die5)||(die3==die4&&die4==die5)){
                cout<<"7)You have a three of a kind:    "<<(die1+die2+die3+die4+die5)<<endl;
            }
            else if(used3Kind==0){
                cout<<"7)You can Scratch your Three of a Kind"<<endl;
            }
            //four of a kind
            if((used4Kind==0)&&(die1==die2&&die2==die3&&die3==die4)||
                    (die1==die3&&die3==die4&&die4==die5)||
                    (die1==die2&&die2==die3&&die3==die5)||
                    (die1==die2&&die2==die4&&die4==die5)||
                    (die2==die3&&die3==die4&&die4==die5)){
                cout<<"8)You have a four of a kind:     "<<(die1+die2+die3+die4+die5)<<endl;
            }
            else if(used4Kind==0){
                cout<<"8)You can Scratch your Four of a Kind"<<endl;
            }
            //full house
            if((usedFull==0)&&((die1==die2&&die2==die3)&&(die4==die5))||((die1==die2&&die2==die4)&&(die3==die5))||
                    ((die1==die2&&die2==die5)&&(die3==die4))||((die1==die3&&die3==die4)&&(die2==die5))||
                    ((die1==die3&&die3==die5)&&(die2==die4))||((die1==die4&&die4==die5)&&(die2==die3))||
                    ((die2==die3&&die3==die4)&&(die1==die5))||((die2==die3&&die3==die5)&&(die1==die4))||
                    ((die2==die4&&die4==die5)&&(die1==die3))||((die3==die4&&die4==die5)&&(die1==die2))){
                cout<<"9)You have a full house:         25"<<endl;
            }
            else if(usedFull==0){
                cout<<"9)You can Scratch your Full House"<<endl;
            }
            //Small straight
            if((usedSS==0)&&isSS(die1,die2,die3,die4,die5)==true){
                cout<<"10)You have a Small Straight:    30"<<endl;
            }
            else if(usedSS==0){
                cout<<"10)You can Scratch your Small Straight"<<endl;
            }
            //Large straight
            if((usedLS==00)&&isLS(die1,die2,die3,die4,die5)==true){
                cout<<"11)You have a Large Straight:    40"<<endl;
            }
            else if(usedLS==0){
                cout<<"11)You can Scratch your Large Straight"<<endl;
            }
            //Yahtzee
            if((usedYahtzee==0)&&(die1==die2&&die2==die3&&die3==die4&&die4==die5)){
                cout<<"12)Yahtzee!                         100"<<endl;
            }
            else if((usedYahtzee==1)&&(die1==die2&&die2==die3&&die3==die4&&die4==die5)){
                cout<<"12)You have already used your Yahtzee!"<<endl;
            }
            else if (usedYahtzee==0){
                cout<<"12)You can Scratch Yahtzee"<<endl;
            }
            //Chance
            if(usedChance==0){
                cout<<"13)Chance:                       "<<(die1+die2+die3+die4+die5)<<endl;
            }

            //Data Validation for selection of how to score
            cout<<"Enter the number of the category to be scored"<<endl;
            cin>>pSel;

            switch(pSel){
                case 1:{
                    //check to see if the user has not used category
                    if(usedAces==0){
                        SS1=totAces(die1,die2,die3,die4,die5);
                        cout<<"You used your 1s! "<<SS1<<" Points!"<<endl;
                        okScore=1;
                        usedAces=1;
                        break;
                    }
                    //give error if they haven't
                    else{
                        cout<<"You have already used that category!"<<endl;
                        break;
                    }
                }
                case 2:{
                    //check to see if the user has not used category
                    if(usedTwos==0){
                        SS2=totTwos(die1,die2,die3,die4,die5);
                        cout<<"You used your 2s! "<<SS2<<" Points!"<<endl;
                        okScore=1;
                        usedTwos=1;
                        break;
                    }
                    //give error if they haven't
                    else{
                        cout<<"You have already used that category!"<<endl;
                        break;
                    }
                }
                case 3:{
                    //check to see if the user has not used category
                    if(usedThrees==0){
                        SS3=totThrees(die1,die2,die3,die4,die5);
                        cout<<"You used your 3s! "<<SS3<<" Points!"<<endl;
                        okScore=1;
                        usedThrees=1;
                        break;
                    }
                    //give error if they haven't
                    else{
                        cout<<"You have already used that category!"<<endl;
                        break;
                    }
                }
                case 4:{
                    //check to see if the user has not used category
                    if(usedFours==0){
                        SS4=totFours(die1,die2,die3,die4,die5);
                        cout<<"You used your 4s! "<<SS4<<" Points!"<<endl;
                        okScore=1;
                        usedFours=1;
                        break;
                    }
                    //give error if they haven't
                    else{
                        cout<<"You have already used that category!"<<endl;
                        break;
                    }
                }
                case 5:{
                    //check to see if the user has not used category
                    if(usedFives==0){
                        SS5=totFives(die1,die2,die3,die4,die5);
                        cout<<"You used your 5s! "<<SS5<<" Points!"<<endl;
                        okScore=1;
                        usedFives=1;
                        break;
                    }
                    //give error if they haven't
                    else{
                        cout<<"You have already used that category!"<<endl;
                        break;
                    }
                }
                case 6:{
                    //check to see if the user has not used category
                    if(usedSixes==0){
                        SS6=totSixes(die1,die2,die3,die4,die5);
                        cout<<"You used your 6s! "<<SS6<<" Points!"<<endl;
                        okScore=1;
                        usedSixes=1;
                        break;
                    }
                    //give error if they haven't
                    else{
                        cout<<"You have already used that category!"<<endl;
                        break;
                    }
                }
                case 7:{
                    //if user meets critera
                    if((used3Kind==0)&&(die1==die2&&die2==die3)||
                            (die1==die2&&die2==die4)||(die1==die2&&die2==die5)||
                            (die1==die3&&die3==die4)||(die1==die3&&die3==die5)||
                            (die1==die4&&die4==die5)||(die2==die3&&die3==die4)||
                            (die2==die3&&die4==die5)||(die2==die3&&die3==die5)||
                            (die3==die4&&die4==die5)){
                        SS7=(die1+die2+die3+die4+die5);
                        cout<<"You used your 3 of a Kind! "<<SS7<<" Points!"<<endl;
                        okScore=1;
                        used3Kind=1;
                        break;
                    }
                    //for a scratch
                    else if(used3Kind==0){
                        cout<<"You have scratched your 3 of a kind!"<<endl;
                        SS7=0;
                        okScore=1;
                        used3Kind=1;
                        break;
                    }
                    else{
                        cout<<"You have already used that category!"<<endl;
                        break;
                    }
                }
                case 8:{
                    if((used4Kind==0)&&(die1==die2&&die2==die3&&die3==die4)||
                            (die1==die3&&die3==die4&&die4==die5)||
                            (die1==die2&&die2==die3&&die3==die5)||
                            (die1==die2&&die2==die4&&die4==die5)||
                            (die2==die3&&die3==die4&&die4==die5)){
                        SS8=(die1+die2+die3+die4+die5);
                        cout<<"You used your 4 of a Kind! "<<SS8<<" Points!"<<endl;
                        okScore=1;
                        used4Kind=1;
                        break;
                    }
                    else if(used4Kind==0){
                        cout<<"You have scratched your 4 of a kind!"<<endl;
                        SS8=0;
                        okScore=1;
                        used4Kind=1;
                        break;
                    }
                    else{
                        cout<<"You have already used that category!"<<endl;
                        break;
                    }
                }
                case 9:{
                    if((usedFull==0)&&((die1==die2&&die2==die3)&&(die4==die5))||
                            ((die1==die2&&die2==die4)&&(die3==die5))||
                            ((die1==die2&&die2==die5)&&(die3==die4))||
                            ((die1==die3&&die3==die4)&&(die2==die5))||
                            ((die1==die3&&die3==die5)&&(die2==die4))||
                            ((die1==die4&&die4==die5)&&(die2==die3))||
                            ((die2==die3&&die3==die4)&&(die1==die5))||
                            ((die2==die3&&die3==die5)&&(die1==die4))||
                            ((die2==die4&&die4==die5)&&(die1==die3))||
                            ((die3==die4&&die4==die5)&&(die1==die2))){
                        SS9=25;
                        cout<<"You used your Full House! "<<SS9<<" Points!"<<endl;
                        okScore=1;
                        usedFull=1;
                        break;
                    }
                    else if(usedFull==0){
                        cout<<"You have scratched your Full House!"<<endl;
                        SS9=0;
                        okScore=1;
                        usedFull=1;
                        break;
                    }
                    else{
                        cout<<"You have already used that category!"<<endl;
                        break;
                    }
                }
                case 10:{
                    if((usedSS==0)&&isSS(die1,die2,die3,die4,die5)==true){
                        SS10=30;
                        cout<<"You used your Small Straight! "<<SS10<<" Points!"<<endl;
                        okScore=1;
                        usedSS=1;
                        break;
                    }
                    else if(usedSS==0){
                        cout<<"You have scratched your Small Straight!"<<endl;
                        SS10=0;
                        okScore=1;
                        usedSS=1;
                        break;
                    }
                    else{
                        cout<<"You have already used that category!"<<endl;
                        break;
                    }
                }
                case 11:{
                    if((usedLS==0)&&isLS(die1,die2,die3,die4,die5)==true){
                        SS11=40;
                        cout<<"You used your Large Straight! "<<SS11<<" Points!"<<endl;
                        okScore=1;
                        usedLS=1;
                        break;
                    }
                    else if(usedLS==0){
                        cout<<"You have scratched your Large Straight!"<<endl;
                        SS11=0;
                        okScore=1;
                        usedLS=1;
                        break;
                    }
                    else{
                        cout<<"You have already used that category!"<<endl;
                        break;
                    }
                }
                case 12:{
                    if((usedYahtzee==0)&&(die1==die2&&die2==die3&&die3==die4&&die4==die5)){
                        SS12=50;
                        cout<<"You scored a Yahtzee! "<<SS12<<" Points!"<<endl;
                        okScore=1;
                        usedYahtzee=1;
                        break;
                    }
                    else if(usedYahtzee==0){
                        cout<<"You have scratched your Yahtzee!"<<endl;
                        SS12=0;
                        okScore=1;
                        usedYahtzee=1;
                        break;
                    }
                    else{
                        cout<<"You have already used that category!"<<endl;
                        break;
                    }
                }
                case 13:{
                    if(usedChance==0){
                        SS13=(die1+die2+die3+die4+die5);
                        cout<<"You used your Chance! "<<SS13<<" Points!"<<endl;
                        okScore=1;
                        usedChance=1;
                        break;
                    }
                    else{
                        cout<<"You have already used that category!"<<endl;
                        break;
                    }
                }
                default:{
                    cout<<"Invalid Input, try again!"<<endl;
                    break;
                }
            }
            //check to see if the loop should be broken out of or not
            if(okScore==true)break;

        }while(true);
        cout<<"Press enter to continue."<<endl;
        cin.get();
        cin.ignore();
    }
    //output all of the data
    fileOut(SS1,SS2,SS3,SS4,SS5,SS6,SS7,SS8,SS9,SS10,SS11,SS12,SS13);
    return 0;
}

//roll function
unsigned short roll(){
    //set the random number seed,  give random die
    unsigned short value=rand()%6+1;//[1,6]
    return value;
}
//figuring out the number of dice
int number_of_dice(int number){
    int diceNumber=1;
    while(number/=10){
        diceNumber++;
    }
    return diceNumber;
}

bool isValid(int vNum, unsigned int vdNum){
    bool isOkay=0;
    
    //usage of switch statement to validate the user code inputed
    switch(vdNum){
        case 1:{
            isOkay=isValid1(vNum);
            return isOkay;
            break;
        }
        case 2:{
            isOkay=isValid2(vNum);
            return isOkay;
            break;
        }
        case 3:{
            isOkay=isValid3(vNum);
            return isOkay;
            break;
        }
        case 4:{
            isOkay=isValid4(vNum);
            return isOkay;
            break;
        }
        case 5:{
            isOkay=isValid5(vNum);
            return isOkay;
            break;
        }
        default:{
            return isOkay;
        }
    }
}
//make sure an input of 1 digit is valid
bool isValid1(int userIn){
    //local variables
    int choice1=userIn;
    
    //return true if everything is valid
    if(choice1<6&&choice1>0){
        return true;
    }
    else{
        return false;
    }
}

//make sure an input of 2 digits is valid
bool isValid2(int userIn){
    //local variables
    int choice1=0;
    int choice2=0;
    
    //checking each digit to make sure it is not greater than 5
    choice2=(userIn-userIn%10)/10;        //number in the 10s
    choice1=(userIn-choice2*10);
    
    //return true if everything is valid
    if((choice2<6&&choice2>0)&&(choice1<6&&choice1>0)){
        return true;
    }
    else{
        return false;
    }
}

//make sure an input of 3 digits is valid
bool isValid3(int userIn){
    //local variables
    int choice1=0;
    int choice2=0;
    int choice3=0;
    
    //checking each digit to make sure it is not greater than 5
    choice3=(userIn-userIn%100)/100;      //number in the 100s place
    userIn=(userIn-choice3*100);          //subtracting off the 100s
    choice2=(userIn-userIn%10)/10;        //number in the 10s
    choice1=(userIn-choice2*10);
    
    //return true if everything is valid
    if((choice3<6&&choice3>0)&&(choice2<6&&choice2>0)&&(choice1<6&&choice1>0)){
        return true;
    }
    else{
        return false;
    }
}

//make sure an input of 4 digits is valid
bool isValid4(int userIn){
    //local variables
    int choice1=0;
    int choice2=0;
    int choice3=0;
    int choice4=0;
    
    //checking each digit to make sure it is not greater than 5
    choice4=(userIn-userIn%1000)/1000;    //number of 1000s
    userIn=(userIn-choice4*1000);         //subtracting off 1000s
    choice3=(userIn-userIn%100)/100;      //number in the 100s place
    userIn=(userIn-choice3*100);          //subtracting off the 100s
    choice2=(userIn-userIn%10)/10;        //number in the 10s
    choice1=(userIn-choice2*10);
    
    //return true if everything is valid
    if((choice4<6&&choice4>0)&&(choice3<6&&choice3>0)&&(choice2<6&&choice2>0)&&(choice1<6&&choice1>0)){
        return true;
    }
    else{
        return false;
    }
}

//make sure an input of 5 digit is valid
bool isValid5(int userIn){
    
    //local variables
    int choice1=0;
    int choice2=0;
    int choice3=0;
    int choice4=0;
    int choice5=0;
    
    //checking each digit to make sure it is not greater than 5
    choice5=(userIn-userIn%10000)/10000;  //number in 10000 place
    userIn=(userIn-choice5*10000);        //subtracting off 10000s
    choice4=(userIn-userIn%1000)/1000;    //number of 1000s
    userIn=(userIn-choice4*1000);         //subtracting off 1000s
    choice3=(userIn-userIn%100)/100;      //number in the 100s place
    userIn=(userIn-choice3*100);          //subtracting off the 100s
    choice2=(userIn-userIn%10)/10;        //number in the 10s
    choice1=(userIn-choice2*10);
    
    //return true if everything is valid
    if((choice5<6&&choice5>0)&&(choice4<6&&choice4>0)&&(choice3<6&&choice3>0)&&(choice2<6&&choice2>0)&&(choice1<6&&choice1>0)){
        return true;
    }
    else{
        return false;
    }
}
//get the total of all the dice if they are 1s
unsigned int totAces(unsigned short o1,unsigned short o2,unsigned short o3,unsigned short o4,unsigned short o5){
    unsigned int total=0;
    
    //total each if they are equal to 1
    if(o1==1)total+=1;
    if(o2==1)total+=1;
    if(o3==1)total+=1;
    if(o4==1)total+=1;
    if(o5==1)total+=1;
    
    return total;
}

//get the total of all the dice if they are 2s
unsigned int totTwos(unsigned short o1,unsigned short o2,unsigned short o3,unsigned short o4,unsigned short o5){
    unsigned int total=0;
    
    //total each if they are equal to 2
    if(o1==2)total+=2;
    if(o2==2)total+=2;
    if(o3==2)total+=2;
    if(o4==2)total+=2;
    if(o5==2)total+=2;
    
    return total;
}

//get the total of all the dice if they are 3s
unsigned int totThrees(unsigned short o1,unsigned short o2,unsigned short o3,unsigned short o4,unsigned short o5){
    unsigned int total=0;
    
    //total each if they are equal to 3
    if(o1==3)total+=3;
    if(o2==3)total+=3;
    if(o3==3)total+=3;
    if(o4==3)total+=3;
    if(o5==3)total+=3;
    
    return total;
}

//get the total of all the dice if they are 4s
unsigned int totFours(unsigned short o1,unsigned short o2,unsigned short o3,unsigned short o4,unsigned short o5){
    unsigned int total=0;
    
    //total each if they are equal to 4
    if(o1==4)total+=4;
    if(o2==4)total+=4;
    if(o3==4)total+=4;
    if(o4==4)total+=4;
    if(o5==4)total+=4;
    
    return total;
}

//get the total of all the dice if they are fives
unsigned int totFives(unsigned short o1,unsigned short o2,unsigned short o3,unsigned short o4,unsigned short o5){
    unsigned int total=0;
    
    //total each if they are equal to 4
    if(o1==5)total+=5;
    if(o2==5)total+=5;
    if(o3==5)total+=5;
    if(o4==5)total+=5;
    if(o5==5)total+=5;
    
    return total;
}
unsigned int totSixes(unsigned short o1,unsigned short o2,unsigned short o3,unsigned short o4,unsigned short o5){
    unsigned int total=0;
    
    //total each if they are equal to 5
    if(o1==6)total+=6;
    if(o2==6)total+=6;
    if(o3==6)total+=6;
    if(o4==6)total+=6;
    if(o5==6)total+=6;
    
    return total;
}
//figuring out if there is a small straight
bool isSS(unsigned short o1,unsigned short o2,unsigned short o3,unsigned short o4,unsigned short o5){
    int start=findSmallest(o1,o2,o3,o4,o5);
    int temp=start;
    
    //see if any numbers match the sequence need to for small straight
    if((((temp+1)==o1)||((temp+1)==o2)||((temp+1)==o3)||((temp+1)==o4)||((temp+1)==o5))&&
            (((temp+2)==o1)||((temp+2)==o2)||((temp+2)==o3)||((temp+2)==o4)||((temp+2)==o5))&&
            (((temp+3)==o1)||((temp+3)==o2)||((temp+3)==o3)||((temp+3)==o4)||((temp+3)==o5))){
        return true;
    }
    else if((((temp+2)==o1)||((temp+2)==o2)||((temp+2)==o3)||((temp+2)==o4)||((temp+2)==o5))&&
            (((temp+3)==o1)||((temp+3)==o2)||((temp+3)==o3)||((temp+3)==o4)||((temp+3)==o5))&&
            (((temp+4)==o1)||((temp+4)==o2)||((temp+4)==o3)||((temp+4)==o4)||((temp+4)==o5))){
        return true;
    }
    else{
        return false;
    }
}
//figuring out if there is a large straight
bool isLS(unsigned short o1,unsigned short o2,unsigned short o3,unsigned short o4,unsigned short o5){
    int start=findSmallest(o1,o2,o3,o4,o5);
    int temp=start;
    
    if((((temp+1)==o1)||((temp+1)==o2)||((temp+1)==o3)||((temp+1)==o4)||((temp+1)==o5))&&
            (((temp+2)==o1)||((temp+2)==o2)||((temp+2)==o3)||((temp+2)==o4)||((temp+2)==o5))&&
            (((temp+3)==o1)||((temp+3)==o2)||((temp+3)==o3)||((temp+3)==o4)||((temp+3)==o5))&&
            (((temp+4)==o1)||((temp+4)==o2)||((temp+4)==o3)||((temp+4)==o4)||((temp+4)==o5))){
        return true;
    }
    else{
        return false;
    }
}
//find the smallest, used as the starting point for the isSS and isLS functions
unsigned short findSmallest(unsigned short s1,unsigned short s2,unsigned short s3,unsigned short s4,unsigned short s5){
    //assign smallest value to first number
    unsigned short smallest=s1;
    
    //check to see if any of the numbers are smaller
    if(s2<smallest)smallest=s2;
    if(s3<smallest)smallest=s3;
    if(s4<smallest)smallest=s4;
    if(s5<smallest)smallest=s5;
    
    //return the smallest of all of them
    return smallest;
}
void fileOut(int score1, int score2, int score3, int score4, int score5,
        int score6, int score7, int score8, int score9, int score10,
        int score11, int score12, int score13){
    int uTotal=0,uBonus=0,lTotal=0,oTotal=0;
    ofstream out;
    //get totals
    uTotal=score1+score2+score3+score4+score5+score6;
    lTotal=score7+score8+score9+score10+score11+score12+score13;
    oTotal=uTotal+lTotal;
    
    //see if user got bonus
    if(uTotal>=63){
        uBonus=36;
        oTotal+=uBonus;
    }
    
    //output results to a file and normally
    cout<<"Upper Section\n"<<endl;
    cout<<"Aces:            "<<score1<<endl;
    cout<<"Twos:            "<<score2<<endl;
    cout<<"Threes:          "<<score3<<endl;
    cout<<"Fours:           "<<score4<<endl;
    cout<<"Fives:           "<<score5<<endl;
    cout<<"Sixes:           "<<score6<<endl;
    cout<<"Upper Total:     "<<uTotal<<endl;
    cout<<"Bonus:           "<<uBonus<<"\n"<<endl;
    cout<<"Lower Section\n"<<endl;
    cout<<"3 of a Kind:     "<<score7<<endl;
    cout<<"4 of a Kind:     "<<score8<<endl;
    cout<<"Full House:      "<<score9<<endl;
    cout<<"Small Straight:  "<<score10<<endl;
    cout<<"Large Straight:  "<<score11<<endl;
    cout<<"Yahtzee:         "<<score12<<endl;
    cout<<"Chance:          "<<score13<<"\n"<<endl;
    cout<<"Lower Total:     "<<lTotal<<"\n"<<endl;
    cout<<"Score:           "<<oTotal<<"\n"<<endl;
    
    //to a file
    out.open("Yahtzee.dat");
    out<<"Upper Section\r\n\r\n"<<endl;
    out<<"Aces:             "<<score1<<"\r\n"<<endl;
    out<<"Twos:             "<<score2<<"\r\n"<<endl;
    out<<"Threes:           "<<score3<<"\r\n"<<endl;
    out<<"Fours:            "<<score4<<"\r\n"<<endl;
    out<<"Fives:            "<<score5<<"\r\n"<<endl;
    out<<"Sixes:            "<<score6<<"\r\n"<<endl;
    out<<"Upper Total:      "<<uTotal<<"\r\n"<<endl;
    out<<"Bonus:            "<<uBonus<<"\r\n\r\n"<<endl;
    out<<"Lower Section\r\n\r\n"<<endl;
    out<<"3 of a Kind:      "<<score7<<"\r\n"<<endl;
    out<<"4 of a Kind:      "<<score8<<"\r\n"<<endl;
    out<<"Full House:       "<<score9<<"\r\n"<<endl;
    out<<"Small Straight:   "<<score10<<"\r\n"<<endl;
    out<<"Large Straight:   "<<score11<<"\r\n"<<endl;
    out<<"Yahtzee:          "<<score12<<"\r\n"<<endl;
    out<<"Chance:           "<<score13<<"\r\n\r\n"<<endl;
    out<<"Lower Total:      "<<lTotal<<"\r\n\r\n"<<endl;
    out<<"Score:            "<<oTotal<<"\r\n"<<endl;
    out.close();
    
}