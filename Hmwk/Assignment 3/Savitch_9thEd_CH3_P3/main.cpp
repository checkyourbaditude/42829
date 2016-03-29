/* 
 * File:   main.cpp
 * Author: Christopher Schaefer
 * Write a program that accepts a year written as a four-digit Arabicnumeral and
 * outputs the year written in Roman numerals
 * Created on March 23, 2016, 10:04 AM
 */

#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

int main(int argc, char** argv) {
    //set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //variables
    unsigned short number=rand()%2001+1000;//this makes it start between 1000 and 3000
    unsigned char n1000s,n100s,n10s,n1s;
    
    //output the number that is going to be converted
    cout<<"This is the number to be converted:"<<number<<endl;
    
    //calculate the number in each place
    n1000s=(number-number%1000)/1000;
    number=(number-n1000s*1000);
    n100s=(number-number%100)/100;
    number=(number-n100s*100);
    n10s=(number-number%10)/10;
    n1s=(number-n10s*10);
    
    //outputt the numbers that are going to be converted
    //must static cast them to make sure that it is the correct value
    cout<<"The number of 1000s is:"<<static_cast<int>(n1000s)<<endl;
    cout<<"The number of 100s is:"<<static_cast<int>(n100s)<<endl;
    cout<<"The number of 10s is:"<<static_cast<int>(n10s)<<endl;
    cout<<"The number of 1s is:"<<static_cast<int>(n1s)<<endl;
    
    //Figure out the digits in the 1000s
    switch(n1000s){
        case 3:
            cout<<"M";
        case 2:
            cout<<"M";
        case 1:
            cout<<"M";
    }
    //Figure out the digits in the 100s
    switch(n100s){
        case 9:
            cout<<"CM";
            break;
        case 8:
            cout<<"DCCC";
            break;
        case 7:
            cout<<"DCC";
            break;
        case 6:
            cout<<"DC";
            break;
        case 5:
            cout<<"D";
            break;
        case 4:
            cout<<"CD";
            break;
        case 3:
            cout<<"C";
        case 2:
            cout<<"C";
        case 1:
            cout<<"C";     
    }
    //Figure out the digits in the 10s
    switch(n10s){
        case 9:
            cout<<"XC";
            break;
        case 8:
            cout<<"LXXX";
            break;
        case 7:
            cout<<"LXX";
            break;
        case 6:
            cout<<"LX";
            break;
        case 5:
            cout<<"L";
            break;
        case 4:
            cout<<"XL";
            break;
        case 3:
            cout<<"L";
        case 2:
            cout<<"L";
        case 1:
            cout<<"L";  
    }
    //Figure out the digits in the 1s
    switch(n1s){
        case 9:
            cout<<"IX";
            break;
        case 8:
            cout<<"VIII";
            break;
        case 7:
            cout<<"VII";
            break;
        case 6:
            cout<<"VI";
            break;
        case 5:
            cout<<"V";
            break;
        case 4:
            cout<<"IV";
            break;
        case 3:
            cout<<"I";
        case 2:
            cout<<"I";
        case 1:
            cout<<"I";
    }
    return 0;
}

