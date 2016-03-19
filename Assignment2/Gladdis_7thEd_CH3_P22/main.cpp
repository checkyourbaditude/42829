/* 
 * File:   main.cpp
 * Author: Chris Schaefer
 * Chapter 3 Problem 22 Gladdis 7th Edition
 * Create the word game in the book, ask user for input
 * Created on January 14, 2016, 2:08 AM
 */

#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char** argv) {
    //Declare Variables
    string name, age, city, college, pro, animal, pname;
    
    //inputs
    cout<<"What is your name?"<<endl;
    cin>>name;
    cout<<"How old are you?"<<endl;
    cin>>age;
    cout<<"What city are you in?"<<endl;
    cin>>city;
    cout<<"What school do you go to?"<<endl;
    cin>>college;
    cout<<"What profession do you want to be?"<<endl;
    cin>>pro;
    cout<<"What is your favorite animal?"<<endl;
    cin>>animal;
    cout<<"What is the animals name?"<<endl;
    cin>>pname;
    
    //outputs
    cout<<"There once was a person named "<<name<<" who lived in "<<city<<"\n. At"
          " the age of "<<age<<", "<<name<<"went to college at "<<college<<"\n. "
          <<name<<" graduated and went to work as a "<<pro<<"\n. Then,"<<name<<
          "adopted a(n) "<<animal<<" named "<<pname<<"\n. They both lived"
          "happily after!";
    return 0;
}

