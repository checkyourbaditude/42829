/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Christopher
 *
 * Created on April 23, 2016, 7:20 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

//functional Prototypes
float getCharges(int days, float rate, float med, float serv);
float getCharges(float med, float serv);

int main(int argc, char** argv) {
    //variables
    char type=0;
    int nDays=0;
    float dRate=0.00f, mCharges=0.00f, sCharges=0.00f, total=0.00f;
    
    //output, check to see if patient is in or out
    cout<<"Lets calculate the charges for your medical stay!"<<endl;
    cout<<"Are you an in-patient(1), or an outpatient(2)?"<<endl;
    cin>>type;
    
    switch(type){
        //in-patient expense calculation
        case'1':
            cout<<"For in-patient we need the following expenses:\n\n"<<endl;;
            
            //number of days during the stay
            cout<<"How many days were you in the hospital?"<<endl;
            cin>>nDays;
            
            //validate
            while(nDays<1){
                cout<<"Invalid Input!"<<endl;
                cout<<"How many days were you in the hospital?"<<endl;
                cin>>nDays;
            }
            
            //the daily rate
            cout<<"What is the daily rate?"<<endl;
            cin>>dRate;
            
            //validate
            while(dRate<1){
                cout<<"Invalid Input!"<<endl;
                cout<<"What is the daily rate?"<<endl;
                cin>>dRate;
            }
            
            //medication charges
            cout<<"What were your hospital medication charges? (enter 0 if none)"<<endl;
            cin>>mCharges;
            
            //validate
            //validate
            while(mCharges<1){
                cout<<"Invalid Input!"<<endl;
                cout<<"What were your hospital medication charges? (enter 0 if none)"<<endl;
                cin>>mCharges;
            }
            
            //Hospital services charges
            cout<<"What were your hospital service charges? (enter 0 if none)"<<endl;
            cin>>sCharges;
            
             while(sCharges<1){
                cout<<"Invalid Input!"<<endl;
                cout<<"What were your hospital service charges? (enter 0 if none)"<<endl;
                cin>>sCharges;
            }
            
            //call function with data that was input
            total=getCharges(nDays, dRate, mCharges, sCharges);
            
            //output the result
            cout<<"Your total Charges are: "<<setprecision(2)<<fixed<<total<<"$"<<endl;
            break;
            
        //out-patient expense calculation
        case '2':
            cout<<"For out-patient we need the following expenses:";
            
            //medication charges
            cout<<"What were your hospital medication charges? (enter 0 if none)"<<endl;
            cin>>mCharges;
            
            //validate
            //validate
            while(mCharges<1){
                cout<<"Invalid Input!"<<endl;
                cout<<"What were your hospital medication charges? (enter 0 if none)"<<endl;
                cin>>mCharges;
            }
            
            //Hospital services charges
            cout<<"What were your hospital service charges? (enter 0 if none)"<<endl;
            cin>>sCharges;
            
             while(sCharges<1){
                cout<<"Invalid Input!"<<endl;
                cout<<"What were your hospital service charges? (enter 0 if none)"<<endl;
                cin>>sCharges;
            }
            
            //call function with the data that was input
            total=getCharges(mCharges, sCharges);
            
            //output the result
            cout<<"Your total Charges are: "<<setprecision(2)<<fixed<<total<<"$"<<endl;
            break;
    }
    return 0;
}

float getCharges(int days, float rate, float med, float serv){
    
    //local variable to hold data
    float tot=0.00f;
    
    //calculations
    tot=((static_cast<float>(days)*rate)+med+serv);
    
    //return data
    return tot;
}
float getCharges(float med, float serv){
    
    //variable to hold local data
    float tot=0.00f;
    
    //calculation
    tot=med+serv;
    
    //return data
    return tot;
}
