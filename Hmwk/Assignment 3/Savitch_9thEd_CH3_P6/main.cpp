/* 
 * File:   main.cpp
 * Author: Christopher Schaefer
 * Use the Febinaci sequence to take an input from the user and calcuate the 
 * amount of pounds of green crud is created. The start is 10 lbs, first day is
 * 10 lbs, and so on
 * Created on March 23, 2016, 8:15 AM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

int main(int argc, char** argv) {
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
    return 0;
}

