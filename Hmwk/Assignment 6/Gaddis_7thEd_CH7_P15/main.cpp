/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Christopher Schaefer
 * Create a Tic-Tac Toe game with a 3x3 array
 *
 * Created on May 16, 2016, 9:41 AM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

//set size of the multi-demensional array
const int ROWS=3, COL=3;

//function to output the board array
void outputBoard(char [ROWS][COL]);
bool grade(char [ROWS][COL]);

int main(int argc, char** argv) {
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
    return 0;
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

