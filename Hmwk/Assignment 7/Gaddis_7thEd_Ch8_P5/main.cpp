/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: chris
 *
 * Created on May 30, 2016, 1:24 PM
 */

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Function prototypes
void getData(float [], int);
float totalRainfall(float [], int);
float averageRainfall(float [], int);
int driestMonth(float [], int);
int wettestMonth(float [], int);
void displayReport(float, float, int, int, float [], int);
string getMonth(int);

// Global variables


int main(){
	const int mths = 12;
	float rainfall[mths];
	float Total, Average, Least, Most;

	// Call function getData
	getData(rainfall, mths);

	// Call function totalRainfall
	Total = totalRainfall(rainfall, mths);
	Average = averageRainfall(rainfall, mths);
	Least = driestMonth(rainfall, mths);
	Most = wettestMonth(rainfall, mths);
	displayReport(Total, Average, Least, Most, rainfall, mths);

	return 0;
}
//gets user input
void getData(float rainfall[], int mths){
	float rain;

	cout << "Enter the total rainfall for each of 12 months.\n";
	for (int i = 0; i < mths; i++){
            do{
                cout << "Month #" <<  (i + 1) << ": ";
                cin >> rain;

                if (rain < 0){
                    cout << "Error! Rainfall amounts must be greater than 0.\n";
                }
            }while(rain < 0);

            rainfall[i] = rain;
	}	 
}

float totalRainfall(float rainfall[], int mths){
    float tot = 0;

    for (int i = 0; i < mths; i++){
        tot+=rainfall[i];
    }

    return tot;
}

float averageRainfall(float rainfall[], int mths){
	return totalRainfall(rainfall, mths) / mths;
}

int driestMonth(float rainfall[], int mths){	
    float Driest = rainfall[0];
    int R;
    for (int i = 0; i < mths; i++){
        if(rainfall[i] < Driest){
                Driest = rainfall[i];
                R = i;
        }
    }
    return R;
}

int wettestMonth(float rainfall[], int mths){
    float Wettest = rainfall[0];
    int R;
    for (int i = 0; i < mths; i++){
        if(rainfall[i] > Wettest){
            Wettest = rainfall[i];
            R = i;
        }
    }
    return R;
}

void displayReport(float T, float A, int L, int M, float R[], int S){
    cout << "\n\n    2016 Rain Report for Riverside County\n\n";
    cout << fixed << showpoint << setprecision(2);
    cout << "Total rainfall: " << T << " inches\n";
    cout << "Average monthly rainfall: " << A << " inches\n";
    cout << "The least rain fell in " << getMonth(L) << " with "
        << R[L] << " inches.\n";
    cout << "The most rain fell in " << getMonth(M) << " with "
        << R[M] << " inches.\n";
}

string getMonth(int Mth){
    string M;
    switch (Mth + 1){
        case 1:{
            M="January";
            break;
        }
        case 2:{
            M="February";
            break;
        }
        case 3:{
            M="March";
            break;
        }
        case 4:{ 
            M="April";
            break;
        }
        case 5:{
            M="May";
            break;
        }
        case 6:{
            M="June";
            break;
        }
        case 7:{ 
            M="July";
            break;
        }
        case 8:{
            M="August";
            break;
        }
        case 9:{ 
            M="September";
            break;
        }
        case 10:{
            M="October";
            break;
        }
        case 11:{
            M="November";
            break;
        }
        case 12:{
            M="December";
            break;
        }
    }
    return M;
}

