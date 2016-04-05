/* 
 * File:   main.cpp
 * Author: Christopher Schaefer
 * Write a program that writes out the song "99 bottles of beer on the wall"
 * take input from the user and start with that number
 * use the % to section of the number and output the correct string.
 * Created on March 30, 2016, 8:25 AM
 */

#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;
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
int main(int argc, char** argv) {
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
    
    return 0;
}

