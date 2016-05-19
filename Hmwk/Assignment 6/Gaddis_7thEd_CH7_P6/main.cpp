/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Christopher
 *
 * Created on May 14, 2016, 10:39 PM
 */

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <fstream>
using namespace std;

void genNums();

int main(int argc, char** argv) {
    
    genNums();
    
    //open the file stream to bring in the numbers to the array
    fstream readIn("numbers.text");
    const int SIZE=100;
    char txtNums[SIZE];
    int i=0;
    
    //continue reading in until the end of the file is reached
    while(readIn>>txtNums[i]){
        readIn>>txtNums[i];
        cout<<"The "<<i<<" element is:"<<txtNums[i]<<endl;
        i++;
    }
    
    readIn.close();
    return 0;
}
void genNums(){
    //set random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //open File stream
    ofstream fillFile;
    fillFile.open("numbers.dat");
    
    //figure out how many numbers are going into the file
    int numContents=rand()%100+1;
    const int SIZE=100;
    int numbers[SIZE];
    int nArray=0;
    
    //fill the file with numbers
    for(int i=0;i<numContents;i++){
        fillFile<<rand()%1000+1<<"/n/r";
    }
    
    //close the file
    fillFile.close();
}

