/* 
 * File:   main.cpp
 * Author: Chris Schaefer
 * Gladdis Chapter 4 Problem 20
 * Ask the user to enter a temperature and then show all the substances that
 * will freeze at that temperature and all that will boil at that temperature. 
 * Created on January 22, 2016, 11:52 AM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

int main(int argc, char** argv) {
    //Declare Variables
    int utemp;
    
    //Outputs
    cout<<"The following substances feeze and boil at the following temps:"<<endl;
    cout<<"Substance        Feezeing point (F)      Boiling Point (F)"<<endl;
    cout<<"Ethyl Alcohol    -173                    172"<<endl;
    cout<<"Mercury          -38                     676"<<endl;
    cout<<"Oxygen           -362                    -306"<<endl;
    cout<<"Water            32                      212"<<endl;
    
    //Input
    cout<<"Enter a temp and see what will Freeze and Boil at that temp"<<endl;
    cin>>utemp;
    
    //Logic
    
    if (utemp<=-38){cout<<"Mercury Freezes at this point!"<<endl;
        if(utemp<=-173)(cout<<"Ethyl Alcohol Freezes at this point!"<<endl);
            if(utemp<=-306)(cout<<"Oxygen Boils at this point!"<<endl);
                if(utemp<=-362)(cout<<"Oxygen Freezes at this point!"<<endl);
    }
    else if (utemp>=32){
        cout<<"Water Freezes at this point!"<<endl;
        if(utemp>=172)(cout<<"Ethyl Alcohol Boils at this point!"<<endl);
            if(utemp>=212)(cout<<"Water Boils at this point!"<<endl);
                if(utemp>=676)(cout<<"Mercury Boils at this point!"<<endl);
    }
    return 0;
}

