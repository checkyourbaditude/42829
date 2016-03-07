/* 
 * File:   main.cpp
 * Author: Christopher Schaefer
 * Lab 03/01/2016
 * Created on March 2, 2016, 10:09 AM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

int main(int argc, char** argv) {
    //variables
    //google revenue from http://www.statista.com/statistics/266206/googles-annual-global-revenue/
    float rev=74.54e9f, ireRate=.125, usaRate=.4;
    
    cout<<"The total revenue of Google in 2015 was "<<rev<<endl;
    cout<<"They paid "<<usaRate*rev<<" in taxes on that revenue."<<endl;
    cout<<"if they were based in Ireland they would have paid "<<ireRate*rev<<" in taxes."<<endl;
    cout<<"Google pays "<<(usaRate*rev)-(ireRate*rev)<<" more in taxes because they are based in the USA."<<endl;
    return 0;
}

