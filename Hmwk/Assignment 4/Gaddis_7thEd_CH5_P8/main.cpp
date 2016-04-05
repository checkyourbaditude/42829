/* 
 * File:   main.cpp
 * Author: Chris Schaefer
 * Gladdis Chapter 5 Problem 8
 * Allow user to select the operator they would like to use
 * Then give them numbers to use that operator with
 * allow an exit in the menu
 * Created on January 23, 2016, 5:00 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

int main(int argc, char** argv) {
    //Declare Variables
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
    return 0;
}

