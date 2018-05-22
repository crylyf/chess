#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
//Print_board reads an array of length 64 and prints out
//a chess board.
//Effect: Prints out a chess board. 
void print_board(char board[64]){
  int counter= 1 ;
  for(int x = 0; x<64; x++){ 
    if (counter%8 == 0){ 
      printf("%c\n", board[x]); 
      counter++; 
    } else { 
      printf("%c", board[x]); 
      counter++;
    }
  }
}

 
//moves a piece on the board from position a to b 
//mutates the board 
void move(char board[64], char piece,int from, int to){
  board[to] = piece; 
  board[from] = 42; 
  //promotion time 
  if((piece == 'p') && (to >= 0) && (to <= 7)){ 
    board[to] = 'q';
  }else if ((piece == 'P') && (to >= 56) && (to <= 63)) { 
    board[to] = 'Q'; 
  } 
}
  
void play(){ 
  int turn_counter = 1; 
  char board[64] = 
{'R','H','B','K','Q','B','H','R', 
 'P','P','P','P','P','P','P','P',
 42,42,42,42,42,42,42,42, 
 42,42,42,42,42,42,42,42,
 42,42,42,42,42,42,42,42,
 42,42,42,42,42,42,42,42,
 'p','p','p','p','p','p','p','p',
 'r','h','b','q','k','b','h','r'};

  while(1){ 
  /*  char board[64] = {'R','H','B','K','Q','B','H','R', 
                      'P','P','P','P','P','P','P','P',
                      42,42,42,42,42,42,42,42, 
                      42,42,42,42,42,42,42,42,
                      42,42,42,42,42,42,42,42,
                      42,42,42,42,42,42,42,42,
                      'p','p','p','p','p','p','p','p',
                      'r','h','b','q','k','b','h','r'};*/
    print_board(board); 
    printf("Please enter a move\n");
    char input; 
    scanf(" %c",&input); 
    if ((input == 'Q') || (input == 'q')) { 
      break; 
    }else if ((input == 'M') || (input  == 'm')){ 
      char piece; 
      int from; 
      int to; 
      printf("Please enter a piece\n");
      scanf(" %c", &piece); 
      printf("Please enter from\n"); 
      scanf("%d", &from); 
      printf("Please enter to\n");
      scanf("%d", &to) ; 
      
      //game over? 
      if ((board[from] >= 'a') && (board[from] <= 'z')  && (board[to] == 'K')){ 
        printf ("Player1 won!\n");
        break; 
      }
      if ((board[from] >= 'A') && (board[from]<= 'Z') && (board[to] == 'k')){ 
        printf("Player2 won!\n"); 
        break; 
      }
      
      //checking if you are playing your own pieces 
      if ((piece >= 'a') && (piece <= 'z') && (turn_counter % 2 == 0)) { 
        printf("Please play on your own turn!\n");
      }else if ((piece >= 'A') && (piece <= 'Z') && (turn_counter % 2 == 1)){ 
        printf("Please play on your own turn!\n"); 
      
                            
      //checking for illegal move 
      }else if ((piece == 'P') && (to <= from)) { 
        printf("illegal move!\n"); 
      }else if ((piece == 'p') && (to >= from)) { 
        printf("illegal move!\n");
      }else if (((piece == 'r') || (piece == 'R')) &&
                (((to - from) % 7 == 0) || 
                 ((to - from) % 9 == 0))){ 
        printf("illegal move!\n"); 
      }else if (((piece == 'b') || (piece == 'B')) &&
                (((to - from) % 7 != 0) || 
                 ((to - from) % 9 != 0))){ 
        printf("illegal move!\n"); 
      }else {
        move(board, piece,from,to);  
        turn_counter++; 
        
      }
    }
  }
}

int main(){
  play(); 
}
