/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Christopher
 *
 * Created on May 18, 2016, 9:32 PM
 */

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <string>
#include <fstream>
using namespace std;
//menu function
void menu();

//Variables for Gaddis_7thEd_CH7_P15
const int ROWS=3, COL=3;

//Variables for Gaddis_7thEd_CH7_P16
const int rSIZE=3;
const int cSIZE=3;

//problems
//Gaddis_7thEd_CH7_P1
void prob1();
//Gaddis_7thEd_CH7_P3
void prob2();
//Gaddis_7thEd_CH7_P4
void prob3();
//Gaddis_9thEd_CH8_P10
void prob4();
//Gaddis_7thEd_CH7_P8
void prob5();
//Gaddis_7thEd_CH7_P13
void prob6();
//Gaddis_7thEd_CH7_P15
void prob7();
//Gaddis_7thEd_CH7_P16
void prob8();
//Gaddis_9thEd_CH8_P10
void prob9();
//Savitch_CH7_9thEd_PP2
void prob9();
//Savitch_CH7_9thEd_PP4
void prob10();

//functionsGaddis_9thEd_CH8_P10
void prntAry(char [], int, int);
int readFile(char [], char []);
int score(char [], int, char [], int);

//functions Gaddis_7thEd_CH7_P13
void fill(unsigned int [], int NUMB);
void compare(unsigned int [], unsigned int []);

//functions Gaddis_7thEd_CH7_P15
//function to output the board array
void outputBoard(char [ROWS][COL]);
bool grade(char [ROWS][COL]);

//functions Gaddis_7thEd_CH7_P16
int getTotal(int [rSIZE][cSIZE], int, int);
int getAverage(int [rSIZE][cSIZE] , int, int);
int getRowTotal(int [rSIZE][cSIZE], int);
int getColumnTotal(int [rSIZE][cSIZE], int);
int getHighestInRow(int [rSIZE][cSIZE], int);
int getLowestInRow(int [rSIZE][cSIZE], int);

//functions Savitch_CH7_9thEd_PP2
void countNum2s(int a[], int size);

//functions Savitch_CH7_9thEd_PP4
string lookupName(string Name, string lNames[], string lPhones[]);

int main(int argc, char** argv) {
    //Declare the loop variable
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

//Gaddis_7thEd_CH7_P1
void prob1(){
    //variables
    const int SIZE=10;
    int getVal[SIZE];
    int Large, Small;
    
    //get the user to fill the array
    for (int i=0;i<=(SIZE-1);i++){
        cout<<"Enter the "<<i+1<<" element in the Array"<<endl;
        cin>>getVal[i];
    }
    //initialize the smallest and largest values
    Large=getVal[0];
    Small=getVal[0];
    
    for(int j=0;j<SIZE;j++){
        if(getVal[j]>Large)Large=getVal[j];
        if(getVal[j]<Small)Small=getVal[j];
    }
    cout<<"This is the smallest number:"<<Small<<endl;
    cout<<"This is the largest number:"<<Large<<endl;
}

//Gaddis_7thEd_CH7_P3
void prob2(){
    //variables
    const int SIZE=5;
    string salsas[]={"mild", "medium", "sweet", "hot", "zesty"};
    int jars[SIZE];
    int nLar=-1, nSmall=10000;
    string large=" ", small=" ";
    
    //use for loop to get the variables
    cout<<"Lets see which of the following salsas had the most jars sold!"<<endl;
    for(int i=0;i<SIZE;i++){
        cout<<"How many jars of "<<salsas[i]<<" were sold?"<<endl;
        cin>>jars[i];
        while(jars[i]<0){
            cout<<"Incorrect Input! No Negative Numbers"<<endl;
            cout<<"Try again..."<<endl;
            cin>>jars[i];
        }
        
        //determine the largest and smallest
        if(jars[i]>nLar){
            large=salsas[i];
            nLar=jars[i];
        }
        if(jars[i]<nSmall){
            small=salsas[i];
            nSmall=jars[i];
        }
    }
    
    //print the data
    for(int j=0;j<SIZE;j++){
        cout<<salsas[j]<<":     "<<jars[j]<<endl;
    }
    cout<<"The best seller: "<<large<<endl;
    cout<<"The worst seller: "<<small<<endl;
}

//Gaddis_7thEd_CH7_P4
void prob3(){
    //Declare the arrays that will hold the information
    const int N_MONKS=3, N_DAYS=7,N_OUTPUTS=3;
    int lbsFood[N_MONKS][N_DAYS];
    int OUTPUTS[N_OUTPUTS]={0, 10000, 0};
    
    cout<<"Lets calculate the number of lbs of food that the Monkies are eating!"<<endl;
    cout<<"Monkey 1: George\nMonkey 2: Marvin\nMonkey 3: Al"<<endl;
    
    for(int i=0;i<N_MONKS;i++){
        
        //re-initialize j so we can fill the array properly
        int j=0;
        
        for(;j<N_DAYS;j++){
            
            //make user know which monkey's data is being entered
            switch(i){
                
                case 0:{
                    cout<<"Enter the number of lbs of food George ate on day "<<j+1<<endl;
                    cin>>lbsFood[i][j];

                    //data validation
                    while(lbsFood[i][j]<0){
                        cout<<"Invalid Input.... Try again!";
                        cin>>lbsFood[i][j];
                    }
                    break;
                }
                case 1:{
                    cout<<"Enter the number of lbs of food Marvin ate on day "<<j+1<<endl;
                    cin>>lbsFood[i][j];

                    //data validation
                    while(lbsFood[i][j]<0){
                        cout<<"Invalid Input.... Try again!";
                        cin>>lbsFood[i][j];
                    }
                    break;
                }
                case 2:{
                    cout<<"Enter the number of lbs of food Al ate on day "<<j+1<<endl;
                    cin>>lbsFood[i][j];

                    //data validation
                    while(lbsFood[i][j]<0){
                        cout<<"Invalid Input.... Try again!";
                        cin>>lbsFood[i][j];
                    }
                    break;
                }
                default:{
                    cout<<"Something went wrong..."<<endl;
                    break;
                }
            }
            
            //check to see if the inputs qualify as smallest or largest respectively
            OUTPUTS[0]+=lbsFood[i][j];
            if(lbsFood[i][j]<OUTPUTS[1])OUTPUTS[2]=lbsFood[i][j];
            if(lbsFood[i][j]>OUTPUTS[2])OUTPUTS[2]=lbsFood[i][j];
        }
    }
    
    //outputs
    cout<<"The average amount of food consumed was: "<<OUTPUTS[0]/21<<endl;
    cout<<"The smallest amount of food consumed was: "<<OUTPUTS[1]<<endl;
    cout<<"The largest amount of food consumed was: "<<OUTPUTS[2]<<endl;
}
//Gaddis_7thEd_CH7_P6
void prob4(){
    //variables
    const int SIZE=100;
    char answers[SIZE];
    char user[SIZE];
    
    //open the file
    char fnAns[]="answerKey.dat";
    int nAnswers=readFile(fnAns, answers);
    char fnUser[]="UserAns.dat";
    int nUser=readFile(fnUser, user);
    
    //print the array
    cout<<"The Answer Key"<<endl;
    prntAry(answers, nAnswers, 10);
    
    cout<<"The User Answers"<<endl;
    prntAry(user, nUser, 10);
    
    //calculate the results
    int results=score(answers, nAnswers, user, nUser);
    
    //output the scores
    cout<<"Score="<<results<<" right -> "<<1.0f*results/nAnswers*100<<"%"<<endl;
}

//Gaddis_7thEd_CH7_P8
void prob5(){
    //variables
    const int SIZE=7;
    long int empID[SIZE]={5658845, 4520125, 7895122, 8777541, 8451277, 1302850, 7580489};
    int hours[SIZE];
    int payRate[SIZE];
    int wages[SIZE];
    
    cout<<"Lets calculate employee wages!"<<endl;
    
    //for loop to get the wages
    for(int i=0;i<SIZE;i++){
        cout<<"Employee ID #: "<<empID[i]<<endl;
        cout<<"Enter number of hours: "<<endl;
        cin>>hours[i];
        cout<<"Enter the pay rate per hour"<<endl;
        cin>>payRate[i];
        wages[i]=hours[i]*payRate[i];
    }
    
    cout<<"Wages for Employees"<<endl;
    
    for(int j=0;j<SIZE;j++){
        cout<<empID[j]<<": "<<wages[j]<<endl;;
    }
}
void prob6(){
    //set random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //variables
    const int SIZE=5;
    unsigned int lotArr[SIZE];
    unsigned int userArr[SIZE];
    
    //fill the arrays
    fill(lotArr, SIZE);
    fill(userArr, SIZE);
    
    //print the arrays
    cout<<"The lottery numbers are:     ";
    for(int j=0;j<SIZE;j++){
        cout<<lotArr[j];
    }
    cout<<endl;
    
    cout<<"The user numbers are:        ";
    for(int j=0;j<SIZE;j++){
        cout<<userArr[j];
    }
    cout<<endl;
    
    //compare the arrays to see if there is a winner
    compare(lotArr,userArr);
}

void prob7(){
    //variables
    bool finish=false;
    char board[ROWS][COL]={ 
                                {'*','*','*'},
                                {'*','*','*'},
                                {'*','*','*'}
                              };
    
    cout<<"Lets play a game of Tic-Tac-Toe"<<endl;
    cout<<"Player 1 is X"<<endl;
    cout<<"Player 2 is O"<<endl;
    
    outputBoard(board);
    
    cout<<"If you enter numbers outside the bounds of the board, you lose your turn!"<<endl;
    
    while(finish==false){
        int p1Col=0,p1Row=0,p2Col=0,p2Row=0;
        //get the player 1 information
        cout<<"Player 1 Enter the Row"<<endl;
        cin>>p1Row;
        cout<<"Player 1 Enter the column"<<endl;
        cin>>p1Col;
        
        //input validation
        while(board[p1Row][p1Col]=='X'||board[p1Row][p1Col]=='O'){
            cout<<"Invalid Input, try again!"<<endl;
            cout<<"Player 1 Enter the Row"<<endl;
            cin>>p1Row;
            cout<<"Player 1 Enter the column"<<endl;
            cin>>p1Col;
        }
        
        //insert user info into table
        board[p2Row][p2Col]='X';
        
        //show user the board
        outputBoard(board);
        
        //check to see if player 1won on this turn
        if(finish=grade(board)){
            cout<<"Player 1 has won!"<<endl;
            break;
        }
        
        //get the player 2 information
        cout<<"Player 2 Enter the Row"<<endl;
        cin>>p2Row;
        cout<<"Player 2 Enter the column"<<endl;
        cin>>p2Col;
        
        //input validation
        while(board[p2Row][p2Col]=='X'||board[p2Row][p2Col]=='O'){
            cout<<"Invalid Input, try again!"<<endl;
            cout<<"Player 2 Enter the Row"<<endl;
            cin>>p2Row;
            cout<<"Player 2 Enter the column"<<endl;
            cin>>p2Col;
        }
        
        //insert user info into table
        board[p2Row][p2Col]='O';
        
        //show user the board
        outputBoard(board);
        
        //check to see if player 2 has won the game
        if(finish=grade(board)){
            cout<<"Player 2 has won!"<<endl;
            break;
        }
        
    }
}

void prob8(){
    //Set the random number seed for variability
    srand(static_cast<unsigned int>(time(0)));
    
    //variables
    const int rSIZE=3;
    const int cSIZE=3;
    int Array[rSIZE][cSIZE];
    int rChoice=0,cChoice=0, total=0,average=0,rowTotal=0,colTotal=0, getRowH=0, getRowL=1000;
    
    //fill the array
    for(int i=0;i<rSIZE;i++){
        for(int j=0;j<cSIZE;j++){
            Array[i][j]=rand()%90+10;
            cout<<Array[i][j]<<" ";
        }
        cout<<endl;
    }
    
    //get the user input on the row they would like to do operations on
    cout<<"What row would you like to do operations on?"<<endl;
    cin>>rChoice;
    while(rChoice<rSIZE||rChoice>rSIZE){
        cout<<"Invalid Input!"<<endl;
        cout<<"What row would you like to do operations on?"<<endl;
        cin>>rChoice;
    }
    
    //get the column they would like to do operations on
    cout<<"What column would you like to do operations on?"<<endl;
    cin>>cChoice;
    while(cChoice<cSIZE||cChoice>cSIZE){
        cout<<"Invalid Input!"<<endl;
        cout<<"What row would you like to do operations on?"<<endl;
        cin>>cChoice;
    }
    
    //make sure it translate to an actually array index
    rChoice-=1;
    cChoice-=1;
    
    //calling functions
    total=getTotal(Array, rSIZE, cSIZE);
    average=getAverage(Array, rSIZE, cSIZE);
    rowTotal=getRowTotal(Array, rChoice);
    colTotal=getColumnTotal(Array, cChoice);
    getRowH=getHighestInRow(Array, rChoice);
    getRowL=getLowestInRow(Array, rChoice);
            
    //output the functions 
    cout<<"Total: "<<total<<endl;
    cout<<"Average: "<<average<<endl;
    cout<<"Row "<<rChoice+1<<" Total: "<<rowTotal<<endl;
    cout<<"Column "<<cChoice+1<<" Total: "<<colTotal<<endl;
    cout<<"Row "<<rChoice+1<<" Highest: "<<getRowH<<endl;
    cout<<"Row "<<rChoice+1<<" Lowest: "<<getRowL<<endl;
}

void prob9(){
    //variables
    int userInput[5], howBig=5;
    unsigned short nTwos=0;
    
    //call the function
    countNum2s(userInput, howBig);
}

void prob10(){
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
}

void prntAry(char a[], int nIna, int perLine){
    //loop and out the array
    for(int i=0;i<nIna;i++){
        cout<<a[i];
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

int readFile(char fn[], char dat[]){
    //variables
    ifstream ansKey;
    
    //open the file
    ansKey.open(fn);
    
    //read from the file
    int n=0;
    while(ansKey>>dat[n]){dat[n++];}
    
    
    //close the file
    ansKey.close();
    
    //return the size
    return n;
}
int score(char answers[], int nAnswers, char user[], int nUser){
    int results=0;
    for(int ques=0;ques<nAnswers&&ques<nUser;ques++){
        if(answers[ques]==user[ques])results++;
    }
    return results;
}

//filling each array with a function
void fill(unsigned int a[], int NUMB){
    for(int i=0;i<NUMB;i++){
        a[i]=rand()%10;
    }
}

//compare the two arrays to see what digits they have in common
void compare(unsigned int l[], unsigned int u[]){
    int counter=0;
    
    for(int k=0;k<5;k++){
        if(l[k]==u[k]){
            cout<<"The number "<<k+1<<" is matching!"<<endl;
            counter++;
        }
    }
    
    if(counter==5){
        cout<<"YOU WON THE LOTTERY!"<<endl;
    }
    
}

void outputBoard(char a[ROWS][COL]){
    //output board
    cout<<"Columns and rows are 0-2"<<endl;
    cout<<a[0][0]<<a[0][1]<<a[0][2]<<endl;
    cout<<a[1][0]<<a[1][1]<<a[1][2]<<endl;
    cout<<a[2][0]<<a[2][1]<<a[2][2]<<endl;
}

bool grade(char a[ROWS][COL]){
    //check to see if X wins
    if((a[0][0]=='X'&&a[0][1]=='X'&&a[0][2]=='X')||
            (a[1][0]=='X'&&a[1][1]=='X'&&a[1][2]=='X')||
            (a[2][0]=='X'&&a[2][1]=='X'&&a[2][2]=='X')||
            (a[0][0]=='X'&&a[1][0]=='X'&&a[2][0]=='X')||
            (a[0][1]=='X'&&a[1][1]=='X'&&a[2][1]=='X')||
            (a[0][2]=='X'&&a[1][2]=='X'&&a[2][2]=='X')||
            (a[0][0]=='X'&&a[1][1]=='X'&&a[2][2]=='X')||
            (a[2][0]=='X'&&a[1][1]=='X'&&a[0][2]=='X')){
        return true;
    }
    else if((a[0][0]=='O'&&a[0][1]=='O'&&a[0][2]=='O')||
            (a[1][0]=='O'&&a[1][1]=='O'&&a[1][2]=='O')||
            (a[2][0]=='O'&&a[2][1]=='O'&&a[2][2]=='O')||
            (a[0][0]=='O'&&a[1][0]=='O'&&a[2][0]=='O')||
            (a[0][1]=='O'&&a[1][1]=='O'&&a[2][1]=='O')||
            (a[0][2]=='O'&&a[1][2]=='O'&&a[2][2]=='O')||
            (a[0][0]=='O'&&a[1][1]=='O'&&a[2][2]=='O')||
            (a[2][0]=='O'&&a[1][1]=='O'&&a[0][2]=='O')){
        return true;
    }
    else {
        return false;
    }
}

int getTotal(int a[rSIZE][cSIZE], int r, int c){
    int tot=0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            tot+=a[i][j];
        }
    }
    return tot;
}
int getAverage(int a[rSIZE][cSIZE], int r, int c){
    int avg=0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            avg+=a[i][j];
        }
    }
    avg=avg/(r*c);
    return avg;
}

int getRowTotal(int a[rSIZE][cSIZE], int c){
    int rtot=0;
    for(int i=0;i<cSIZE;i++){
        rtot+=a[c][i];
    }
    return rtot;
}

int getColumnTotal(int a[rSIZE][cSIZE], int c){
    int ctot=0;
    for(int i=0;i<rSIZE;i++){
        ctot+=a[i][c];
    }
    return ctot;
}
int getHighestInRow(int a[rSIZE][cSIZE], int h){
    int large=a[h][0];
    for(int i=0;i<rSIZE;i++){
        if(a[h][i]>large)large=a[h][i];
    }
    return large;
}

int getLowestInRow(int a[rSIZE][cSIZE], int h){
    int small=a[h][0];
    for(int i=0;i<rSIZE;i++){
        if(a[h][i]<small)small=a[h][i];
    }
    return small;
}

void countNum2s(int a[], int size){
    
    //local variables
    unsigned short nTwos=0;
    
    for(int i=0;i<=(size-1);i++){
        //get user input, and check to see if anything is a 2
        cout<<"Enter a score"<<endl;
        cin>>a[i];
        if(a[i]==2) nTwos++;
    }
    cout<<"The number of 2s: "<<nTwos<<endl;
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