/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on April 27, 2016, 10:01 AM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
//Book asked for Global constant of liters per gallon
const float LITERS_PER_GALLON=3.78541;

//menu function
void menu();

//problems
//Gaddis_7thEd_CH6_P1
void prob1();
//Gaddis_7thEd_CH6_P7
void prob2();
//Gaddis_7thEd_CH6_P10
void prob3();
//Gaddis_7thEd_CH6_P11
void prob4();
//Gaddis_7thEd_CH6_P14
void prob5();
//Gaddis_7thEd_CH6_P21
void prob6();
//Gaddis_7thEd_CH6_P22
void prob7();
//Gaddis_7thEd_CH6_P23
void prob8();
//Savitch_9thEd_CH4_P2
void prob9();
//Savitch_9thEd_CH4_P4
void prob10();

//functions for problem 1
float calculateRetail(float num, float perc);

//functions for problem 2
float celsius(float conv);

//functions for problem 3
void getscore(int &score);
void calcAverage(int score1, int score2, int score3, int score4, int score5);
int findLowest(int l1, int l2, int l3, int l4, int l5);

//functions for problem 4
void getJudgeData(float &score);
void calcScore(float score1, float score2, float score3, float score4, float score5);
float findLowest(float l1, float l2, float l3, float l4, float l5);
float findHighest(float h1, float h2, float h3, float h4, float h5);

//functions for problem 5
float getCharges(int days, float rate, float med, float serv);
float getCharges(float med, float serv);

//functions for problem 6
bool isPrime21(int num);

//functions for problem 7
void isPrime(int num);

//functions for problem 8
unsigned short computer();
unsigned short player();
bool winner(unsigned short computer, unsigned int player);

//functions for problem 9
float calcMPG(int liters,int miles);

//functions for problem 10
float calcInflation(float past, float current);



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

//menu function
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

//problems
void prob1(){
    //variables
    float rCost=0.00f, mPerc=0.00f, wCost=0.00f;
    
    //inputs
    cout<<"Lets calculate the retail cost of a good."<<endl;
    cout<<"What is the wholesale cost of the good?"<<endl;
    cin>>rCost;
    
    cout<<"What is the markup? (This should be in %)"<<endl;
    cin>>mPerc;
    
    //Convert to a decimal
    mPerc/=100.00f;
    
    //send to function
    wCost = calculateRetail(rCost, mPerc);
    
    //output result
    cout<<"This good costs "<<setprecision(2)<<fixed<<rCost<<" wholesale.";
    cout<<" With a "<<setprecision(2)<<fixed<<mPerc*100<<"% markup it costs:"<<endl;
    cout<<setprecision(2)<<fixed<<wCost;
}
void prob2(){
    //variables
    float fTemp=0.00f, cTemp=0.00f;
    
    //output
    cout<<"Lets convert a range of Fahrenheit temps to Celsius!"<<endl;
    cout<<"What is the first temp you would like like to see?"<<endl;
    cin>>fTemp;
    
    cout<<"Here are the converted temperatures:"<<endl;

    //loop for multiple conversions 
    for(int i=0;i<=20;i++){
        //call the function and assign return to cTemp
        cTemp = celsius(fTemp+i);
        
        //output the results
        cout<<setprecision(2)<<fixed<<fTemp+i;
        cout<<" degree Fahrenheit is ";
        cout<<setprecision(2)<<fixed<<cTemp<<" degree celsius."<<endl;
    }
}
void prob3(){
    //variables
    int s1=0,s2=0,s3=0,s4=0,s5=0,average=0;
    
    cout<<"We are going to take in five scores, calculate the average";
    cout<<" of the four highest scores. Scores must be between 0 and 100."<<endl;
    
    getscore(s1);
    cout<<"The first score is "<<s1<<endl;;
    
    getscore(s2);
    cout<<"The second score is "<<s2<<endl;
    
    getscore(s3);
    cout<<"The third score is "<<s3<<endl;
    
    getscore(s4);
    cout<<"the fourth score is "<<s4<<endl;
    
    getscore(s5);
    cout<<"the fifth score is "<<s5<<endl;
    
    calcAverage(s1,s2,s3,s4,s5);
}
void prob4(){
    //variables
    float jScore1=0.00f, jScore2=0.00f, jScore3=0.00f, jScore4=0.00f, jScore5=0.00f;
    
    //Get each of the judges scores, and store them into their variables
    getJudgeData(jScore1);
    cout<<"The First judge's score is: "<<jScore1<<endl;
    
    getJudgeData(jScore2);
    cout<<"The Second judge's score is: "<<jScore2<<endl;
    
    getJudgeData(jScore3);
    cout<<"The Third judge's score is: "<<jScore3<<endl;
    
    getJudgeData(jScore4);
    cout<<"The Fourth judge's score is: "<<jScore4<<endl;
    
    getJudgeData(jScore5);
    cout<<"The Fifth judge's score is: "<<jScore5<<endl;
    
    calcScore(jScore1, jScore2, jScore3, jScore4, jScore5);
}
void prob5(){
    //variables
    char type=0;
    int nDays=0;
    float dRate=0.00f, mCharges=0.00f, sCharges=0.00f, total=0.00f;
    
    //output, check to see if patient is in or out
    cout<<"Lets calculate the charges for your medical stay!"<<endl;
    cout<<"Are you an in-patient(1), or an outpatient(2)?"<<endl;
    cin>>type;
    
    switch(type){
        //in-patient expense calculation
        case'1':
            cout<<"For in-patient we need the following expenses:\n\n"<<endl;;
            
            //number of days during the stay
            cout<<"How many days were you in the hospital?"<<endl;
            cin>>nDays;
            
            //validate
            while(nDays<1){
                cout<<"Invalid Input!"<<endl;
                cout<<"How many days were you in the hospital?"<<endl;
                cin>>nDays;
            }
            
            //the daily rate
            cout<<"What is the daily rate?"<<endl;
            cin>>dRate;
            
            //validate
            while(dRate<1){
                cout<<"Invalid Input!"<<endl;
                cout<<"What is the daily rate?"<<endl;
                cin>>dRate;
            }
            
            //medication charges
            cout<<"What were your hospital medication charges? (enter 0 if none)"<<endl;
            cin>>mCharges;
            
            //validate
            //validate
            while(mCharges<1){
                cout<<"Invalid Input!"<<endl;
                cout<<"What were your hospital medication charges? (enter 0 if none)"<<endl;
                cin>>mCharges;
            }
            
            //Hospital services charges
            cout<<"What were your hospital service charges? (enter 0 if none)"<<endl;
            cin>>sCharges;
            
             while(sCharges<1){
                cout<<"Invalid Input!"<<endl;
                cout<<"What were your hospital service charges? (enter 0 if none)"<<endl;
                cin>>sCharges;
            }
            
            //call function with data that was input
            total=getCharges(nDays, dRate, mCharges, sCharges);
            
            //output the result
            cout<<"Your total Charges are: "<<setprecision(2)<<fixed<<total<<"$"<<endl;
            break;
            
        //out-patient expense calculation
        case '2':
            cout<<"For out-patient we need the following expenses:";
            
            //medication charges
            cout<<"What were your hospital medication charges? (enter 0 if none)"<<endl;
            cin>>mCharges;
            
            //validate
            //validate
            while(mCharges<1){
                cout<<"Invalid Input!"<<endl;
                cout<<"What were your hospital medication charges? (enter 0 if none)"<<endl;
                cin>>mCharges;
            }
            
            //Hospital services charges
            cout<<"What were your hospital service charges? (enter 0 if none)"<<endl;
            cin>>sCharges;
            
             while(sCharges<1){
                cout<<"Invalid Input!"<<endl;
                cout<<"What were your hospital service charges? (enter 0 if none)"<<endl;
                cin>>sCharges;
            }
            
            //call function with the data that was input
            total=getCharges(mCharges, sCharges);
            
            //output the result
            cout<<"Your total Charges are: "<<setprecision(2)<<fixed<<total<<"$"<<endl;
            break;
    }
}
void prob6(){
    //variables
    int input=0;
    bool result=true;
    
    //get the number from the user
    cout<<"This program is going to check to see a number is a prime number"<<endl;
    cout<<"What number would you like to check?"<<endl;
    cin>>input;
    
    //call the funtion
    result=isPrime21(input);
    
    //let user know the result
    if (result=1){
        cout<<input<<" is not a prime number!"<<endl;
    }
    else {
        cout<<input<<" is not a prime number!"<<endl;
    }
}
void prob7(){
    //variables
    int input=0;
    bool result=true;
    
    //open the output file and create the file stream object
    ofstream outputFile;
    outputFile.open("primes.txt");
    
    //get the number from the user
    cout<<"This program is going to output all of the prime numbers up to"<<endl;
    cout<<"the number that you give it into a file called prime.txt!"<<endl;
    cout<<"What is the upper limit you would like to check for prime numbers?"<<endl;
    cin>>input;
    
    //call the function
    isPrime(input);
}
void prob8(){
    //variables
    //1=rock,2=paper,3=scissors
    unsigned short cChoice=1,uChoice=1;
    bool tie=true;
    
    //enter the loop, if not tie then break the loop
    while(tie==true){
        //get the computers choice
        cChoice=computer();
        uChoice=player();

        //determine winner
        tie=winner(cChoice,uChoice);
    }
}
void prob9(){
    char choice;
    int gas1=0,dist1=0,gas2=0,dist2=0;
    float MPG1,MPG2;
    do{
        cout<<"Lets calculate the MPG of 2 vehicles!"<<endl;
        
        //read in the amount of liters
        cout<<"How many liters has the first car consumed?"<<endl;
        cin>>gas1;
        
        //read in the number of miles
        cout<<"How far has the first car gone, in miles?"<<endl;
        cin>>dist1;
        
        //read in the amount of liters
        cout<<"How many liters has the second car consumed?"<<endl;
        cin>>gas2;
        
        //read in the number of miles
        cout<<"How far has the second car gone, in miles?"<<endl;
        cin>>dist2;
        
        //call the function
        MPG1=calcMPG(gas1,dist1);
        MPG2=calcMPG(gas2,dist2);
        
        //output result
        cout<<"First MPG is:"<<setprecision(3)<<MPG1<<endl;
        cout<<"Second MPG is:"<<setprecision(3)<<MPG2<<endl;
        
        if (MPG1>MPG2){
            cout<<"The first car has better gas milage!"<<endl;
        }
        else if (MPG1<MPG2){
            cout<<"The Second car has better gas milage!"<<endl;
        }
        
        //ask user if the calculation wants to be done again
        cout<<"Do you want to do another calculation: Yes(1) or No (2)?"<<endl;
        cin>>choice;
    }while(choice=='1');
}
void prob10(){
    //variables
    float inflation=0.00f,cPrice=0, pPrice=0;
    
    //get the current price 1 year ago
    cout<<"We are going to calculate the inflation of a good in this game"<<endl;
    cout<<"What was the price of the good 1 year ago?"<<endl;
    cin>>pPrice;
    
    //get the current price of the good
    cout<<"What was the price of the good today?"<<endl;
    cin>>cPrice;
    
    //call the function
    inflation=calcInflation(pPrice,cPrice);
    
    cout<<"Inflation on this good is "<<inflation<<"%"<<endl;
}

//functions for problem 1
float calculateRetail(float num, float perc){
    return (num+(num*perc));
}

//functions for problem 2
float celsius(float conv){
    return  ((5.00/9.00)*(conv-32)); 
}

//functions for problem 3
//get the scores
void getscore(int &score){
    //first try 
    cout<<"Please enter a score!";
    cin>>score;
    
    //if the user did not follow the rules
    while(score<=-1 || score>=101){
        
        //get valid user input
        cout<<"The score must be between 0 and 100"<<endl;
        cout<<"Please enter a valid score!"<<endl;
        cin>>score;
    }
}

//calculating the average
void calcAverage(int score1, int score2, int score3, int score4, int score5){
    
    //declare local variables
    int drop=0,sum=0,avg=0;
    
    //figure out what value is the lowest, then put into variable drop
    drop=findLowest(score1, score2, score3, score4, score5);
    
    cout<<drop<<endl;
    //sum all of the inputs, then subtract the smallest with variable drop
    sum=(score1+score2+score3+score4+score5)-drop;
    
    //calculate the average
    avg=sum/4;
    
    //output the average
    cout<<"The average of the five scores is: "<<avg<<endl;
}

//finding the lowest number of the bunch
int findLowest(int l1, int l2, int l3, int l4, int l5){

    //assign the lowest value to the first
    int lowest=l1;
    
    //compare to the second value
    if(lowest>l2){
        lowest=l2;
    }
    
    //compare to the third value
    if(lowest>l3){
        lowest=l3;
    }
    
    //compare to the fourth value
    if(lowest>l4){
        lowest=l4;
    }
    
    //compare to the fifth value
    if(lowest>l5){
        lowest=l5;
    }
    
    //output the lowest value
    cout<<"The smallest score is "<<lowest<<endl;
    
    //return the lowest value
    return lowest;
}

//functions for problem 4
//ask the judges for their score
void getJudgeData(float &score){
    //first try 
    cout<<"Please enter a score Judge!";
    cin>>score;
    
    //if the user did not follow the rules
    while(score<0 || score>10){
        
        //get valid user input
        cout<<"The score must be between 0 and 10"<<endl;
        cout<<"Please enter a valid score!"<<endl;
        cin>>score;
    }
}

//calculating the score, requires that we call the findLowest and findHighest 
//functions and remove the highest and lowest scores
void calcScore(float score1, float score2, float score3, float score4, float score5){
    
    //Put the highest and lowest scores into these variables
    float hRemove=0.00f, lRemove=0.00f, avg=0.00f;

    //find the highest and lowest
    hRemove=findHighest(score1, score2, score3, score4, score5);
    lRemove=findLowest(score1, score2, score3, score4, score5);
    
    //calculate the average, subtracting the largest and highest scores
    avg=((score1+score2+score3+score4+score5)-hRemove-lRemove)/(static_cast<float>(3));
    cout<<"The total score is: "<<setprecision(2)<<fixed<<avg<<endl;
}

//find the lowest score
float findLowest(float l1, float l2, float l3, float l4, float l5){
    
    //assign the lowest value to the first
    float lowest=l1;
    
    //compare to the second value
    if(lowest>l2){
        lowest=l2;
    }
    
    //compare to the third value
    if(lowest>l3){
        lowest=l3;
    }
    
    //compare to the fourth value
    if(lowest>l4){
        lowest=l4;
    }
    
    //compare to the fifth value
    if(lowest>l5){
        lowest=l5;
    }
    
    //output the lowest value
    cout<<"The lowest score is: "<<setprecision(2)<<fixed<<lowest<<endl;
    
    //return the lowest value
    return lowest;
}

//find the highest scores
float findHighest(float h1, float h2, float h3, float h4, float h5){
    //assign the lowest value to the first
    float highest=h1;
    
    //compare to the second value
    if(highest<h2){
        highest=h2;
    }
    
    //compare to the third value
    if(highest<h3){
        highest=h3;
    }
    
    //compare to the fourth value
    if(highest<h4){
        highest=h4;
    }
    
    //compare to the fifth value
    if(highest<h5){
        highest=h5;
    }
    
    //output the lowest value
    cout<<"The highest score is: "<<setprecision(2)<<fixed<<highest<<endl;
    
    //return the lowest value
    return highest;
}

//functions for problem 5
float getCharges(int days, float rate, float med, float serv){
    
    //local variable to hold data
    float tot=0.00f;
    
    //calculations
    tot=((static_cast<float>(days)*rate)+med+serv);
    
    //return data
    return tot;
}
float getCharges(float med, float serv){
    
    //variable to hold local data
    float tot=0.00f;
    
    //calculation
    tot=med+serv;
    
    //return data
    return tot;
}

//functions for problem 6
bool isPrime21(int num){
    //set the first divisable number to n-1, subtract until it goes to 2
    for (int i=(num-1);i>1;i--){
        if(num%i==0){
            return false;
        }
    }
    return true;
}

//functions for problem 7
void isPrime(int num){
    //set the first divisable number to n-1, subtract until it goes to 2
    ofstream outputFile;
    outputFile.open("primes.txt");
    
    //begin the loop
    start:while(num>=1){
        for(int i=(num-1);i>1;i--){
            if(num%i==0){
                num--;
                goto start;
            }
        }
        outputFile<<num<<" ";
        num--;
    }
    outputFile.close();
}

//functions for problem 8
unsigned short computer(){
    //setting random number seed for AI
    srand(static_cast<unsigned int>(time(0)));
    return (rand()%3+1);
}
unsigned short player(){
    
    //make variables to store data and return
    unsigned short choice=0;
    
    //get the user input
    cout<<"Lets play rock paper scissors!"<<endl;
    cout<<"Enter (1)=rock, (2)=paper, and (3)=scissors"<<endl;
    cin>>choice;
    
    //make sure the number is between 1 and 3
    while(choice>=4||choice<=0){
        cout<<"Not a valid input!"<<endl;
        cout<<"Try again: Enter (1)=rock, (2)=paper, and (3)=scissors"<<endl;
        cin>>choice;
    }
    
    //confirm the choice for user's benefit
    switch(choice){
        case 1:
            cout<<"You have chosen Rock"<<endl;
            break;
        case 2:
            cout<<"You have chosen Paper"<<endl;
            break;
        case 3:
            cout<<"You have chosen Paper"<<endl;
            break;
    }
    
    //return value to use in winner function
    return choice;
}
bool winner(unsigned short computer, unsigned int player){
    
    //output computer's choice
    switch(computer){
        case 1:
            cout<<"The computer has chosen Rock"<<endl;
            break;
        case 2:
            cout<<"The computer has chosen Paper"<<endl;
            break;
        case 3:
            cout<<"The computer has chosen Scissors"<<endl;
            break;
    }
    
    //player wins
    if (computer==3&&player==1){
        cout<<"Rock smashes the Scissors!"<<endl;
        cout<<"You win!"<<endl;
        
        //return false to end the loop
        return false;
    }
    
    else if(computer==2&&player==3){
        cout<<"Scissors cuts Paper!"<<endl;
        cout<<"You win!"<<endl;
        
        //return false to end the loop
        return false;
    }
    else if(computer==1&&player==2){
        cout<<"Paper covers Rock!"<<endl;
        cout<<"You win!"<<endl;
        
        //return false to end the loop
        return false;
    }
    
    //computer wins
    else if(computer==3&&player==1){
        cout<<"Rock smashes the Scissors!"<<endl;
        cout<<"Computer wins!"<<endl;
        
        //return false to end the loop
        return false;
    }
    else if(computer==3&&player==2){
        cout<<"Scissors cuts Paper!"<<endl;
        cout<<"Computer wins!"<<endl;
        
        //return false to end the loop
        return false;
    }
    else if (computer==2&&player==1){
        cout<<"Paper covers Rock!"<<endl;
        cout<<"Computer wins!"<<endl;
        
        //return false to end the loop
        return false;
    }
    
    //for a tie
    else{
        cout<<"It is a tie!"<<endl;
        cout<<"Play again!"<<endl;
        
        //output true to continue the loop
        return true;
    }
}

//functions for problem 9
float calcMPG(int liters,int miles){
    return (static_cast<float>(miles)/(static_cast<float>(liters)*LITERS_PER_GALLON));
}

//functions for problem 10
float calcInflation(float past, float current){
    return (current-past)*100;
}



