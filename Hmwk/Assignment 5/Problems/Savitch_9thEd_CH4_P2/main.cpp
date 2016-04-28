/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on April 27, 2016, 8:00 AM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;
//Book asked for Global constant of liters per gallon
const float LITERS_PER_GALLON=3.78541;

//conversion 
float calcMPG(int liters,int miles);

int main(int argc, char** argv) {
    char choice;
    int gas1=0,dist1=0,gas2=0,dist2=0;
    float MPG1,MPG2;
    do{
        cout<<"Lets calculate the MPG of 2 vehicles!"<<endl;
        
        //read in the amount of liters
        cout<<"How many liters has the first car consumed?"<<endl;
        cin>>gas1;
        
        //read in the number of miles
        cout<<"How far has the first car gone, in miles?"<<endl;
        cin>>dist1;
        
        //read in the amount of liters
        cout<<"How many liters has the second car consumed?"<<endl;
        cin>>gas2;
        
        //read in the number of miles
        cout<<"How far has the second car gone, in miles?"<<endl;
        cin>>dist2;
        
        //call the function
        MPG1=calcMPG(gas1,dist1);
        MPG2=calcMPG(gas2,dist2);
        
        //output result
        cout<<"First MPG is:"<<setprecision(3)<<MPG1<<endl;
        cout<<"Second MPG is:"<<setprecision(3)<<MPG2<<endl;
        
        if (MPG1>MPG2){
            cout<<"The first car has better gas milage!"<<endl;
        }
        else if (MPG1<MPG2){
            cout<<"The Second car has better gas milage!"<<endl;
        }
        
        //ask user if the calculation wants to be done again
        cout<<"Do you want to do another calculation: Yes(1) or No (2)?"<<endl;
        cin>>choice;
    }while(choice=='1');
    return 0;
}

//conversion formula
float calcMPG(int liters,int miles){
    return (static_cast<float>(miles)/(static_cast<float>(liters)*LITERS_PER_GALLON));
}

