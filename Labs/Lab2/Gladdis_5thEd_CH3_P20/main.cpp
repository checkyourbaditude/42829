/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on March 7, 2016, 10:48 AM
 */

#include <cstdlib>
#include <math.h>
#include <iostream>
using namespace std;
//Global Constant
const float PI = atan(1)*4;

int main(int argc, char** argv) {
    //variables
    float area;
    int d, n;
    
    //inputs
    
    cout<<"What is the diameter of the pizza?"<<endl;
    cin>>d;
    
    //calculation
    area = (PI * d * d)/4.00;
    
    n = (area/14.125)+1;
    
    cout<<area<<endl;
    cout<<n<<endl;
    
    return 0;
}

