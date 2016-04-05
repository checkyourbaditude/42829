/* 
 * File:   main.cpp
 * Author: Christopher Schaefer
 * There is a time machine that is capable of going ahead in time up to 24 hours
 * Allow the user to input and time with an input for am or pm and a time they
 * would like to fast forward too then calculate the difference in minutes
 * between the two times
 * 
 * totmins=hrs*60+mins
 * if(!sisAM )totmins + 12*60
 * totminf=hrf*60+minf
 * if(!fisAM)totminF+12*60
 * diff=totminf-totmins
 * 
 * if(hrs==12)total mins -=12
 * if(hrs==12)total minf -=12
 * what about noon?
 * Created on March 30, 2016, 9:46 AM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

//the conversion function
int conv(int chr, int cmin, bool cAM,int fhr, int fmin, bool fAM){
    int total=0;
    //if the hours match, and the AM/PM bool matchs
    if((chr==fhr)&&((cAM==1&&fAM==1)||(cAM==0&&fAM==0))){
        total=1440-(cmin-fmin);
        return total;
    }
    //if the future hours is greater than current hours, and the AM/PM bool matches
    else if((chr<fhr)&&((cAM==1&&fAM==1)||(cAM==0&&fAM==0))){
        total=(((fhr*60)+fmin)-((chr*60)+cmin));
        return total;
    }
    //if the future hours is greater than current hours, and the AM/PM bool does not matches
    else if((chr<fhr)&&((cAM==0&&fAM==1)||(cAM==1&&fAM==0))){
        total=720-((fhr*60)+fmin)-((chr*60)+cmin);
        return total;
    }
    //if the future is less than current hours, and the AM/PM bool matches
    else if((chr>fhr)&&((cAM==0&&fAM==0)||(cAM==1&&fAM==1))){
        if(chr==12){
            total=((fhr*60)+fmin)-(cmin);
        }
        else{
            total=(((chr*60)+cmin)-((fhr*60)+fmin));
        }
        return total;
    }
    //if the future is less than current hours, and the AM/PM does not match
    else if((chr>fhr)&&((cAM==0&&fAM==1)||(cAM==1&&fAM==0))){
        if(chr==12){
            total=720-(((chr*60)+cmin)-((fhr*60)+fmin));
        }
        total=720-(((chr*60)+cmin)-((fhr*60)+fmin));
        return total;
    }
    //if nothing works!
    else{
        return total=0;
    }
    //if the future is less than current hours, and the AM/PM does not match
}
int main(int argc, char** argv) {
    //variables (i know these are long however this is how the book asked to do it)
    int chours,cminutes,fhours,fminutes,diff;
    bool cisAM,fisAM;
    
    cout<<"There is a time machine that is capable of going ahead in time up to";
    cout<<"24 hours. Enter in a current time, then a future time and this program";
    cout<<"will calculate the difference"<<endl;
    
    //get the current hours
    cout<<"Current hour(between 1 and 12):";
    cin>>chours;
    
    //verify it is between 1 and 12
    if(chours>=13||chours<=0){
        do{
            cout<<"Try Again! Current hour(between 1 and 12):";
            cin>>chours;
        }while(chours>=13||chours<=0);
    }

    //get the current minutes
    cout<<"Current minutes(between 0 and 59):";
    cin>>cminutes;
    
    //verify it is between 0 and 59
    if(cminutes>=60||cminutes<0){
        do{
            cout<<"Try Again! Current Minutes(between 0 and 59):";
            cin>>cminutes;
        }while(cminutes>=60||cminutes<0);
    }
    
    //ask if it is PM or AM
    cout<<"Is it AM(1) or PM(0)?:";
    cin>>cisAM;
    
    //future inputs
    
   //get the current hours
    cout<<"Future hour(between 1 and 12):";
    cin>>fhours;
    
    //verify it is between 1 and 12
    if(fhours>=13||fhours<=0){
        do{
            cout<<"Try Again! Future hour(between 1 and 12):";
            cin>>fhours;
        }while(fhours>=13||fhours<=0);
    }

    //get the current minutes
    cout<<"Future minutes(between 0 and 59):";
    cin>>fminutes;
    
    //verify it is between 0 and 59
    if(fminutes>=60||fminutes<0){
        do{
            cout<<"Try Again! Future Minutes(between 0 and 59):";
            cin>>fminutes;
        }while(fminutes>=60||fminutes<0);
    }
    
    //ask if it is PM or AM
    cout<<"Is it AM(1) or PM(anything else)?:";
    cin>>fisAM;
    
    diff=conv(chours,cminutes,cisAM,fhours,fminutes,fisAM);
    
    cout<<"The difference between the current time and future time is:"<<diff<<endl;
    
    return 0;
}

