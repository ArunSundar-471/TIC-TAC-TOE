#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;
int option, test, row, col, turn, option2 = 0;
char board[3][3];

//print the board to the screen 
void drawBoard()
{
     cout<<"\n";
     for(int i = 0; i < 3; i++)
     {
         for(int j = 0; j < 3; j++)
         {
                 cout<<"|"<<board[i][j]<<"|  ";
         }        
         cout<<"\n-------------\n";
     }        
}     

//this method returns a 0 if there's no winner, 1 if X wins, 2 if O wins, 3 if tie
int checkWinner()
{
//check to see if X won    
        if(board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X')
          return 1;
        if(board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X')
          return 1;     
        if(board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X')
          return 1;  
                       
        if(board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X')
          return 1;  
        if(board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X')
          return 1; 
        if(board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X')
          return 1;           

        if(board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X')
          return 1;   
        if(board[2][0] == 'X' && board[1][1] == 'X' && board[0][2] == 'X')
          return 1;  
//check to see if O won
        if(board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O')
          return 0;
        if(board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O')
          return 0;     
        if(board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O')
          return 0;  
                       
        if(board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O')
          return 0;  
        if(board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O')
          return 0; 
        if(board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O')
          return 0;           

        if(board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O')
          return 0;   
        if(board[2][0] == 'O' && board[1][1] == 'O' && board[0][2] == 'O')
          return 0;                                               
}        

void AI()
{
     col = -1;
     row = -1;
     while(col == -1 || row == -1)
     {
        time_t seconds;
        time(&seconds);
        srand((unsigned int) seconds);  
        col = rand()%3;
        row = rand()%3;
        if(board[row][col] != ' ')
        {
            col = -1;
            row = -1; 
        }
        board[row][col] = 'O';                        
     }           
     
}     
int main()
{

    do
    {
      option2 = 0; //so we can play multiple times
      cout<<"Enter a menu option:\n";
      cout<<"-----------------------------\n\n";
      cout<<"1. Play Tic Tac Toe\n";
      cout<<"2. Quit\n";
      cin>>option;
       for(int i = 0; i < 3; i++)
       {
           for(int j = 0; j < 3; j++)
           {
                   board[i][j] = ' ';
           }        
       }    
      if(option !=2)
      {
        while(option2 != -1)
        {         
            if(turn%2 == 0)
            {
                bool condition = true;
                while(condition == true) 
                {     
                    cout<<"\n\nEnter a move:\n";
                    cout<<"Enter the row you wish to make your move on (0,1,2)\n";
                    cin>>row;
                    cout<<"Enter the column you wish to make your move on (0,1,2)\n";
                    cin>>col;  
                    if(board[row][col] == ' ')
                    {   
                        board[row][col] = 'X';
                        turn++;
                        condition = false;
                    }    
                    else
                        cout<<"Invalid move!\n";
                }    
            }    
            else 
            {
                AI();                   
                turn++;
            }
                          
            if(checkWinner() == 1) 
            {
                cout<<"Congratulations! X won!\n\n";
                option2 = -1;
            }               
            else if(checkWinner() == 2) 
            {
                cout<<"Congratulations! O won!\n\n";
                option2 = -1;
            }               
            drawBoard();
        }  
        
      }  
      
    }while(option != 2);
      cout<<"\n\n\n\nEnter anything to quit.";
      cin>>test;
}