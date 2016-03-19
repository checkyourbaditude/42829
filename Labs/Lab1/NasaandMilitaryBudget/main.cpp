/* 
 * File:   main.cpp
 * Author: Christopher, Schaefer
 * Lab 03/1/2016
 * Created on March 2, 2016, 10:00 AM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

int main(int argc, char** argv) {
    //variables
    float budget=3.8e12f, mil=601e9f, nasa=19.3e9f;
    
    //calculations
    

    cout<<"The total budget is "<<budget<<endl;
    cout<<"The Military portion is "<<mil<<" and is "<<(mil/budget)*100<<" percent of the total"<<endl;
    cout<<"The NASA portion is "<<nasa<<" and is "<<(nasa/budget)*100<<" percent of the total"<<endl;
    return 0;
}

