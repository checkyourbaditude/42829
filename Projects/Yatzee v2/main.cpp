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
void finishTurn(unsigned short d1,unsigned short d2,unsigned short d3,unsigned short d4,unsigned short d5);
unsigned int totAces(unsigned short o1,unsigned short o2,unsigned short o3,unsigned short o4,unsigned short o5);
unsigned int totTwos(unsigned short o1,unsigned short o2,unsigned short o3,unsigned short o4,unsigned short o5);
unsigned int totThrees(unsigned short o1,unsigned short o2,unsigned short o3,unsigned short o4,unsigned short o5);
unsigned int totFours(unsigned short o1,unsigned short o2,unsigned short o3,unsigned short o4,unsigned short o5);
unsigned int totFives(unsigned short o1,unsigned short o2,unsigned short o3,unsigned short o4,unsigned short o5);
unsigned int totSixes(unsigned short o1,unsigned short o2,unsigned short o3,unsigned short o4,unsigned short o5);
bool isSS(unsigned short o1,unsigned short o2,unsigned short o3,unsigned short o4,unsigned short o5);
bool isLS(unsigned short o1,unsigned short o2,unsigned short o3,unsigned short o4,unsigned short o5);
unsigned short findSmallest(unsigned short s1,unsigned short s2,unsigned short s3,unsigned short s4,unsigned short s5);
bool isExists(unsigned int check);

int main(int argc, char** argv) {
    //Set the random number seed for variability
    srand(static_cast<unsigned int>(time(NULL)));
    
    //greeting
    cout<<"Lets Play Yatzee!"<<endl;
    cout<<"Rules:"<<endl;
    cout<<"You must enter the  sequential code corrisponding to the dice"<<endl;
    cout<<"you would like to keep.\nEnter a zero if you would like to ";
    cout<<"roll all of the dice again."<<endl;
    cout<<"Sequences with zeros are not allowed."<<endl;
    cout<<"For Example: 325 is valid, however 2035 is not.\n"<<endl;
    cout<<"Here is the first roll!"<<endl;
    
    //variables
    unsigned int uSel=0;
    bool is1to5=0;
    unsigned int nDice=0;
    int nKeep=0;
    
    //upper section
    bool usedAces=0;
    bool usedTwos=0;
    bool usedThrees=0;
    bool usedFours=0;
    bool usedFives=0;
    bool usedSixes=0;
    
    //lower section
    bool used3Kind=0;
    bool used4Kind=0;
    bool usedFull=0;
    bool usedSS=0;
    bool usedLS=0;
    bool usedYahtzee=0;
    bool usedChance=0;
    /*
    unsigned short die1=4;//[1,6]
    unsigned short die2=6;//[1,6]
    unsigned short die3=3;//[1,6]
    unsigned short die4=1;//[1,6]
    unsigned short die5=5;//[1,6]
    //first dice throw
    */

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
        //data validation, make sure all digits are between 1 and 5
        //make sure no numbers greater than 5 are entered
        do{
            //ask user what they would like to keep
            cout<<"Enter the numbers of the dice you would like to keep!"<<endl;
            cout<<"If you would like to keep nothing, just press zero (0)"<<endl;
            cout<<"All digits must be between 0 and 5"<<endl;
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
        cout<<"The number of dice chosen is:"<<nDice<<endl;

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
                    cout<<"You have kept dice number 1"<<endl;

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
                    cout<<"You have kept dice number 1"<<endl;

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
        //output all of the dice
        cout<<"Dice 1:"<<die1<<endl;
        cout<<"Dice 2:"<<die2<<endl;
        cout<<"Dice 3:"<<die3<<endl;
        cout<<"Dice 4:"<<die4<<endl;
        cout<<"Dice 5:"<<die5<<endl;
    }
    
    //begin grading
    cout<<"Lets grade your hand!"<<endl;
    
    cout<<"enter the number for the way you want your hand to be graded"<<endl;
    
    //for the upper section, give user totals to decide what their best move is
    if(die1==1||die2==1||die3==1||die4==1||die5==1){
        cout<<"1)The total of your aces is:     "<<totAces(die1,die2,die3,die4,die5)<<endl;
    }
    if(die1==2||die2==2||die3==2||die4==2||die5==2){
        cout<<"2)The total of your twos is:     "<<totTwos(die1,die2,die3,die4,die5)<<endl;
    }
    if(die1==3||die2==3||die3==3||die4==3||die5==3){
        cout<<"3)The total of your threes is:   "<<totThrees(die1,die2,die3,die4,die5)<<endl;
    }
    if(die1==4||die2==4||die3==4||die4==4||die5==4){
        cout<<"4)The total of your fours is:    "<<totFours(die1,die2,die3,die4,die5)<<endl;
    }
    if(die1==5||die2==5||die3==5||die4==5||die5==5){
        cout<<"5)The total of your fives is:    "<<totFives(die1,die2,die3,die4,die5)<<endl;
    }
    if(die1==6||die2==6||die3==6||die4==6||die5==6){
        cout<<"6)The total of your Sixes is:    "<<totSixes(die1,die2,die3,die4,die5)<<endl;
    }
    
    //for the lower section
    //three of a kind
    if((die1==die2&&die2==die3)||(die1==die2&&die2==die4)||(die1==die2&&die2==die5)||(die1==die3&&die3==die4)||
            (die1==die3&&die3==die5)||(die1==die4&&die4==die5)||(die2==die3&&die3==die4)||
            (die2==die3&&die4==die5)||(die2==die3&&die3==die5)||(die3==die4&&die4==die5)){
        cout<<"7)You have a three of a kind:    "<<(die1+die2+die3+die4+die5)<<endl;
    }
    //four of a kind
    if((die1==die2&&die2==die3&&die3==die4)||(die1==die3&&die3==die4&&die4==die5)||(die1==die2&&die2==die3&&die3==die5)||
            (die1==die2&&die2==die4&&die4==die5)||(die2==die3&&die3==die4&&die4==die5)){
        cout<<"8)You have a four of a kind:     "<<(die1+die2+die3+die4+die5)<<endl;
    }
    //full house
    if(((die1==die2&&die2==die3)&&(die4==die5))||((die1==die2&&die2==die4)&&(die3==die5))||
            ((die1==die2&&die2==die5)&&(die3==die4))||((die1==die3&&die3==die4)&&(die2==die5))||
            ((die1==die3&&die3==die5)&&(die2==die4))||((die1==die4&&die4==die5)&&(die2==die3))||
            ((die2==die3&&die3==die4)&&(die1==die5))||((die2==die3&&die3==die5)&&(die1==die4))||
            ((die2==die4&&die4==die5)&&(die1==die3))||((die3==die4&&die4==die5)&&(die1==die2))){
        cout<<"9)You have a full house:         25"<<endl;
    }
    //Small straight
    if(isSS(die1,die2,die3,die4,die5)==true){
        cout<<"10)You have a Small Straight:    30"<<endl;
    }
    //Large straight
    if(isLS(die1,die2,die3,die4,die5)==true){
        cout<<"10)You have a Large Straight:    40"<<endl;
    }
    //Yahtzee
    if(die1==die2&&die2==die3&&die3==die4&&die4==die5){
        cout<<"11)Yahtzee!                         100"<<endl;
    }
    //Chance
    cout<<"12)Chance:                       "<<(die1+die2+die3+die4+die5)<<endl;
    //finishTurn(die1,die2,die3,die4,die5);
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
    int choice1=0;
    
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

//this is where the grading process begins
/*void finishTurn(unsigned short d1,unsigned short d2,unsigned short d3,unsigned short d4,unsigned short d5){
    //use booleans to not allow user to grade the same thing multiple times
    cout<<"Lets grade your hand!"<<endl;
    
    unsigned int uSel=0;
    
    //upper section
    bool usedAces;
    bool usedTwos;
    bool usedThrees;
    bool usedFours;
    bool usedFives;
    bool usedSixes;
    
    //lower section
    bool used3Kind;
    bool used4Kind;
    bool usedFull;
    bool usedSS;
    bool usedLS;
    bool usedYahtzee;
    bool usedChance;
    
    //give total for the numbers given
    
    cout<<"enter the number for the way you want your hand to be graded"<<endl;
    
    //for the upper section, give user totals to decide what their best move is
    if(d1==1||d2==1||d3==1||d4==1||d5==1){
        cout<<"1)The total of your aces is:     "<<totAces(d1,d2,d3,d4,d5)<<endl;
    }
    if(d1==2||d2==2||d3==2||d4==2||d5==2){
        cout<<"2)The total of your twos is:     "<<totTwos(d1,d2,d3,d4,d5)<<endl;
    }
    if(d1==3||d2==3||d3==3||d4==3||d5==3){
        cout<<"3)The total of your threes is:   "<<totThrees(d1,d2,d3,d4,d5)<<endl;
    }
    if(d1==4||d2==4||d3==4||d4==4||d5==4){
        cout<<"4)The total of your fours is:    "<<totFours(d1,d2,d3,d4,d5)<<endl;
    }
    if(d1==5||d2==5||d3==5||d4==5||d5==5){
        cout<<"5)The total of your fives is:    "<<totFives(d1,d2,d3,d4,d5)<<endl;
    }
    if(d1==6||d2==6||d3==6||d4==6||d5==6){
        cout<<"6)The total of your Sixes is:    "<<totSixes(d1,d2,d3,d4,d5)<<endl;
    }
    
    //for the lower section
    //three of a kind
    if((d1==d2&&d2==d3)||(d1==d2&&d2==d4)||(d1==d2&&d2==d5)||(d1==d3&&d3==d4)||
            (d1==d3&&d3==d5)||(d1==d4&&d4==d5)||(d2==d3&&d3==d4)||
            (d2==d4&&d4==d5)||(d2==d3&&d3==d5)||(d3==d4&&d4==d5)){
        cout<<"7)You have a three of a kind:    "<<(d1+d2+d3+d4+d5)<<endl;
    }
    //four of a kind
    if((d1==d2&&d2==d3&&d3==d4)||(d1==d3&&d3==d4&&d4==d5)||(d1==d2&&d2==d3&&d3==d5)||
            (d1==d2&&d2==d4&&d4==d5)||(d2==d3&&d3==d4&&d4==d5)){
        cout<<"8)You have a four of a kind:     "<<(d1+d2+d3+d4+d5)<<endl;
    }
    //full house
    if(((d1==d2&&d2==d3)&&(d4==d5))||((d1==d2&&d2==d4)&&(d3==d5))||
            ((d1==d2&&d2==d5)&&(d3==d4))||((d1==d3&&d3==d4)&&(d2==5))||
            ((d1==d3&&d3==d5)&&(d2==d4))||((d1==d4&&d4==d5)&&(d2==d3))||
            ((d2==d3&&d3==d4)&&(d1==d5))||((d2==d3&&d3==d5)&&(d1==d4))||
            ((d2==d4&&d4==d5)&&(d1==d3))||((d3==d4&&d4==d5)&&(d1==d2))){
        cout<<"9)You have a full house:         25"<<endl;
    }
    //Small straight
    if(isSS(d1,d2,d3,d4,d5)==true){
        cout<<"10)You have a Small Straight:    30"<<endl;
    }
    //Large straight
    if(isLS(d1,d2,d3,d4,d5)==true){
        cout<<"10)You have a Large Straight:    40"<<endl;
    }
    //Yahtzee
    if(d1==d2&&d2==d3&&d3==d4&&d4==d5){
        cout<<"Yahtzee!                         100"<<endl;
    }
    //Chance
    cout<<"Dice 1:"<<d1<<endl;
    cout<<"Dice 2:"<<d2<<endl;
    cout<<"Dice 3:"<<d3<<endl;
    cout<<"Dice 4:"<<d4<<endl;
    cout<<"Dice 5:"<<d5<<endl;
}
*/
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
bool isExists(unsigned int check){
    
}