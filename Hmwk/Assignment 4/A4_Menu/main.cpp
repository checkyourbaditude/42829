/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Christopher
 *
 * Created on April 4, 2016, 5:57 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
//global constant for litres per gallon
const float LITERS_PER_GALLON=3.78541;

//function to calculate the MPG
float calcMPG(int liters,int miles){
    return ((static_cast<float>(liters)*LITERS_PER_GALLON)/static_cast<float>(miles));
}
string song (int a){\
    //local variables
    string str;
    
    //splitting the input
    short d1=a/10;
    short d2=a%10;
    
    //checking to make sure its working correctly
    cout<<d1<<endl;
    cout<<d2<<endl;
    
    if(a==0){
        str="Zero";
    }
    //outputing the correct number
    else if(a>=10 && a<=19){
        switch(a){
            case 19:
                str="Nineteen";
                break;
            case 18:
                str="Eighteen";
                break;
            case 17:
                str="Seventeen";
                break;
            case 16:
                 str="Sixteen";
                break;
            case 15:
                 str="Fifteen";
                break;
            case 14:
                 str="Fourteen";
                break;
            case 13:
                 str="Thirteen";
                break;
            case 12:
                 str="Twelve";
                break;
            case 11:
                 str="Eleven";
                break;
            case 10:
                 str="Ten";
                break;
        }
    }
    else{
        switch(d1){
            case 9:
                str="Ninety ";
                break;
            case 8:
                str="Eighty ";
                break;
            case 7:
                str="Seventy ";
                break;
            case 6:
                str="Sixty ";
                break;
            case 5:
                str="Fifty ";
                break;
            case 4:
                str="Forty ";
                break;
            case 3:
                str="Thirty ";
                break;
            case 2:
                str="Twenty ";
                break;
            default:
                break;
        }
        switch(d2){
            case 9:
                str+="Nine";
                break;
            case 8:
                str+="Eight";
                break;
            case 7:
                str+="Seven";
                break;
            case 6:
                str+="Six";
                break;
            case 5:
                str+="Five";
                break;
            case 4:
                str+="Four";
                break;
            case 3:
                str+="Three";
                break;
            case 2:
                str+="Two";
                break;
            case 1:
                str+="One";
            default:
                break;
        }
    }
    return str;
}
float total(char c){
    switch(c){
        case 'o':{
            return 1.00;
        }
        case 'q':{
            return 0.25;
        }
        case 'd':{
            return 0.10;
        }
        case 'n':{
            return 0.05;
        }
        default:{
            return 0.00;
        }
    }
}
int main(int argc, char** argv) {

    //Declare the loop variable
    short choice;
    //General Menu Format
    do{
        //Display the selection
        cout<<"Type 1 for Gaddis_7thEd_CH5_P1"<<endl;
        cout<<"Type 2 for Gaddis_7thEd_CH5_P3"<<endl;
        cout<<"Type 3 for Gaddis_7thEd_CH5_P5"<<endl;
        cout<<"Type 4 for Gaddis_7thEd_CH5_P7"<<endl;
        cout<<"Type 5 for Gaddis_7thEd_CH5_P8"<<endl;
        cout<<"Type 6 for Gaddis_7thEd_CH5_P9"<<endl;
        cout<<"Type 7 for Gaddis_7thEd_CH5_P11"<<endl;
        cout<<"Type 8 for Gaddis_7thEd_CH5_P17"<<endl;
        cout<<"Type 9 for Gaddis_7thEd_CH5_P19"<<endl;
        cout<<"Type 10 for Gaddis_7thEd_CH5_P22"<<endl;
        cout<<"Type 11 for Savitch_9thEd_CH4_P1"<<endl;
        cout<<"Type 12 for Savitch_9thEd_CH4_P4"<<endl;
        cout<<"Type 13 for Savitch_9thEd_CH4_P6"<<endl;
        cout<<"Type anything else to quit with no solutions."<<endl;
        //Read the choice
        cin>>choice;
        //Solve a problem that has been chosen.
        switch(choice){
                case 1:{//Character '1' in Decimal
                    //Declare Variables
                    int uinput,rtot,i=0;

                    //Input
                    cout<<"This program will add up every number up to the number you enter"<<endl;
                    cin>>uinput;

                    //Make sure the number is entered correctly
                    while(uinput<=0){
                        cout<<"Please enter a number greater than zero"<<endl;
                        cin>>uinput;
                    }
                    //loop and logic portion
                    //Sums the numbers all up until uinput+1
                    if(uinput==1){
                        rtot=1;
                    }
                    else{
                        do{
                            rtot=i+1;
                            i++;
                        }while(i!=(uinput+1));
                    }
                    cout<<"This is the total: "<<rtot<<endl;
                    break;
                }
                case 2:{
                    int years=25;
                    float  rate;

                    //loop
                    cout<<"Year     Running total"<<endl;
                    for(int i=0;i<=years;i++){
                        rate+=1.5f;
                        cout<<i<<"      "<<rate<<endl;
                    }
                    break;
                }
                case 3:{//Character '3' in Hex
                    //Delcare Variables
                    int years=6;
                    float mfeeup=0.04f, mfee=2500;

                    //Loop in order to output the values of the increase per year
                    for(int i=0;i<=years;i++){
                        mfee=(mfeeup*mfee)+mfee;
                        cout<<"In year "<<i<<" The increase will be to "<<mfee<<" dollars"<<endl;
                    }
                    break;
                }
                case 4:{
                    //Declare Variables
                    int ndays;
                    float np=0.01;

                    //Inputs
                    cout<<"How many days do you want to work?"<<endl;
                    cin>>ndays;

                    //loop
                    for(int i=1;i<=ndays;i++){
                        //set the precision, put the operation after the output
                        //this allowsthe day 1 to be at 0.01 cents

                        cout<<fixed<<setprecision(2);
                        cout<<"Day "<<i<<": $"<<np<<endl;
                        np*=2;
                    }
                    break;
                }
                case 5:{
                    int menu,sans ,ansa,anss,ansm,ansd,r1,r2;
                    do{
                        cout<<"Menu:"<<endl;
                        cout<<"1. Addition"<<endl;
                        cout<<"2. Subtraction"<<endl;
                        cout<<"3. Multiplication"<<endl;
                        cout<<"4. Division"<<endl;
                        cout<<"5. Exit"<<endl;
                        cin>>menu;

                        //use switch statement to execute math problems
                        switch(menu){
                            case 1:
                                r1=rand()%50;
                                r2=rand()%50;
                                cout<<"Student lets do some math!"<<endl;
                                cout<<"What is "<<r1<<" + "<<r2<<" = ?"<<endl;
                                cin>>sans;
                                ansa=r1+r2;
                                (sans==ansa)?(cout<<"Correct!\n"):(cout<<"Incorrect!\n");
                                break;
                            case 2:
                                r1=rand()%50;
                                r2=rand()%50;
                                cout<<"Student lets do some math!"<<endl;
                                cout<<"What is "<<r1<<" - "<<r2<<" = ?"<<endl;
                                cin>>sans;
                                anss=r1-r2;
                                (sans==anss)?(cout<<"Correct!\n"):(cout<<"Incorrect!\n");
                                break;
                            case 3:
                                r1=rand()%50;
                                r2=rand()%50;
                                cout<<"Student lets do some math!"<<endl;
                                cout<<"What is "<<r1<<" * "<<r2<<" = ?"<<endl;
                                cin>>sans;
                                ansm=r1*r2;
                                (sans==ansm)?(cout<<"Correct!\n"):(cout<<"Incorrect!\n");
                                break;
                            case 4:
                                r1=rand()%50;
                                r2=rand()%50;
                                cout<<"Student lets do some math!"<<endl;
                                cout<<"What is "<<r1<<" / "<<r2<<" = ?"<<endl;
                                cin>>sans;
                                ansd=r1/r2;
                                (sans==ansd)?(cout<<"Correct!\n"):(cout<<"Incorrect!\n");
                                break;
                            case 5:
                                cout<<"Goodbye!\n"<<endl;
                                break;
                        }
                    }while(menu!=5);
                    break;
                }
                case 6:{
                    //Declare Variables
                    int nfloors,nrooms,trooms,noccp,toccp;
                    float poccp;


                    //Input
                    cout<<"Lets calculate the number of rooms that are occupied in the hotel."<<endl;
                    cout<<"How many floors are in the hotel?"<<endl;
                    cin>>nfloors;

                    //loop, figure out the number of rooms in each floor
                    for(int i=1;i<=nfloors;i++){
                        cout<<"What is the number of rooms on floor number "<<i<<"?"<<endl;
                        cin>>nrooms;
                        trooms+=nrooms;
                        cout<<"What is the number of rooms that are occupied on floor"
                              " number "<<i<<"?"<<endl;
                        cin>>noccp;
                        toccp+=noccp;
                    }

                    //Output the results from the loop, making sure to get a percentage from
                    //the poccp variable
                    poccp=(float)toccp/(float)trooms*100;
                    cout<<"The number of rooms in the hotel is: "<<trooms<<endl;
                    cout<<"The number of rooms that are occupied in the hotel is: "<<noccp<<endl;
                    cout<<"The percentage of the hotel rooms that are occupied is: "
                          <<poccp<<"%"<<endl;
                    break;
                }
                case 7:{
                    //Declare Variables
                    int spop,epop,days;
                    float grate;

                    //Input
                    cout<<"What is the starting population?"<<endl;
                    cin>>spop;
                    cout<<"What is the growth rate?(by percentage)"<<endl;
                    cin>>grate;
                    grate/=100.00;
                    cout<<"How many days will the population grow?"<<endl;
                    cin>>days;

                    //loops and output
                    for(int i=0;i<=days;i++){
                        cout<<"Day "<<i<<": "<<spop<<"\n";
                        spop=(spop*grate)+spop;
                    }
                    break;
                }
                case 8:{
                    //Declare Variables
                    int sales1,sales2,sales3,sales4,sales5,nstar1,nstar2,nstar3,nstar4,nstar5;

                    //inputs
                    cout<<"What is the total sales volume for today at store 1?"<<endl;
                    cin>>sales1;
                    nstar1=sales1/100;
                    cout<<"What is the total sales volume for today at store 2?"<<endl;
                    cin>>sales2;
                    nstar2=sales2/100;
                    cout<<"What is the total sales volume for today at store 3?"<<endl;
                    cin>>sales3;
                    nstar3=sales3/100;
                    cout<<"What is the total sales volume for today at store 4?"<<endl;
                    cin>>sales4;
                    nstar4=sales4/100;
                    cout<<"What is the total sales volume for today at store 5?"<<endl;
                    cin>>sales5;
                    nstar5=sales5/100;

                    //outputs, using loops to determine the amount of stars
                    cout<<"\nStore 1:";
                    while(nstar1!=0){
                        cout<<"*";
                        nstar1-=1;
                    }
                    cout<<"\nStore 2:";
                    while(nstar2!=0){
                        cout<<"*";
                        nstar2-=1;
                    }
                    cout<<"\nStore 3:";
                    while(nstar3!=0){
                        cout<<"*";
                        nstar3-=1;
                    }
                    cout<<"\nStore 4:";
                    while(nstar4!=0){
                        cout<<"*";
                        nstar4-=1;
                    }
                    cout<<"\nStore 5:";
                    while(nstar5!=0){
                        cout<<"*";
                        nstar5-=1;
                    }
                    break;
                }
                case 9:{
                    int budget, exp;
                    //Inputs
                    cout<<"What is your budget for the month?"<<endl;
                    cin>>budget;

                    //loop
                    do{
                        cout<<"Press 0 when you are finished with the program!";
                        cout<<"Expense: ";
                        cin>>exp;
                        exp+=exp;

                    }while(exp!=0);

                    //Calcualte totals
                    cout<<"Your budget was:         $"<<budget<<endl;
                    budget-=exp;
                    cout<<"Your total expenses are: $"<<exp<<endl;
                    break;
                }
                case 10:{
                    //Declare Variables
                    int num,tnum;

                    //Input
                    cout<<"Enter the length of the square you would like to make"<<endl;
                    cin>>num;

                    //limit for the for loop
                    tnum=num*num;

                    //loop
                    cout<<"This is your output!:\n"<<endl;
                    for(int i=1;i<=tnum;i++){
                        cout<<"x";
                        if(i%num==0){
                            cout<<"\n";
                        }
                    }
                    break;
                }
                case 11:{
                    //variables
    
                    char choice;
                    int gas,dist;
                    float MPG;
                    do{
                        cout<<"Lets calculate the MPG of your vehicle!"<<endl;

                        //read in the amount of liters
                        cout<<"How many liters has your car consumed?"<<endl;
                        cin>>gas;

                        //read in the number of miles
                        cout<<"How far have you gone, in miles?"<<endl;
                        cin>>dist;

                        //call the function
                        MPG=calcMPG(gas,dist);

                        //output result
                        cout<<"Your MPG is:"<<setprecision(3)<<MPG<<endl;

                        //ask user if the calculation wants to be done again
                        cout<<"Do you want to do another calculation: Yes(1) or No (2)?"<<endl;
                        cin>>choice;
                    }while(choice=='1');
                    break;
                }
                case 12:{
                    //variables
                    int input;
                    string output;

                    cout<<"Lets sing the song Ninety Nine bottles of beer on the wall!"<<endl;
                    cout<<"What number do you want to start with?"<<endl;
                    cin>>input;

                    //create loop to call function the correct # of times
                    while(input>=0){
                        //if the song is finished just output one line
                        if(input==0){
                            cout<<"Zero bottles of beer on the wall!"<<endl;
                            cout<<"\nEnd Song"<<endl;
                            break;
                        }
                        else{
                            //take the input and insert into the function, store output into output
                            output=song(input);

                            //insert number into the cout function
                            cout<<output<<" bottles of beer on the wall,"<<endl;
                            cout<<output<<" bottles of beer,"<<endl;
                            cout<<"Take one down, pass it around,"<<endl;

                            //decriment the input to get the next number
                            input--;
                        }
                    }
                    break;
                }
                case 13:{
                    //variables
                    char coin;
                    float sum=0.00,cOut=0.00, cost=3.50;

                    //outline the rules of the interaction with user
                    cout<<"You approach a vending machine that outputs deep fried twinkies!"<<endl;
                    cout<<"The cost is 3.50$."<<endl;
                    cout<<"You only have the following coins: Dollar (1.00$), Quarter (0.25$)"<<endl;
                    cout<<"Dime (0.10$), and Nickel (0.05$)"<<endl;

                    //continually prompt until the user reaches 3.50$
                    while(sum<cost){

                        //input
                        cout<<"Enter o for dollar, q for quarter, d for dime, and n for nickel"<<endl;
                        cin>>coin;

                        //call function to determine the coin type
                        cOut=total(coin);

                        //if its not valid, it will output 0
                        if(cOut == 0){
                            cout<<"Not valid Input!"<<endl;
                        }

                        //if its valid the process continues
                        else{
                            sum=sum+cOut;
                            cout<<"Your total so far is:"<<setprecision(2)<<fixed<<sum<<"$"<<endl;
                        }
                    }
                    cout<<"You got your twinkie!"<<endl;
                    cout<<"You entered:"<<sum<<" and you are due "<<setprecision(2)<<fixed<<sum-cost<<" $ in change"<<endl;
                    break;
                }
                default:{
                        cout<<"Exit?"<<endl;
                }
        };
    }while(choice<=13);
    
    //Exit stage right
    return 0;
}

