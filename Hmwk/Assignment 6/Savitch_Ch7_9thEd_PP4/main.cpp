/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: chris
 *
 * Created on May 9, 2016, 10:16 AM
 */

#include <cstdlib>
#include <string>
#include <iostream>
using namespace std;

string lookupName(string Name, string lNames[], string lPhones[]);

int main(int argc, char** argv) {
    //variables
    string names[]={"Michael Myers",
                    "Ash Williams",
                    "Jack Torrance",
                    "Freddy Krueger"};
    string phoneNumbers[]={"333-8000",
                           "333-2323",
                           "333-6150",            
                           "339-7970"};
    string targetName, targetPhone;
    char c;
    do{
        cout<<"Enter a name to find the"
            <<"Corresponding phone number."<<endl;
        getline(cin, targetName);
        targetPhone=lookupName(targetName, names, phoneNumbers);
        if(targetPhone.length() > 0){
            cout<<"The Number is: "<<targetPhone<<endl;
        }
        else{
            cout<<"Name not found."<<endl;
        }
        cout<<"Look up another name? (y/n)"<<endl;
        cin>>c;
        cin.ignore();
        }while(c=='y');
                
    return 0;
}

string lookupName(string Name, string lNames[], string lPhones[]){
    string Value="";
    
    for(int i=0;i<=4;i++){
        if(Name==lNames[i]){
            Value=lPhones[i];
            return Value;
        }
    }
}

