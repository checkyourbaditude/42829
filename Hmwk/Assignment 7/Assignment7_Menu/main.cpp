/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: chris
 *
 * Created on May 30, 2016, 3:27 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
using namespace std;

//menu function
void menu();

//problems
//Gaddis_7thEd_CH8_P1
void prob1();
//Gaddis_7thEd_CH8_P2
void prob2();
//Gaddis_7thEd_CH8_P3
void prob3();
//Gaddis_7thEd_CH8_P4
void prob4();
//Gaddis_7thEd_CH8_P5
void prob5();
//Gaddis_7thEd_CH8_P6
void prob6();
//Gaddis_7thEd_CH8_P7
void prob7();
//Gaddis_7thEd_CH8_P8
void prob8();
//Gaddis_7thEd_CH8_P9
void prob9();
//Gaddis_7thEd_CH8_P10
void prob10();

//Gaddis_7thEd_CH8_P1 Functions and Gaddis_7thEd_CH8_P2 Functions
//function to search
bool searchArr(int [], int, int);

//Gaddis_7thEd_CH8_P3 functions, and Gaddis_7thEd_CH8_P4
//function to search
bool biSearchArr(int [], int, int);
void mrkSort(int a[], int n);

//Gaddis_7thEd_CH8_P5 functions
void getData(float [], int);
float totalRainfall(float [], int);
float averageRainfall(float [], int);
int driestMonth(float [], int);
int wettestMonth(float [], int);
void displayReport(float, float, int, int, float [], int);
string getMonth(int);

//Gaddis_7thEd_CH8_P6 functions
void showArry(string [], int);
void selectSort(string [], int);

//Gaddis_7thEd_CH8_P7 functions
void bubbleSort(string [], int);
void biSearch(string [], int);

//Gaddis_7thEd_CH8_P8 functions
void fillArr1(int [], int);
void printArr(int [], int);
bool biSearchArr1(int [], int, int);
void mrkSort(int [], int);
bool linSearchArr(int [], int, int);

//Gaddis_7thEd_CH8_P9 functions
void bubSort(int [], int);
void selSort(int [], int);

//Gaddis_7thEd_CH8_P10 functions
//functional prototypes
void fillArr(int [], int);
void printArr(int [], int);
void bubSort1(int [], int);
void selSort1(int [], int);

int main(int argc, char** argv) {
    unsigned short choice;
    //General Menu Format
    do{
        //Display the selection
        menu();
        //Read the choice
        cin>>choice;
        //Solve a problem that has been chosen.
        switch(choice){
            case 1:     prob1();break;
            case 2:     prob2();break;
            case 3:     prob3();break;
            case 4:     prob4();break;
            case 5:     prob5();break;
            case 6:     prob6();break;
            case 7:     prob7();break;
            case 8:     prob8();break;
            case 9:     prob9();break;
            case 10:    prob10();break;

            default:{
                    cout<<"Exit?"<<endl;
            }
        };
    }while(choice<=10&&choice>=1);
    return 0;
}
void menu(){
    cout<<"Type 1 to solve problem 1"<<endl;
    cout<<"Type 2 to solve problem 2"<<endl;
    cout<<"Type 3 to solve problem 3"<<endl;
    cout<<"Type 4 to solve problem 4"<<endl;
    cout<<"Type 5 to solve problem 5"<<endl;
    cout<<"Type 6 to solve problem 6"<<endl;
    cout<<"Type 7 to solve problem 7"<<endl;
    cout<<"Type 8 to solve problem 8"<<endl;
    cout<<"Type 9 to solve problem 9"<<endl;
    cout<<"Type 10 to solve problem 10"<<endl;
    cout<<"Type a letter to quit with no solutions."<<endl;
}
void prob1(){
    
    const int SIZE=18;
    
    //variables
    int ChrgVal[SIZE]={
        5658845,4520125,7895122,8777541,8451277,1302850,8080152,4562555,5552012,
        5050552,7825877,1250255,1005231,6545231,3852085,7576651,7881200,4581002,
    };
    int choice=0;
    
    cout<<"Enter a card number so we can see if it matches the list"<<endl;
    cin>>choice;
    
    //use linear search to see if the entered data matches
    if(searchArr(ChrgVal, SIZE, choice)){
        cout<<"This is a valid number!"<<endl;
    }
    else{
        cout<<"Number is not valid!"<<endl;
    }
}

void prob2(){
    
    const int SIZE=18;
    
    //variables
    int lotVal[SIZE]={
        13579,26791,26792,33445,55555,62483,77777,79422,85647,93121,
    };
    int choice=0;
    
    cout<<"Enter the winning lottery number, and we will check to see if your are a winner!"<<endl;
    cin>>choice;
    
    //use linear search to see if the entered data matches
    if(searchArr(lotVal, SIZE, choice)){
        cout<<"Winner!"<<endl;
    }
    else{
        cout<<"Not a Winner!"<<endl;
    }
}

void prob3(){
    //array sizes
    const int SIZE=18;
    
    //variables
    int lotVal[SIZE]={
        13579,26791,26792,33445,55555,62483,77777,79422,85647,93121,
    };
    int choice=0;
    
    cout<<"Enter the winning lottery number, and we will check to see if your are a winner!"<<endl;
    cin>>choice;
    
    //use linear search to see if the entered data matches
    if(biSearchArr(lotVal, SIZE, choice)){
        cout<<"Winner!"<<endl;
    }
    else{
        cout<<"Not a Winner!"<<endl;
    }
}

void prob4(){
    //array sizes
    const int SIZE=18;
    
    //variables
    int ChrgVal[SIZE]={
        5658845,4520125,7895122,8777541,8451277,1302850,8080152,4562555,5552012,
        5050552,7825877,1250255,1005231,6545231,3852085,7576651,7881200,4581002,
    };
    int choice=0;
    
    cout<<"Enter a Charge value to see if it matches!"<<endl;
    cin>>choice;
    
    //use linear search to see if the entered data matches
    if(biSearchArr(ChrgVal, SIZE, choice)){
        cout<<"Winner!"<<endl;
    }
    else{
        cout<<"Not a Winner!"<<endl;
    }
}

void prob5(){
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
}

void prob6(){   
    //constant for array size
    const int NUM_NAMES=20;
    
    string names[NUM_NAMES]={
        "Collins, Bill", "Smith, Bart", "Allen, Jim", "Griffin, Jim",
        "Stamey, Marty", "Rose, Geri", "Taylor, Terri", "Johnson, Jill",
        "Allison, Jeff", "Looney, Joe", "Wolfe, Bill", "James, Jean",
        "Weaver, Jim", "Pore, Bob", "Butherfod, Greg", "Javens, Renee",
        "Harrison, Rose", "Setzer, Cathy", "Pike, Gordon", "Holland, Beth"};
    
    cout<<"Unstorted String Array"<<endl;
    showArry(names, NUM_NAMES);
    cout<<endl;
    
    //sort the string array
    selectSort(names, NUM_NAMES);
    
    cout<<"Sorted String Array"<<endl;
    showArry(names, NUM_NAMES);
    cout<<endl;
}

void prob7(){
    //constant for array size
    const int NUM_NAMES=20;
    
    //variables
    string names[NUM_NAMES]={
        "Collins, Bill", "Smith, Bart", "Allen, Jim", "Griffin, Jim",
        "Stamey, Marty", "Rose, Geri", "Taylor, Terri", "Johnson, Jill",
        "Allison, Jeff", "Looney, Joe", "Wolfe, Bill", "James, Jean",
        "Weaver, Jim", "Pore, Bob", "Butherfod, Greg", "Javens, Renee",
        "Harrison, Rose", "Setzer, Cathy", "Pike, Gordon", "Holland, Beth"};
    
    cout<<"Unstorted String Array"<<endl;
    showArry(names, NUM_NAMES);
    cout<<endl;
    
    //sort the string array
    biSearch(names, NUM_NAMES);
    
    cout<<"Sorted String Array"<<endl;
    showArry(names, NUM_NAMES);
    cout<<endl;
}

void prob8(){
    //declare array
    const int SIZE=20;
    int choice;
    int Numbers[SIZE];
    
    //fill the array
    fillArr1(Numbers,SIZE);
    
    //print the array
    printArr(Numbers, SIZE);
    
    //get user input
    cout<<"Pick a number to find in the array"<<endl;
    cin>>choice;
    while(choice<0||choice>=21){
        cout<<"Try again!"<<endl;
        cin>>choice;
    }
    
    //use the binary search
    if(biSearchArr1(Numbers,SIZE,choice)){
        cout<<"Number was found using Binary search."<<endl;
    }
    else{
        cout<<"Number was not found using Binary search."<<endl;
    }
    
    //use the linear search
    if(linSearchArr(Numbers,SIZE,choice)){
        cout<<"Number was found using Linear search."<<endl;
    }
    else{
        cout<<"Number was not found using Linear search."<<endl;
    }
}
void prob9(){
    //declare arrays
    const int SIZE=20;
    int choice;
    int NumbersB[SIZE];
    int NumbersS[SIZE];
    
    //fill the arrays
    fillArr1(NumbersB,SIZE);
    fillArr1(NumbersS,SIZE);
    
    //print the arrays
    printArr(NumbersB, SIZE);
    printArr(NumbersS, SIZE);
    
    //call sorting functions
    bubSort(NumbersB,SIZE);
    selSort(NumbersS,SIZE);
}
void prob10(){
    //set random number seed
    srand(static_cast<int>(time(NULL)));
    
    //declare variables
    const int SIZE=8;
    int Num1[SIZE];
    int Num2[SIZE];
    
    //fill the arrays
    fillArr(Num1,SIZE);
    fillArr(Num2,SIZE);
    
    //call sorting functions
    bubSort1(Num1, SIZE);
    selSort1(Num2,SIZE);
}

bool searchArr(int a[], int S, int Num){
    for(int i=0;i<=S;i++){
        if(a[i]==Num){
            return true;
        }
    }
    return false;
}

bool biSearchArr(int a[], int S, int Num){
    int first=0;
    int last=S-1;
    int middle;
    bool found=false;
    
    mrkSort(a,S);
    
    while(first<=last&&!found){
        middle=(first+last)/2;
        if(a[middle]==Num){
            found=true;
            return found;
        }
        else if(a[middle]>Num){
            last=middle-1;
        }
        else{
            first=middle+1;
        }
    }
    
    return found;
}

void mrkSort(int a[], int n){
    //nested for loop 
    for(int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if(a[i]<a[j]){
                a[i]=a[i]^a[j];
                a[j]=a[i]^a[j];
                a[i]=a[i]^a[j];
            }
        }
    }
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

void showArry(string arr[], int S){
    for(int i=0;i<S;i++){
        cout<<"Name #"<<i+1<<": "<<arr[i]<<endl;
    }
}
    
void selectSort(string str[], int S){
    int startScan, minIndex, minValue;
    string strMinIndex, strMinValue;
    
    for(startScan=0;startScan<(S-1);startScan++){
        minIndex=startScan;
        minValue=startScan;
        strMinIndex=str[startScan];
        strMinValue=str[startScan];
        for(int index=startScan+1;index<S;index++){
            if(str[index]<=strMinValue){
                minValue=index;
                minIndex=index;
                strMinValue=str[index];
                strMinIndex=str[index];
            }
        }
        str[minIndex]=str[startScan];
        str[startScan]=strMinValue;
    }
}
   
void bubbleSort(string strArr[], int S){
    bool swap;
    string temp;
    
    do{
        swap=false;
        for(int count=0;count<(S-1);count++){
            if(strArr[count]>strArr[count+1]){
                temp=strArr[count];
                strArr[count]=strArr[count+1];
                strArr[count+1]=temp;
                swap=true;
            }
        }
    }while(swap);
}

void biSearch(string str[], int S){
    bubbleSort(str,S);
}
void fillArr1(int a[], int b){
    for(int i=0;i<=b;i++){
        a[i]=i+1;
    }
}
void printArr(int a[], int b){
    for(int i=0;i<=b;i++){
        cout<<a[i]<<endl;
    }
}
bool biSearchArr1(int a[], int S, int Num){
    int first=0;
    int last=S-1;
    int middle;
    int count=0;
    bool found=false;
    
    mrkSort(a,S);
    
    while(first<=last&&!found){
        middle=(first+last)/2;
        if(a[middle]==Num){
            found=true;
            cout<<"Binary Search used "<<count<<"comparisons!"<<endl;
            return found;
        }
        else if(a[middle]>Num){
            last=middle-1;
        }
        else{
            first=middle+1;
        }
        count++;
    }
    cout<<"Binary Search used "<<count<<" comparisons!"<<endl;
    return found;
}
bool linSearchArr(int a[], int S, int Num){
    bool isFound=false;
    int count=0;
    
    for(int i=0;i<=S;i++){
        if(a[i]==Num){
            isFound==true;
            cout<<"Linear Search used "<<count<<" comparisons!"<<endl;
            return isFound;
        }
        count++;
    }
    cout<<"Linear Search used "<<count<<"comparisons!"<<endl;
    return isFound;
}
void bubSort(int a[], int b){
    bool swap;
    int temp;
    int counter=0;
    
    do{
        swap=false;
        for(int count=0; count<(b);count++){
            if(a[count]>a[count+1]){
                temp=a[count];
                a[count]=a[count+1];
                a[count+1]=temp;
                swap=true;
                counter++;
            }
        }
    }while(swap);
    
    cout<<"Bubble Sort used "<<counter<<" exchanges."<<endl;
}

void selSort(int a[], int b){
    int startScan, minIndex, minValue;
    int counter=0;
    
    for(startScan=0;startScan<(b-1);startScan++){
        minIndex=startScan;
        minValue=a[startScan];
        for(int index=startScan+1;index<b;index++){
            if(a[index]<minValue){
                minValue=a[index];
                minIndex=index;
                counter++;
            }
        }
        a[minIndex]=a[startScan];
        a[startScan]=minValue;
    }
    cout<<"Selection Sort used "<<counter<<" exchanges"<<endl;
}
void fillArr(int a[], int b){
    for(int i=0;i<=b;i++){
        a[i]=rand()%10000+1;
    }
}
void bubSort1(int a[], int b){
    bool swap;
    int temp;
    int counter=0;
    
    do{
        swap=false;
        for(int count=0; count<(b);count++){
            if(a[count]>a[count+1]){
                temp=a[count];
                a[count]=a[count+1];
                a[count+1]=temp;
                swap=true;
                counter++;
                cout<<"Array after "<<counter<<" exchanges with Bubble Sort: "<<endl;
                printArr(a,b);
            }
        }
    }while(swap);
}

void selSort1(int a[], int b){
    int startScan, minIndex, minValue;
    int counter=0;
    
    for(startScan=0;startScan<(b-1);startScan++){
        minIndex=startScan;
        minValue=a[startScan];
        for(int index=startScan+1;index<b;index++){
            if(a[index]<minValue){
                minValue=a[index];
                minIndex=index;
                counter++;
                cout<<"Array after "<<counter<<" exchanges with Selection Sort: "<<endl;
                printArr(a,b);
            }
        }
        a[minIndex]=a[startScan];
        a[startScan]=minValue;
    }
}