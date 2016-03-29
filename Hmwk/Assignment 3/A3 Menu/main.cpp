/* 
 * File:   main.cpp
 * Author: Christopher Schaefer
 * Menu for Assignment # 3
 * Modified on Mar 21st, 2016
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <ctime>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    short choice;
    do
    {
        //General Menu Format
        //Display the selection
        cout<<"Type 1 to run Gladdis_7thEd_CH4_P1"<<endl;
        cout<<"Type 2 to run Gladdis_7thEd_CH4_P4"<<endl;
        cout<<"Type 3 to run Gladdis_7thEd_CH4_P8"<<endl;
        cout<<"Type 4 to run Gladdis_7thEd_CH4_P9"<<endl;
        cout<<"Type 5 to run Gladdis_7thEd_CH4_P10"<<endl;
        cout<<"Type 6 to run Gladdis_7thEd_CH4_P12"<<endl;
        cout<<"Type 7 to run Gladdis_7thEd_CH4_P18"<<endl;
        cout<<"Type 8 to run Gladdis_7thEd_CH4_P20"<<endl;
        cout<<"Type 9 to run Gladdis_7thEd_CH4_P21"<<endl;
        cout<<"Type 10 to run Gladdis_7thEd_CH4_P22"<<endl;
        cout<<"Type 11 to run Savitch_9thEd_CH3_P3"<<endl;
        cout<<"Type 12 to run Savitch_9thEd_CH3_P4"<<endl;
        cout<<"Type 13 to run Savitch_9thEd_CH3_P4"<<endl;
        cout<<"Type 14 to run Savitch_9thEd_CH3_P4"<<endl;
        cout<<"Type anything else to quit with no solutions."<<endl;
        //Read the choice
        cin>>choice;
        switch(choice){
            case 1:{//Character '1' in Decimal
                //Declare Variables
                int a,b,max;

                //get input
                cout<<"Input two numbers"<<endl;
                cin>>a;
                cin>>b;

                //logic
                (a>b)?(max=a):(max=b);

                //Output
                cout<<max<<" is bigger";
                break;
            }
            case 2:{//Character '2' in Octal
                //l is length, w is width, a is for area
                short l1, w1, l2, w2, a1, a2;

                //inputs, ask user for values to compare
                cout<<"Enter the length and width of two rectangles, we will calculate"<<endl;
                cout<<"which rectangle has more area"<<endl;
                cout<<"Enter the length of the first rectangle"<<endl;
                cin>>l1;
                cout<<"Enter the width of the first rectangle"<<endl;
                cin>>w1;
                cout<<"Enter the length of the second rectangle"<<endl;
                cin>>l2;
                cout<<"Enter the width of the second rectangle"<<endl;
                cin>>w2;

                //Calculations
                a1=l1*w1;
                a2=l2*w2;
                cout<<"Area of rectangle 1 is "<<a1<<endl;
                cout<<"Area of rectangle 2 is "<<a2<<endl;

                //logic, which is bigger?
                if (a1>a2){
                    cout<<"Area of Rectangle 1 is larger";
                }
                else{
                    cout<<"Area of Rectangle 2 is larger";
                }
                break;
            }
            case 3:{//Character '3' in Hex
                //Declare Variables
                unsigned short q,d,n,p,total,remain;

                //inputs
                cout<<"What is the number of Quarters"<<endl;
                cin>>q;
                cout<<"What is the number of Dimes"<<endl;
                cin>>d;
                cout<<"What is the number of Nickels"<<endl;
                cin>>n;
                cout<<"What is the number of Pennies"<<endl;
                cin>>p;

                //calculations
                total=(q*25)+(d*10)+(n*5)+p;

                //logic
                if(total==100)
                {
                    cout<<"Your total is exactly "<<total<<endl;
                }
                else if(total<100)
                {
                    remain=100-total;
                    cout<<"Your Total was "<<total<<" and you were off by "<<remain<< "cents"<<endl;
                }
                else{
                    remain=total-100;
                    cout<<"Your Total was "<<total<<" and you were off by "<<remain<<" cents"<<endl;
                }
                break;
            }
            case 4:{
                //Declare Variables
                int sans,r1,r2,ans=r1+r2;
                do{
                    r1=rand()%50;
                    r2=rand()%50;
                    cout<<"Student lets do some math!"<<endl;
                    cout<<"What is "<<r1<<" + "<<r2<<" = ?"<<endl;
                    cin>>sans;
                }while(sans==ans);
                //logic
                cout<<"Correct!"<<endl;
                break;
            }
            case 5:{
                //declare Variables
                //q is quantity
                //d1 is discount 1, d2 is discount 2 etc.
                short q,cost=99,totp, totd;
                float d1=0.20f, d2=0.30f, d3=0.40f, d4=0.50f;

                //input
                cout<<"What is the amount of software that you would like to buy?"<<endl;
                cout<<"Each package costs 99$, and our discounts are as follows:"<<endl;
                cout<<"10-19 is 20% \n20-49 is 30%\n50-99 is 40%\n100+ is 50%"<<endl;
                cin>>q;

                //logic/calculations
                if(q>=10 && q<=19){
                    totd=q*cost*d1;
                    totp=q*cost-totd;
                    cout<<"Your discount is "<<totd<<endl;
                    cout<<"Your total purchase is "<<totp<<endl;
                }
                else if(q>=20 && q<=49){
                    totd=q*cost*d2;
                    totp=q*cost-totd;
                    cout<<"Your discount is "<<totd<<endl;
                    cout<<"Your total purchase is "<<totp<<endl;
                }
                else if(q>=50 && q<=99){
                    totd=q*cost*d3;
                    totp=q*cost-totd;
                    cout<<"Your discount is "<<totd<<endl;
                    cout<<"Your total purchase is "<<totp<<endl;
                }
                else if(q>=100){
                    totd=q*cost*d4;
                    totp=q*cost-totd;
                    cout<<"Your discount is "<<totd<<endl;
                    cout<<"Your total purchase is "<<totp<<endl;
                }
                else{
                    totp=cost*q;
                    cout<<"Your discount is "<<totd<<endl;
                    cout<<"Your total purchase is "<<totp<<endl;
                }
                break;
            }
            case 6:{
                //variables, c1 is charge one
                int balance, stdchrg=10.00, q, totchrg;
                float c1=.10, c2=.08, c3=.06, c4=0.04;

                //Inputs
                cout<<"What is the amount of your initial bank account?"<<endl;
                cout<<"If your balance falls below 400$ then its an extra 15$"<<endl;
                cin>>balance;
                cout<<"A 10$ flat fee is charged for checks plus the following:"<<endl;
                cout<<"$0.10 for fewer than 20 checks\n$0.08 for 20-39 checks\n"
                      "$0.06 for 40-59 checks\n$0.04 for 60+"<<endl;
                cout<<"How many checks are you depositing with us?"<<endl;
                cin>>q;

                //Logic/Calculations
                //must use ternary operator for extra 15$ charge
                if(q>=20 && q<=39){
                    totchrg=stdchrg+q*c2;
                    (balance-totchrg)<=400?(totchrg+=25):(totchrg+=0);
                    cout<<"Your total charges are "<<totchrg<<endl;
                }
                else if(q>=40 && q<=59){
                    totchrg=stdchrg+q*c3;
                    (balance-totchrg)<=400?(totchrg+=25):(totchrg+=0);
                    cout<<"Your total charges are "<<totchrg<<endl;
                }
                else if(q>=100){
                    totchrg=stdchrg+q*c4;
                    (balance-totchrg)<=400?(totchrg+=25):(totchrg+=0);
                    cout<<"Your total charges are "<<totchrg<<endl;
                }
                else{
                    totchrg=stdchrg+q*c1;
                    (balance-totchrg)<=400?(totchrg+=25):(totchrg+=0);
                    cout<<"Your total charges are "<<totchrg<<endl;
                }
                break;
            }
            case 7:{
                //Variables
                short input;
                float air=1100, water=4900, steel=16400, dis, result;

                //menu
                cout<<"The following are the speed of sound in specific mediums"<<endl;
                cout<<"Lets calculate how long it will take for sound to travel through"
                      "these mediums. Select one!"<<endl;
                cout<<"1. Air         1,100 feet per second"<<endl;
                cout<<"2. Water       4,900 feet per second"<<endl;
                cout<<"3. Stell       16,400 feet per second"<<endl;
                cin>>input;

                //Inputs
                cout<<"How far is it going to travel? (feet)"<<endl;
                cin>>dis;

                //calculations

                switch(input){
                    case 1:
                        result=air/dis;
                        cout<<fixed<<setprecision(4);
                        cout<<"You chose air"<<endl;
                        cout<<"The sound will travel "<<dis<<" in "<<result<<" seconds";
                        break;
                    case 2:
                        result=water/dis;
                        cout<<fixed<<setprecision(4);
                        cout<<"You chose water"<<endl;
                        cout<<"The sound will travel "<<dis<<" in "<<result<<" seconds";
                        break;
                    case 3:
                        result=steel/dis;
                        cout<<fixed<<setprecision(4);
                        cout<<"You chose steel"<<endl;
                        cout<<"The sound will travel "<<dis<<" in "<<result<<" seconds";
                        break;
                }
                break;
            }
            case 8:{
                //Declare Variables
                int utemp;

                //Outputs
                cout<<"The following substances feeze and boil at the following temps:"<<endl;
                cout<<"Substance        Feezeing point (F)      Boiling Point (F)"<<endl;
                cout<<"Ethyl Alcohol    -173                    172"<<endl;
                cout<<"Mercury          -38                     676"<<endl;
                cout<<"Oxygen           -362                    -306"<<endl;
                cout<<"Water            32                      212"<<endl;

                //Input
                cout<<"Enter a temp and see what will Freeze and Boil at that temp"<<endl;
                cin>>utemp;

                //Logic

                if (utemp<=-38){cout<<"Mercury Freezes at this point!"<<endl;
                    if(utemp<=-173)(cout<<"Ethyl Alcohol Freezes at this point!"<<endl);
                        if(utemp<=-306)(cout<<"Oxygen Boils at this point!"<<endl);
                            if(utemp<=-362)(cout<<"Oxygen Freezes at this point!"<<endl);
                }
                else if (utemp>=32){
                    cout<<"Water Freezes at this point!"<<endl;
                    if(utemp>=172)(cout<<"Ethyl Alcohol Boils at this point!"<<endl);
                        if(utemp>=212)(cout<<"Water Boils at this point!"<<endl);
                            if(utemp>=676)(cout<<"Mercury Boils at this point!"<<endl);
                }
                break;
            }
            case 9:{
                //Declare Variables
                short choice, r, l, w, b, h, areac, arear, areat;
                float pi=atan(1)*4; 

                //Menu and input
                cout<<"1. Calculate the Area of a Circle"<<endl;
                cout<<"2. Calculate the Area of a Rectangle"<<endl;
                cout<<"3. Calculate the Area of a Triangle"<<endl;
                cout<<"4. End"<<endl;
                cin>>choice;

                //switch statement, logic
                switch(choice){
                    //calculate the area of the circle, with user input
                    case 1:
                        cout<<"What is the radius of the Circle"<<endl;
                        cin>>r;
                        areac=pi*r*r;
                        cout<<"The area of the circle with radius "<<r<<" is "<<areac<<endl;
                        break;
                    //calculate the area of the rectangle, with user input
                    case 2:
                        cout<<"What is the length of the rectangle?"<<endl;
                        cin>>l;
                        cout<<"What is the width of the rectangle?"<<endl;
                        cin>>w;
                        arear=l*w;
                        cout<<"The area of the rectangle with length "<<l<<" and width "
                              <<w<<" is "<<arear;
                        break;
                    //calculate the area of the circle, with user input
                    case 3:
                        cout<<"What is the base length of the Triangle?"<<endl;
                        cin>>b;
                        cout<<"What is the height of the triangle?"<<endl;
                        cin>>h;
                        areat=.5*b*h;
                        cout<<"The area of the triangle with height "<<h<<"and base" <<b<<
                              " is "<<areat<<endl;
                        break;
                    case 4:
                        cout<<"Exit";            
                }
                break;
            }
            case 10:{
                //Declare Variables
                //int mins;
                float mins,tot,stime,chrg1=0.12f,chrg2=0.55f,chrg3=0.35f;

                //Input
                cout<<"I see you are going to make a long distance call"<<endl;
                cout<<"Here are the rates for such a call:"<<endl;
                cout<<"starting time of call    Rate per Minute"<<endl;
                cout<<"0-6:59                   0.12 cents"<<endl;
                cout<<"7-19:00                  0.55 cents"<<endl;
                cout<<"19:01-23:59              0.35 cents"<<endl;
                cout<<"Enter the start time of the call in HH.MM format"<<endl;
                cin>>stime;
                cout<<"How long was the call in minutes"<<endl;
                cin>>mins;

                //Validate data, make sure the number is no greater than 0.59
                //and no larger than 23.59, using modf to split number
                //logic
                if(stime<07.00){
                    tot=mins*chrg1;
                    cout<<"You Have been charged "<<chrg1<<" per minute for your "<<endl;
                    cout<<" call of "<<mins<<" minutes for a total charge of "<<tot<<endl;
                    cout<<" dollars"<<endl;
                }
                else if (stime>=07.00&&stime<=19.00){
                    tot=mins*chrg2;
                    cout<<"You Have been charged "<<chrg2<<" per minute for your "<<endl;
                    cout<<" call of "<<mins<<" minutes for a total charge of "<<tot<<endl;
                    cout<<" dollars"<<endl;
                }
                else{
                    tot=mins*chrg3;
                    cout<<"You Have been charged "<<chrg3<<" per minute for your "<<endl;
                    cout<<"call of "<<mins<<"minutes for a total charge of "<<tot<<endl;
                    cout<<" dollars"<<endl;
                }
                break;
            }
            case 11:{
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
                break;
            }
            case 12:{
                //variables; ui is the user input
                int uiN,busted=21;

                //these are the calculated values
                int v1=0,v2=0,v3=0,v4=0,v5=0,total=0;

                //these are the read in values
                char ui1=0,ui2=0,ui3=0,ui4=0,ui5=0;

                //the continue thought
                short cont=1;

                while(cont==1){
                    //get the inputs from the user
                    while(uiN!=2||uiN!=3||uiN!=4||uiN!=5){
                        cout<<"Lets score your blackjack hand!"<<endl;
                        cout<<"How many cards are in your hand? (must be between 2 and 5)"<<endl;
                        cin>>uiN;

                        //tell user the proper values to input!
                        cout<<"Valid inputs are: 2-9, t(10),j(Jack),q(Queen),k(King),a(ace)."<<endl;
                        cout<<"Please use lower case values only."<<endl;

                        //if user has two cards
                        if(uiN==2){
                            cout<<"What is your First card?"<<endl;
                            cin>>ui1;
                            //immediately interpret value
                                if(ui1=='a')v1=1;
                                else if(ui1=='j')v1=10;
                                else if(ui1=='q')v1=10;
                                else if(ui1=='k')v1=10;
                                else if(ui1=='t')v1=10;
                                else{
                                    v1= ui1 - '0';
                                }
                            cout<<"What is your Second card?"<<endl;
                            cin>>ui2;
                                if(ui2=='a')v2=1;
                                else if(ui2=='j')v2=10;
                                else if(ui2=='q')v2=10;
                                else if(ui2=='k')v2=10;
                                else if(ui2=='t')v2=10;
                                else{
                                    v2= ui2 - '0';
                                }
                            total=v1+v2;
                            if(total>busted){
                                cout<<"BUST"<<endl;
                            }
                            else{
                                if(ui1=='a'||ui2=='a')total+=10;
                                    if(total>busted)total-=10;
                                    else{
                                        cout<<"Your total is:"<<total<<endl;
                                    }
                            }
                            break;
                        }
                        //if user has two cards
                        else if (uiN==3){
                            cout<<"What is your First card?"<<endl;
                            cin>>ui1;
                                if(ui1=='a')v1=1;
                                else if(ui1=='j')v1=10;
                                else if(ui1=='q')v1=10;
                                else if(ui1=='k')v1=10;
                                else if(ui1=='t')v1=10;
                                else{
                                    v1= ui1 - '0';
                                }
                            cout<<"What is your Second card?"<<endl;
                            cin>>ui2;
                                if(ui2=='a')v2=1;
                                else if(ui2=='j')v2=10;
                                else if(ui2=='q')v2=10;
                                else if(ui2=='k')v2=10;
                                else if(ui2=='t')v2=10;
                                else{
                                    v2= ui2 - '0';
                                }
                            cout<<"What is your Third card?"<<endl;
                            cin>>ui3;
                                if(ui3=='a')v3=1;
                                else if(ui3=='j')v3=10;
                                else if(ui3=='q')v3=10;
                                else if(ui3=='k')v3=10;
                                else if(ui3=='t')v3=10;
                                else{
                                    v3= ui3 - '0';
                                }
                            total=v1+v2+v3;
                            if(total>busted){
                                cout<<"BUST"<<endl;
                            }
                            else{
                                if(ui1=='a'||ui2=='a'||ui3=='a')total+=10;
                                    if(total>busted)total-=10;
                                    else{
                                        cout<<"Your total is:"<<total<<endl;
                                    }
                            }
                            cout<<"This is your total:"<<total<<endl;
                            break;
                        }
                        //if user has three cards
                        else if(uiN==4){
                            cout<<"What is your First card?"<<endl;
                            cin>>ui1;
                                if(ui1=='a')v1=1;
                                else if(ui1=='j')v1=10;
                                else if(ui1=='q')v1=10;
                                else if(ui1=='k')v1=10;
                                else if(ui1=='t')v1=10;
                                else{
                                    v1= ui1 - '0';
                                }
                            cout<<"What is your Second card?"<<endl;
                            cin>>ui2;
                                if(ui2=='a')v2=1;
                                else if(ui2=='j')v2=10;
                                else if(ui2=='q')v2=10;
                                else if(ui2=='k')v2=10;
                                else if(ui2=='t')v2=10;
                                else{
                                    v2= ui2 - '0';
                                }
                            cout<<"What is your Third card?"<<endl;
                            cin>>ui3;
                                if(ui3=='a')v3=1;
                                else if(ui3=='j')v3=10;
                                else if(ui3=='q')v3=10;
                                else if(ui3=='k')v3=10;
                                else if(ui3=='t')v3=10;
                                else{
                                    v3= ui3 - '0';
                                }
                            cout<<"What is your Fourth card?"<<endl;
                            cin>>ui4;
                                if(ui4=='a')v4=1;
                                else if(ui4=='j')v4=10;
                                else if(ui4=='q')v4=10;
                                else if(ui4=='k')v4=10;
                                else if(ui4=='t')v4=10;
                                else{
                                    v4= ui4 - '0';
                                }
                            total=v1+v2+v3+v4;
                            if(total>busted){
                                cout<<"BUST"<<endl;
                            }
                            else{
                                if(ui1=='a'||ui2=='a'||ui3=='a'||ui4=='a')total+=10;
                                    if(total>busted)total-=10;
                                    else{
                                        cout<<"Your total is:"<<total<<endl;
                                    }
                            }
                            cout<<"This is your total:"<<total<<endl;
                            break;
                        }
                        //if user has four cards
                        else if(uiN==5){
                            cout<<"What is your First card?"<<endl;
                            cin>>ui1;
                                if(ui1=='a')v1=1;
                                else if(ui1=='j')v1=10;
                                else if(ui1=='q')v1=10;
                                else if(ui1=='k')v1=10;
                                else if(ui1=='t')v1=10;
                                else{
                                    v1= ui1 - '0';
                                }
                            cout<<"What is your Second card?"<<endl;
                            cin>>ui2;
                                if(ui2=='a')v2=1;
                                else if(ui2=='j')v2=10;
                                else if(ui2=='q')v2=10;
                                else if(ui2=='k')v2=10;
                                else if(ui2=='t')v2=10;
                                else{
                                    v2= ui2 - '0';
                                }
                            cout<<"What is your Third card?"<<endl;
                            cin>>ui3;
                                if(ui3=='a')v3=1;
                                else if(ui3=='j')v3=10;
                                else if(ui3=='q')v3=10;
                                else if(ui3=='k')v3=10;
                                else if(ui3=='t')v3=10;
                                else{
                                    v3= ui3 - '0';
                                }
                            cout<<"What is your Fourth card?"<<endl;
                            cin>>ui4;
                                if(ui4=='a')v4=1;
                                else if(ui4=='j')v4=10;
                                else if(ui4=='q')v4=10;
                                else if(ui4=='k')v4=10;
                                else if(ui4=='t')v4=10;
                                else{
                                    v4= ui4 - '0';
                                }
                            cout<<"What is your Fifth card?"<<endl;
                            cin>>ui5;
                                if(ui5=='a')v5=1;
                                else if(ui5=='j')v5=10;
                                else if(ui5=='q')v5=10;
                                else if(ui5=='k')v5=10;
                                else if(ui5=='t')v5=10;
                                else{
                                    v5= ui5 - '0';
                                }
                            total=v1+v2+v3+v4+v5;
                            if(total>busted){
                                cout<<"BUST"<<endl;
                            }
                            else{
                                if(ui1=='a'||ui2=='a'||ui3=='a'||ui4=='a'||ui5=='a')total+=10;
                                    if(total>busted)total-=10;
                                    else{
                                        cout<<"Your total is:"<<total<<endl;
                                    }
                            }
                            cout<<"This is your total:"<<total<<endl;
                            break;
                        }
                        //if user has five cards
                        else{
                            cout<<"You did not enter a valid number, try again!"<<endl;
                        }
                    }
                cout<<"Do you want to continue playing? Yes(1) or No(2)"<<endl;
                cin>>cont;
                }
                break;
            }
            case 13:{
                //variable 
                //The day is the weight on that day
                //keep in mind the problem states that each growth period is 5 days
                int day1=10, day2=10,dayN1=20,dayN2=30, total=0;
                int NumDays;
                unsigned short cont=1;

                //while loop to continue playing
                while(cont==1){

                    cout<<"How many days do you want the crud to grow?"<<endl;
                    cin>>NumDays;

                    switch(NumDays){
                        //output the base cases, if days is between 1-10
                        case 1:
                            cout<<"You have "<<day1<<" lbs of crud!"<<endl;
                            break;
                        case 2:
                            cout<<"You have "<<day1<<" lbs of crud!"<<endl;
                            break;
                        case 3:
                            cout<<"You have "<<day1<<" lbs of crud!"<<endl;
                            break;
                        case 4:
                            cout<<"You have "<<day1<<" lbs of crud!"<<endl;
                            break;
                        case 5:
                            cout<<"You have "<<day1<<" lbs of crud!"<<endl;
                            break;
                        case 6:
                            cout<<"You have "<<day2<<" lbs of crud!"<<endl;
                            break;
                        case 7:
                            cout<<"You have "<<day2<<" lbs of crud!"<<endl;
                            break;
                        case 8:
                            cout<<"You have "<<day2<<" lbs of crud!"<<endl;
                            break;
                        case 9:
                            cout<<"You have "<<day2<<" lbs of crud!"<<endl;
                            break;
                        case 10:
                            cout<<"You have "<<day2<<" lbs of crud!"<<endl;
                            break;
                        default:
                            //output the febinaci sequence
                            //starts at 10, because of the base cases
                            for(int i=10;i<=NumDays;i+=5){
                                //the values are being rotated to continue the sequence
                                total=dayN1+dayN2;
                                dayN1=dayN2;
                                dayN2=total;

                                cout<<total<<endl;
                            }
                        break;
                    }
                    cout<<"Do you want to continue? Yes (1) No (anything else)"<<endl;
                    cin>>cont;

                    //do you want to play again?
                    (cont==1) ? (cout<<"Lets do it again!"<<endl) : (cout<<"Finished!"<<endl);
                }
                break;
            }
            case 14:{
                //variables
                int stotal=23, user=0;

                //layout the rules
                cout<<"Lets play 23!"<<endl;
                cout<<"There are "<<stotal<<" picks in he pile."<<endl;

                while(stotal>0){
                    //get the input from the user
                    cout<<"You can draw 1, 2, or 3 picks from the pile"<<endl;
                    cin>>user;
                    switch(user){
                        case 1:
                            stotal-=user;
                            //first condition
                            if(stotal==0){
                                cout<<"You have lost!"<<endl;
                                break;
                            }
                            else if(stotal>4){
                                stotal-=(4-user);
                                cout<<"The computer withdrew "<<4-user<<" picks!"<<endl;
                            //second condition
                            }else if(stotal<=4 && stotal>=2){
                                if(stotal==4){
                                    stotal-=3;
                                    cout<<"The computer withdrew "<<3<<" picks!"<<endl;
                                }
                                if(stotal==3){
                                    stotal-=2;
                                    cout<<"The computer withdrew "<<2<<" picks!"<<endl;
                                }
                                if(stotal==2){
                                    stotal-=1;
                                    cout<<"The computer withdrew "<<2<<" picks!"<<endl;            
                                }
                            //third condition
                            }else if(stotal==1){
                                stotal-=1;
                                cout<<"The computer loses!"<<endl;
                                break;
                            }
                            cout<<"There are "<<stotal<<" picks left!"<<endl;
                            break;
                        case 2:
                            stotal-=user;
                            //first condition
                            if(stotal==0){
                                cout<<"You have lost!"<<endl;
                                break;
                            }
                            else if(stotal>4){
                                stotal-=(4-user);
                                cout<<"The computer withdrew "<<4-user<<" picks!"<<endl;
                            //second condition
                            }else if(stotal<=4 && stotal>=2){
                                if(stotal==4){
                                    stotal-=3;
                                    cout<<"The computer withdrew "<<3<<" picks!"<<endl;
                                }
                                if(stotal==3){
                                    stotal-=2;
                                    cout<<"The computer withdrew "<<2<<" picks!"<<endl;
                                }
                                if(stotal==2){
                                    stotal-=1;
                                    cout<<"The computer withdrew "<<2<<" picks!"<<endl;            
                                }
                            //third condition
                            }else if(stotal==1){
                                stotal-=1;
                                cout<<"The computer loses!"<<endl;
                                break;
                            }
                            cout<<"There are "<<stotal<<" picks left!"<<endl;
                            break;
                        case 3:
                            stotal-=user;
                            //first condition
                            if(stotal==0){
                                cout<<"You have lost!"<<endl;
                                break;
                            }
                            else if(stotal>4){
                                stotal-=(4-user);
                                cout<<"The computer withdrew "<<4-user<<" picks!"<<endl;
                            //second condition
                            }else if(stotal<=4 && stotal>=2){
                                if(stotal==4){
                                    stotal-=3;
                                    cout<<"The computer withdrew "<<3<<" picks!"<<endl;
                                }
                                if(stotal==3){
                                    stotal-=2;
                                    cout<<"The computer withdrew "<<2<<" picks!"<<endl;
                                }
                                if(stotal==2){
                                    stotal-=1;
                                    cout<<"The computer withdrew "<<2<<" picks!"<<endl;            
                                }
                            //third condition
                            }else if(stotal==1){
                                stotal-=1;
                                cout<<"The computer loses!"<<endl;
                                break;
                            }
                            cout<<"There are "<<stotal<<" picks left!"<<endl;
                            break;
                        default:
                            cout<<"Not valid: Enter 1, 2, or 3"<<endl;
                            cout<<"There are "<<stotal<<" picks left!"<<endl;
                            break;
                    }
                }
                break;
            }  
            default:{
                    cout<<"Exit?"<<endl;
            }
        }
    }while(choice>=1&&choice<=14);
    return 0;
}