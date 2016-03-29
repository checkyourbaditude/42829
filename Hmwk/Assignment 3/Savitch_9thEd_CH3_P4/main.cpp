/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Christopher Schaefer
 * CSC 5 Spring 2016 42829
 * Write a program that scores a blackjack hand of 2-5 cards
 * with the user naming their hand.
 *
 * Created on March 20, 2016, 6:05 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

int main(int argc, char** argv) {
    //variables; ui is the user input
    int uiN,busted=21;
    
    //these are the calculated values
    int v1=0,v2=0,v3=0,v4=0,v5=0,total=0;
    
    //these are the read in values
    char ui1=0,ui2=0,ui3=0,ui4=0,ui5=0;
    
    //the continue thought
    short cont=1;
    
    while(cont==1){
        //get the inputs from the user
        while(uiN!=2||uiN!=3||uiN!=4||uiN!=5){
            cout<<"Lets score your blackjack hand!"<<endl;
            cout<<"How many cards are in your hand? (must be between 2 and 5)"<<endl;
            cin>>uiN;

            //tell user the proper values to input!
            cout<<"Valid inputs are: 2-9, t(10),j(Jack),q(Queen),k(King),a(ace)."<<endl;
            cout<<"Please use lower case values only."<<endl;

            //if user has two cards
            if(uiN==2){
                cout<<"What is your First card?"<<endl;
                cin>>ui1;
                //immediately interpret value
                    if(ui1=='a')v1=1;
                    else if(ui1=='j')v1=10;
                    else if(ui1=='q')v1=10;
                    else if(ui1=='k')v1=10;
                    else if(ui1=='t')v1=10;
                    else{
                        v1= ui1 - '0';
                    }
                cout<<"What is your Second card?"<<endl;
                cin>>ui2;
                    if(ui2=='a')v2=1;
                    else if(ui2=='j')v2=10;
                    else if(ui2=='q')v2=10;
                    else if(ui2=='k')v2=10;
                    else if(ui2=='t')v2=10;
                    else{
                        v2= ui2 - '0';
                    }
                total=v1+v2;
                if(total>busted){
                    cout<<"BUST"<<endl;
                }
                else{
                    if(ui1=='a'||ui2=='a')total+=10;
                        if(total>busted)total-=10;
                        else{
                            cout<<"Your total is:"<<total<<endl;
                        }
                }
                break;
            }
            //if user has two cards
            else if (uiN==3){
                cout<<"What is your First card?"<<endl;
                cin>>ui1;
                    if(ui1=='a')v1=1;
                    else if(ui1=='j')v1=10;
                    else if(ui1=='q')v1=10;
                    else if(ui1=='k')v1=10;
                    else if(ui1=='t')v1=10;
                    else{
                        v1= ui1 - '0';
                    }
                cout<<"What is your Second card?"<<endl;
                cin>>ui2;
                    if(ui2=='a')v2=1;
                    else if(ui2=='j')v2=10;
                    else if(ui2=='q')v2=10;
                    else if(ui2=='k')v2=10;
                    else if(ui2=='t')v2=10;
                    else{
                        v2= ui2 - '0';
                    }
                cout<<"What is your Third card?"<<endl;
                cin>>ui3;
                    if(ui3=='a')v3=1;
                    else if(ui3=='j')v3=10;
                    else if(ui3=='q')v3=10;
                    else if(ui3=='k')v3=10;
                    else if(ui3=='t')v3=10;
                    else{
                        v3= ui3 - '0';
                    }
                total=v1+v2+v3;
                if(total>busted){
                    cout<<"BUST"<<endl;
                }
                else{
                    if(ui1=='a'||ui2=='a'||ui3=='a')total+=10;
                        if(total>busted)total-=10;
                        else{
                            cout<<"Your total is:"<<total<<endl;
                        }
                }
                cout<<"This is your total:"<<total<<endl;
                break;
            }
            //if user has three cards
            else if(uiN==4){
                cout<<"What is your First card?"<<endl;
                cin>>ui1;
                    if(ui1=='a')v1=1;
                    else if(ui1=='j')v1=10;
                    else if(ui1=='q')v1=10;
                    else if(ui1=='k')v1=10;
                    else if(ui1=='t')v1=10;
                    else{
                        v1= ui1 - '0';
                    }
                cout<<"What is your Second card?"<<endl;
                cin>>ui2;
                    if(ui2=='a')v2=1;
                    else if(ui2=='j')v2=10;
                    else if(ui2=='q')v2=10;
                    else if(ui2=='k')v2=10;
                    else if(ui2=='t')v2=10;
                    else{
                        v2= ui2 - '0';
                    }
                cout<<"What is your Third card?"<<endl;
                cin>>ui3;
                    if(ui3=='a')v3=1;
                    else if(ui3=='j')v3=10;
                    else if(ui3=='q')v3=10;
                    else if(ui3=='k')v3=10;
                    else if(ui3=='t')v3=10;
                    else{
                        v3= ui3 - '0';
                    }
                cout<<"What is your Fourth card?"<<endl;
                cin>>ui4;
                    if(ui4=='a')v4=1;
                    else if(ui4=='j')v4=10;
                    else if(ui4=='q')v4=10;
                    else if(ui4=='k')v4=10;
                    else if(ui4=='t')v4=10;
                    else{
                        v4= ui4 - '0';
                    }
                total=v1+v2+v3+v4;
                if(total>busted){
                    cout<<"BUST"<<endl;
                }
                else{
                    if(ui1=='a'||ui2=='a'||ui3=='a'||ui4=='a')total+=10;
                        if(total>busted)total-=10;
                        else{
                            cout<<"Your total is:"<<total<<endl;
                        }
                }
                cout<<"This is your total:"<<total<<endl;
                break;
            }
            //if user has four cards
            else if(uiN==5){
                cout<<"What is your First card?"<<endl;
                cin>>ui1;
                    if(ui1=='a')v1=1;
                    else if(ui1=='j')v1=10;
                    else if(ui1=='q')v1=10;
                    else if(ui1=='k')v1=10;
                    else if(ui1=='t')v1=10;
                    else{
                        v1= ui1 - '0';
                    }
                cout<<"What is your Second card?"<<endl;
                cin>>ui2;
                    if(ui2=='a')v2=1;
                    else if(ui2=='j')v2=10;
                    else if(ui2=='q')v2=10;
                    else if(ui2=='k')v2=10;
                    else if(ui2=='t')v2=10;
                    else{
                        v2= ui2 - '0';
                    }
                cout<<"What is your Third card?"<<endl;
                cin>>ui3;
                    if(ui3=='a')v3=1;
                    else if(ui3=='j')v3=10;
                    else if(ui3=='q')v3=10;
                    else if(ui3=='k')v3=10;
                    else if(ui3=='t')v3=10;
                    else{
                        v3= ui3 - '0';
                    }
                cout<<"What is your Fourth card?"<<endl;
                cin>>ui4;
                    if(ui4=='a')v4=1;
                    else if(ui4=='j')v4=10;
                    else if(ui4=='q')v4=10;
                    else if(ui4=='k')v4=10;
                    else if(ui4=='t')v4=10;
                    else{
                        v4= ui4 - '0';
                    }
                cout<<"What is your Fifth card?"<<endl;
                cin>>ui5;
                    if(ui5=='a')v5=1;
                    else if(ui5=='j')v5=10;
                    else if(ui5=='q')v5=10;
                    else if(ui5=='k')v5=10;
                    else if(ui5=='t')v5=10;
                    else{
                        v5= ui5 - '0';
                    }
                total=v1+v2+v3+v4+v5;
                if(total>busted){
                    cout<<"BUST"<<endl;
                }
                else{
                    if(ui1=='a'||ui2=='a'||ui3=='a'||ui4=='a'||ui5=='a')total+=10;
                        if(total>busted)total-=10;
                        else{
                            cout<<"Your total is:"<<total<<endl;
                        }
                }
                cout<<"This is your total:"<<total<<endl;
                break;
            }
            //if user has five cards
            else{
                cout<<"You did not enter a valid number, try again!"<<endl;
            }
        }
    cout<<"Do you want to continue playing? Yes(1) or No(2)"<<endl;
    cin>>cont;
    }
    return 0;
}

