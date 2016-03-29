/* 
 * File:   main.cpp
 * Author: Chris Schaefer
 * Gladdis Chapter 4 Problem 18
 * Display a menu allowing the user to select air, water, or steel with a
 * distance travled. Display the time it will take with four decimal percision
 * Created on January 22, 2016, 11:21 AM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char** argv) {
    //Variables
    short input;
    float air=1100, water=4900, steel=16400, dis, result;
    
    //menu
    cout<<"The following are the speed of sound in specific mediums"<<endl;
    cout<<"Lets calculate how long it will take for sound to travel through"
          "these mediums. Select one!"<<endl;
    cout<<"1. Air         1,100 feet per second"<<endl;
    cout<<"2. Water       4,900 feet per second"<<endl;
    cout<<"3. Stell       16,400 feet per second"<<endl;
    cin>>input;
    
    //Inputs
    cout<<"How far is it going to travel? (feet)"<<endl;
    cin>>dis;
    
    //calculations
    
    switch(input){
        case 1:
            result=air/dis;
            cout<<fixed<<setprecision(4);
            cout<<"You chose air"<<endl;
            cout<<"The sound will travel "<<dis<<" in "<<result<<" seconds";
            break;
        case 2:
            result=water/dis;
            cout<<fixed<<setprecision(4);
            cout<<"You chose water"<<endl;
            cout<<"The sound will travel "<<dis<<" in "<<result<<" seconds";
            break;
        case 3:
            result=steel/dis;
            cout<<fixed<<setprecision(4);
            cout<<"You chose steel"<<endl;
            cout<<"The sound will travel "<<dis<<" in "<<result<<" seconds";
            break;
    }
    return 0;
}

