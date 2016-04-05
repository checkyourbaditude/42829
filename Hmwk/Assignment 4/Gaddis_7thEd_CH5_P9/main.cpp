/* 
 * File:   main.cpp
 * Author: Chris Schaefer
 * Gladdis Chapter 5 Problem 9
 * Calculate the occupancy rate of a hotel
 * ask for the number of floors, then number of rooms, then number of the rooms
 * that are occupied.
 * Then output a percentage
 * Created on January 24, 2016, 7:10 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

int main(int argc, char** argv) {
    //Declare Variables
    int nfloors,nrooms,trooms,noccp,toccp;
    float poccp;
    
    
    //Input
    cout<<"Lets calculate the number of rooms that are occupied in the hotel."<<endl;
    cout<<"How many floors are in the hotel?"<<endl;
    cin>>nfloors;

    //loop, figure out the number of rooms in each floor
    for(int i=1;i<=nfloors;i++){
        cout<<"What is the number of rooms on floor number "<<i<<"?"<<endl;
        cin>>nrooms;
        trooms+=nrooms;
        cout<<"What is the number of rooms that are occupied on floor"
              " number "<<i<<"?"<<endl;
        cin>>noccp;
        toccp+=noccp;
    }
    
    //Output the results from the loop, making sure to get a percentage from
    //the poccp variable
    poccp=(float)toccp/(float)trooms*100;
    cout<<"The number of rooms in the hotel is: "<<trooms<<endl;
    cout<<"The number of rooms that are occupied in the hotel is: "<<noccp<<endl;
    cout<<"The percentage of the hotel rooms that are occupied is: "
          <<poccp<<"%"<<endl;
    return 0;
}

