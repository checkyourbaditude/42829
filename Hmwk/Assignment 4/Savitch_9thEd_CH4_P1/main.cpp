/* 
 * File:   main.cpp
 * Author: Christopher Schaefer
 * Use a fucntion to calculate the MPG of a car, input the number of liters
 * create global constant of conversion from the liters to gallons
 * 
 * Created on March 28, 2016, 10:17 AM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;
//global constant for litres per gallon
const float LITERS_PER_GALLON=3.78541;

//function to calculate the MPG
float calcMPG(int liters,int miles){
    return ((static_cast<float>(liters)*LITERS_PER_GALLON)/static_cast<float>(miles));
}

int main(int argc, char** argv) {
    //variables
    
    char choice;
    int gas,dist;
    float MPG;
    do{
        cout<<"Lets calculate the MPG of your vehicle!"<<endl;
        
        //read in the amount of liters
        cout<<"How many liters has your car consumed?"<<endl;
        cin>>gas;
        
        //read in the number of miles
        cout<<"How far have you gone, in miles?"<<endl;
        cin>>dist;
        
        //call the function
        MPG=calcMPG(gas,dist);
        
        //output result
        cout<<"Your MPG is:"<<setprecision(3)<<MPG<<endl;
        
        //ask user if the calculation wants to be done again
        cout<<"Do you want to do another calculation: Yes(1) or No (2)?"<<endl;
        cin>>choice;
    }while(choice=='1');
    return 0;
}

