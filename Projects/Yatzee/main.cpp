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

int main(int argc, char** argv) {
    //Set the random number seed for variability
    srand(static_cast<unsigned int>(time(NULL)));
    
    //greeting
    cout<<"Lets Play Yatzee!"<<endl;
    cout<<"Here is the first roll!"<<endl;
    
    //variables
    bool is1to5=0;
    unsigned int nDice=0;
    int nKeep=0;
    
    //first dice throw
    unsigned short die1=roll();//[1,6]
    unsigned short die2=roll();//[1,6]
    unsigned short die3=roll();//[1,6]
    unsigned short die4=roll();//[1,6]
    unsigned short die5=roll();//[1,6]

    //initiate a turn
    for(int i=1;i<=3;i++){
        //output the results
        cout<<"Dice 1:"<<die1<<endl;
        cout<<"Dice 2:"<<die2<<endl;
        cout<<"Dice 3:"<<die3<<endl;
        cout<<"Dice 4:"<<die4<<endl;
        cout<<"Dice 5:"<<die5<<endl;

        //data validation, make sure all digits are between 1 and 5
        //make sure no numbers greater than 5 are entered
        do{
            //ask user what they would like to keep
            cout<<"Enter the numbers of the dice you would like to keep!"<<endl;
            cout<<"If you would like to keep nothing, just press zero (0)"<<endl;
            cout<<"All digits must be between 0 and 5"<<endl;
            cin>>nKeep;

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
                    unsigned short die2=roll();//[1,6]
                    unsigned short die3=roll();//[1,6]
                    unsigned short die4=roll();//[1,6]
                    unsigned short die5=roll();//[1,6]

                    //output the dice that were rolled
                    cout<<"Dice 2:"<<die2<<endl;
                    cout<<"Dice 3:"<<die3<<endl;
                    cout<<"Dice 4:"<<die4<<endl;
                    cout<<"Dice 5:"<<die5<<endl;
                    break;
                }
                if(nKeep==2){
                    cout<<"You have kept dice number 2"<<endl;

                    //call the dice that were not kept to be rolled
                    unsigned short die1=roll();//[1,6]
                    unsigned short die3=roll();//[1,6]
                    unsigned short die4=roll();//[1,6]
                    unsigned short die5=roll();//[1,6]

                    //output the dice that were rolled
                    cout<<"Dice 1:"<<die1<<endl;
                    cout<<"Dice 3:"<<die3<<endl;
                    cout<<"Dice 4:"<<die4<<endl;
                    cout<<"Dice 5:"<<die5<<endl;
                    break;
                }
                if(nKeep==3){
                    cout<<"You have kept dice number 3"<<endl;

                    //call the dice that were not kept to be rolled
                    unsigned short die1=roll();//[1,6]
                    unsigned short die2=roll();//[1,6]
                    unsigned short die4=roll();//[1,6]
                    unsigned short die5=roll();//[1,6]

                    //output the dice that were rolled
                    cout<<"Dice 1:"<<die1<<endl;
                    cout<<"Dice 2:"<<die2<<endl;
                    cout<<"Dice 4:"<<die4<<endl;
                    cout<<"Dice 5:"<<die5<<endl;
                    break;
                }
                if(nKeep==4){
                    cout<<"You have kept dice number 4"<<endl;

                    //call the dice that were not kept to be rolled
                    unsigned short die1=roll();//[1,6]
                    unsigned short die2=roll();//[1,6]
                    unsigned short die3=roll();//[1,6]
                    unsigned short die5=roll();//[1,6]

                    //output the dice that were rolled
                    cout<<"Dice 1:"<<die1<<endl;
                    cout<<"Dice 2:"<<die2<<endl;
                    cout<<"Dice 3:"<<die3<<endl;
                    cout<<"Dice 5:"<<die5<<endl;
                    break;
                }
                if(nKeep==5){
                    cout<<"You have kept dice number 5"<<endl;

                    //call the dice that were not kept to be rolled
                    unsigned short die1=roll();//[1,6]
                    unsigned short die2=roll();//[1,6]
                    unsigned short die3=roll();//[1,6]
                    unsigned short die4=roll();//[1,6]

                    //output the dice that were rolled
                    cout<<"Dice 1:"<<die1<<endl;
                    cout<<"Dice 2:"<<die2<<endl;
                    cout<<"Dice 3:"<<die3<<endl;
                    cout<<"Dice 4:"<<die4<<endl;
                    break;
                }
            }
            //if 2 dice is kept
            case 2:{
                if(nKeep==12){
                    cout<<"You have kept dice number 1 and 2"<<endl;

                    //call the dice that were not kept to be rolled
                    unsigned short die3=roll();//[1,6]
                    unsigned short die4=roll();//[1,6]
                    unsigned short die5=roll();//[1,6]

                    //output the dice that were rolled
                    cout<<"Dice 3:"<<die3<<endl;
                    cout<<"Dice 4:"<<die4<<endl;
                    cout<<"Dice 5:"<<die5<<endl;
                    break;
                }
                if(nKeep==13){
                    cout<<"You have kept dice number 1 and 3"<<endl;

                    //call the dice that were not kept to be rolled
                    unsigned short die2=roll();//[1,6]
                    unsigned short die4=roll();//[1,6]
                    unsigned short die5=roll();//[1,6]

                    //output the dice that were rolled
                    cout<<"Dice 2:"<<die2<<endl;
                    cout<<"Dice 4:"<<die4<<endl;
                    cout<<"Dice 5:"<<die5<<endl;
                    break;
                }
                if(nKeep==14){
                    cout<<"You have kept dice number 1 and 4"<<endl;

                    //call the dice that were not kept to be rolled
                    unsigned short die2=roll();//[1,6]
                    unsigned short die3=roll();//[1,6]
                    unsigned short die5=roll();//[1,6]

                    //output the dice that were rolled
                    cout<<"Dice 2:"<<die2<<endl;
                    cout<<"Dice 3:"<<die3<<endl;
                    cout<<"Dice 5:"<<die5<<endl;
                    break;
                }
                if(nKeep==15){
                    cout<<"You have kept dice number 1 and 5"<<endl;

                    //call the dice that were not kept to be rolled
                    unsigned short die2=roll();//[1,6]
                    unsigned short die3=roll();//[1,6]
                    unsigned short die4=roll();//[1,6]

                    //output the dice that were rolled
                    cout<<"Dice 2:"<<die2<<endl;
                    cout<<"Dice 3:"<<die3<<endl;
                    cout<<"Dice 4:"<<die4<<endl;
                    break;
                }
                if(nKeep==23){
                    cout<<"You have kept dice number 2 and 3"<<endl;

                    //call the dice that were not kept to be rolled
                    unsigned short die1=roll();//[1,6]
                    unsigned short die4=roll();//[1,6]
                    unsigned short die5=roll();//[1,6]

                    //output the dice that were rolled
                    cout<<"Dice 1:"<<die1<<endl;
                    cout<<"Dice 4:"<<die4<<endl;
                    cout<<"Dice 5:"<<die5<<endl;
                    break;
                }
                if(nKeep==24){
                    cout<<"You have kept dice number 2 and 4"<<endl;

                    //call the dice that were not kept to be rolled
                    unsigned short die1=roll();//[1,6]
                    unsigned short die3=roll();//[1,6]
                    unsigned short die5=roll();//[1,6]

                    //output the dice that were rolled
                    cout<<"Dice 1:"<<die1<<endl;
                    cout<<"Dice 3:"<<die3<<endl;
                    cout<<"Dice 5:"<<die5<<endl;
                    break;
                }
                if(nKeep==25){
                    cout<<"You have kept dice number 2 and 5"<<endl;

                    //call the dice that were not kept to be rolled
                    unsigned short die1=roll();//[1,6]
                    unsigned short die3=roll();//[1,6]
                    unsigned short die4=roll();//[1,6]

                    //output the dice that were rolled
                    cout<<"Dice 1:"<<die1<<endl;
                    cout<<"Dice 3:"<<die3<<endl;
                    cout<<"Dice 4:"<<die4<<endl;
                    break;
                }
                if(nKeep==34){
                    cout<<"You have kept dice number 3 and 4"<<endl;

                    //call the dice that were not kept to be rolled
                    unsigned short die1=roll();//[1,6]
                    unsigned short die2=roll();//[1,6]
                    unsigned short die5=roll();//[1,6]

                    //output the dice that were rolled
                    cout<<"Dice 1:"<<die1<<endl;
                    cout<<"Dice 2:"<<die2<<endl;
                    cout<<"Dice 5:"<<die5<<endl;
                    break;
                }
                if(nKeep==35){
                    cout<<"You have kept dice number 3 and 4"<<endl;

                    //call the dice that were not kept to be rolled
                    unsigned short die1=roll();//[1,6]
                    unsigned short die2=roll();//[1,6]
                    unsigned short die4=roll();//[1,6]

                    //output the dice that were rolled
                    cout<<"Dice 1:"<<die1<<endl;
                    cout<<"Dice 2:"<<die2<<endl;
                    cout<<"Dice 4:"<<die4<<endl;
                    break;
                }
                if(nKeep==45){
                    cout<<"You have kept dice number 4 and 5"<<endl;

                    //call the dice that were not kept to be rolled
                    unsigned short die1=roll();//[1,6]
                    unsigned short die2=roll();//[1,6]
                    unsigned short die3=roll();//[1,6]

                    //output the dice that were rolled
                    cout<<"Dice 1:"<<die1<<endl;
                    cout<<"Dice 2:"<<die2<<endl;
                    cout<<"Dice 3:"<<die3<<endl;
                    break;
                }
            }
            //if 3 dice is kept
            case 3:{
                if(nKeep==123){
                    cout<<"You have kept dice number 1, 2, and 3"<<endl;

                    //call the dice that were not kept to be rolled
                    unsigned short die4=roll();//[1,6]
                    unsigned short die5=roll();//[1,6]

                    //output the dice that were rolled
                    cout<<"Dice 4:"<<die4<<endl;
                    cout<<"Dice 5:"<<die5<<endl;
                    break;
                }
                if(nKeep==124){
                    cout<<"You have kept dice number 1, 2, and 4"<<endl;

                    //call the dice that were not kept to be rolled
                    unsigned short die3=roll();//[1,6]
                    unsigned short die5=roll();//[1,6]

                    //output the dice that were rolled
                    cout<<"Dice 3:"<<die3<<endl;
                    cout<<"Dice 5:"<<die5<<endl;
                    break;
                }
                if(nKeep==125){
                    cout<<"You have kept dice number 1, 2, and 5"<<endl;

                    //call the dice that were not kept to be rolled
                    unsigned short die3=roll();//[1,6]
                    unsigned short die4=roll();//[1,6]

                    //output the dice that were rolled
                    cout<<"Dice 3:"<<die3<<endl;
                    cout<<"Dice 4:"<<die4<<endl;
                    break;
                }
                if(nKeep==134){
                    cout<<"You have kept dice number 1, 3, and 4"<<endl;

                    //call the dice that were not kept to be rolled
                    unsigned short die2=roll();//[1,6]
                    unsigned short die5=roll();//[1,6]

                    //output the dice that were rolled
                    cout<<"Dice 2:"<<die2<<endl;
                    cout<<"Dice 5:"<<die5<<endl;
                    break;
                }
                if(nKeep==145){
                    cout<<"You have kept dice number 1, 4, and 5"<<endl;

                    //call the dice that were not kept to be rolled
                    unsigned short die2=roll();//[1,6]
                    unsigned short die3=roll();//[1,6]

                    //output the dice that were rolled
                    cout<<"Dice 2:"<<die2<<endl;
                    cout<<"Dice 3:"<<die3<<endl;
                    break;
                }
                if(nKeep==135){
                    cout<<"You have kept dice number 1, 3, and 5"<<endl;

                    //call the dice that were not kept to be rolled
                    unsigned short die2=roll();//[1,6]
                    unsigned short die4=roll();//[1,6]

                    //output the dice that were rolled
                    cout<<"Dice 2:"<<die2<<endl;
                    cout<<"Dice 4:"<<die4<<endl;
                    break;
                }
                if(nKeep==234){
                    cout<<"You have kept dice number 2, 3, and 4"<<endl;

                    //call the dice that were not kept to be rolled
                    unsigned short die1=roll();//[1,6]
                    unsigned short die5=roll();//[1,6]

                    //output the dice that were rolled
                    cout<<"Dice 1:"<<die1<<endl;
                    cout<<"Dice 5:"<<die5<<endl;
                    break;
                }
                if(nKeep==235){
                    cout<<"You have kept dice number 2, 3, and 5"<<endl;

                    //call the dice that were not kept to be rolled
                    unsigned short die1=roll();//[1,6]
                    unsigned short die4=roll();//[1,6]

                    //output the dice that were rolled
                    cout<<"Dice 1:"<<die1<<endl;
                    cout<<"Dice 4:"<<die4<<endl;
                    break;
                }
                if(nKeep==245){
                    cout<<"You have kept dice number 2, 4, and 5"<<endl;

                    //call the dice that were not kept to be rolled
                    unsigned short die1=roll();//[1,6]
                    unsigned short die3=roll();//[1,6]

                    //output the dice that were rolled
                    cout<<"Dice 1:"<<die1<<endl;
                    cout<<"Dice 3:"<<die3<<endl;
                    break;
                }
                if(nKeep==345){
                    cout<<"You have kept dice number 3, 4, and 5"<<endl;

                    //call the dice that were not kept to be rolled
                    unsigned short die1=roll();//[1,6]
                    unsigned short die2=roll();//[1,6]

                    //output the dice that were rolled
                    cout<<"Dice 1:"<<die1<<endl;
                    cout<<"Dice 2:"<<die2<<endl;
                    break;
                }
                break;
            }
            //if 4 dice is kept
            case 4:{
                if(nKeep==1234){
                    cout<<"You have kept dice number 1,2,3, and 4"<<endl;

                    //call the dice that need to be rolled
                    unsigned short die5=roll();//[1,6]

                    //output the dice that were rolled
                    cout<<"Dice 5:"<<die5<<endl;
                    break;
                }
                if(nKeep==1345){
                    cout<<"You have kept dice number 1,3,4, and 5"<<endl;

                    //call the dice that need to be rolled
                    unsigned short die2=roll();//[1,6]

                    //output the dice that were rolled
                    cout<<"Dice 2:"<<die2<<endl;
                    break;
                }
                if(nKeep==1235){
                    cout<<"You have kept dice number 1,2,3, and 5"<<endl;

                    //call the dice that need to be rolled
                    unsigned short die4=roll();//[1,6]

                    //output the dice that were rolled
                    cout<<"Dice 4:"<<die4<<endl;
                    break;
                }
                if(nKeep==1245){
                    cout<<"You have kept dice number 1"<<endl;

                    //call the dice that need to be rolled
                    unsigned short die3=roll();//[1,6]

                    //output the dice that were rolled
                    cout<<"Dice 3:"<<die3<<endl;
                    break;
                }
                if(nKeep==2345){
                    cout<<"You have kept dice number 1"<<endl;

                    //call the dice that need to be rolled
                    unsigned short die1=roll();//[1,6]

                    //output the dice that were rolled
                    cout<<"Dice 1:"<<die1<<endl;
                    break;
                }
                break;
            }
            //if 5 dice is kept
            case 5:{
                cout<<"You Entered 5, we should probably grade that..."<<endl;
                break;
            }
            //if 0 dice is kept
            default:{

            }
        }
    }
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
