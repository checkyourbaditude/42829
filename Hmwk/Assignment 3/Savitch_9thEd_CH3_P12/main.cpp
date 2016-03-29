/* 
 * File:   main.cpp
 * Author: Christopher Schafer
 * There is a pile of 23 toothpicks, each player takes turns removing between
 * 1-3 toothpicks. The last player to remove a toothpick looses.
 * The computer player must have the following conditions:
 * 1.If there are more than 4 toothpicks left, then the computer should withdraw
 *  4-x where x is the number of toothpicks removed by user.
 * 2.If there are 2-4 toothpicks left, then the computer should withdraw enough
 *  toothpicks to leave 1.
 * 3.If there is 1 toothpick left, the computer must take it and loose.
 * Created on March 28, 2016, 8:14 AM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

int main(int argc, char** argv) {
    //variables
    int stotal=23, user=0;
    
    //layout the rules
    cout<<"Lets play 23!"<<endl;
    cout<<"There are "<<stotal<<" picks in he pile."<<endl;
    
    while(stotal>0){
        //get the input from the user
        cout<<"You can draw 1, 2, or 3 picks from the pile"<<endl;
        cin>>user;
        switch(user){
            case 1:
                stotal-=user;
                //first condition
                if(stotal==0){
                    cout<<"You have lost!"<<endl;
                    break;
                }
                else if(stotal>4){
                    stotal-=(4-user);
                    cout<<"The computer withdrew "<<4-user<<" picks!"<<endl;
                //second condition
                }else if(stotal<=4 && stotal>=2){
                    if(stotal==4){
                        stotal-=3;
                        cout<<"The computer withdrew "<<3<<" picks!"<<endl;
                    }
                    if(stotal==3){
                        stotal-=2;
                        cout<<"The computer withdrew "<<2<<" picks!"<<endl;
                    }
                    if(stotal==2){
                        stotal-=1;
                        cout<<"The computer withdrew "<<2<<" picks!"<<endl;            
                    }
                //third condition
                }else if(stotal==1){
                    stotal-=1;
                    cout<<"The computer loses!"<<endl;
                    break;
                }
                cout<<"There are "<<stotal<<" picks left!"<<endl;
                break;
            case 2:
                stotal-=user;
                //first condition
                if(stotal==0){
                    cout<<"You have lost!"<<endl;
                    break;
                }
                else if(stotal>4){
                    stotal-=(4-user);
                    cout<<"The computer withdrew "<<4-user<<" picks!"<<endl;
                //second condition
                }else if(stotal<=4 && stotal>=2){
                    if(stotal==4){
                        stotal-=3;
                        cout<<"The computer withdrew "<<3<<" picks!"<<endl;
                    }
                    if(stotal==3){
                        stotal-=2;
                        cout<<"The computer withdrew "<<2<<" picks!"<<endl;
                    }
                    if(stotal==2){
                        stotal-=1;
                        cout<<"The computer withdrew "<<2<<" picks!"<<endl;            
                    }
                //third condition
                }else if(stotal==1){
                    stotal-=1;
                    cout<<"The computer loses!"<<endl;
                    break;
                }
                cout<<"There are "<<stotal<<" picks left!"<<endl;
                break;
            case 3:
                stotal-=user;
                //first condition
                if(stotal==0){
                    cout<<"You have lost!"<<endl;
                    break;
                }
                else if(stotal>4){
                    stotal-=(4-user);
                    cout<<"The computer withdrew "<<4-user<<" picks!"<<endl;
                //second condition
                }else if(stotal<=4 && stotal>=2){
                    if(stotal==4){
                        stotal-=3;
                        cout<<"The computer withdrew "<<3<<" picks!"<<endl;
                    }
                    if(stotal==3){
                        stotal-=2;
                        cout<<"The computer withdrew "<<2<<" picks!"<<endl;
                    }
                    if(stotal==2){
                        stotal-=1;
                        cout<<"The computer withdrew "<<2<<" picks!"<<endl;            
                    }
                //third condition
                }else if(stotal==1){
                    stotal-=1;
                    cout<<"The computer loses!"<<endl;
                    break;
                }
                cout<<"There are "<<stotal<<" picks left!"<<endl;
                break;
            default:
                cout<<"Not valid: Enter 1, 2, or 3"<<endl;
                cout<<"There are "<<stotal<<" picks left!"<<endl;
                break;
        }
    }
    return 0;
}

