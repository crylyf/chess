

#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
//* = 42
//K = 75 
//Q = 81 
//**FOR TESTING PURPOSES**
/*static char board1[64] = {42,42,42,42,42,42,42,81,
                          42,42,42,42,42,42,42,42,
                          42,42,42,42,42,42,42,42,
                          42,42,42,42,42,42,42,42,
                          42,42,42,42,42,42,42,42,
                          42,42,42,42,42,42,42,42,
                          75,42,42,42,42,42,42,42,
                          42,42,42,42,42,42,42,42}; 

static char board2[64] = {42,42,42,42,42,42,42,81,
                          42,42,42,42,42,42,42,42,
                          42,42,42,42,42,42,42,42,
                          42,42,42,42,42,42,42,42,
                          42,42,42,42,42,42,42,42,
                          81,42,42,42,42,42,42,42,
                          75,81,42,42,42,42,42,42,
                          81,42,42,42,42,42,42,42}; 

static char board3[64] = {42,42,42,42,42,42,42,81,
                          42,42,42,42,42,42,42,42,
                          42,42,42,42,42,42,42,42,
                          42,42,42,81,42,42,42,42,
                          81,42,42,42,42,42,42,42,
                          42,42,42,81,42,42,42,42,
                          75,42,42,42,42,42,42,42,
                          42,42,42,81,42,42,42,42};

static char board4[64] = {81,42,42,42,42,42,42,42,
                          42,42,42,42,42,42,42,42,
                          42,42,42,42,42,42,42,42,
                          42,42,42,42,42,42,42,42,
                          42,42,42,42,42,42,42,42,
                          42,42,42,42,42,42,42,42,
                          75,42,42,42,42,42,42,42,
                          42,42,42,42,42,42,42,42}; 

static char board5[64] = {81,42,42,42,42,42,42,42,
                          42,42,42,42,42,42,42,42,
                          42,42,42,42,42,42,42,42,
                          42,42,42,42,42,42,42,42,
                          42,81,42,42,42,42,42,42,
                          42,42,81,42,42,42,42,42,
                          75,42,42,42,42,42,42,42,
                          42,42,81,42,42,42,42,42}; 

static char board7[64] = {42,42,42,81,75,42,42,42,
                          42,42,42,42,42,42,42,42,
                          42,42,42,42,42,42,42,42,
                          42,42,42,42,42,42,42,42,
                          42,42,42,42,42,42,42,42,
                          42,42,42,42,42,42,42,42,
                          42,42,42,42,42,42,42,42,
                          42,42,42,42,42,42,42,42}; 

static char board6[64] = {42,42,42,42,42,42,81,42,
                          42,42,42,42,42,42,42,42,
                          42,42,42,42,42,42,42,42,
                          42,42,42,42,42,42,42,42,
                          42,81,42,42,42,42,42,42,
                          42,42,81,42,42,42,42,42,
                          75,42,42,42,42,42,42,42,
                          42,42,81,42,42,42,42,42}; 

static char board8[64] = {42,42,42,81,75,42,42,42,
                          42,42,42,42,42,81,42,42,
                          42,42,42,42,42,42,42,42,
                          42,42,42,42,42,42,42,42,
                          42,42,42,42,42,42,42,42,
                          42,42,42,42,42,42,42,42,
                          42,42,42,42,42,42,42,42,
                          42,42,42,42,42,42,42,42}; 
*/

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

static const int s1 = 0; 
static const int s2 = 7; 
static const int s3 = 8; 
static const int s4 = 15; 
static const int s5 = 16; 
static const int s6 = 23; 
static const int s7 = 24; 
static const int s8 = 31; 
static const int s9 = 32; 
static const int s10 = 39; 
static const int s11 = 40; 
static const int s12 = 47; 
static const int s13 = 48; 
static const int s14 = 55; 
static const int s15 = 56; 
static const int s16 = 63; 

//same_cdr takes in two integers, a and b, and produces true 
//if the two numbers are either in the same row, in the same column, 
//or diagonal to each other on a 8x8 chess board. 
//Requires: 0 <= a <= 63, 0 <= b <= 63
bool same_cdr(int a, int b){ 
  if (a == b) { 
    return false; 
  }else if (((a - b) % 8) == 0 ){
    return true ; 
  }else if (((a - b) % 7) == 0){ 
    return true ; 
  }else if (((a - b) % 9) == 0){ 
    return true ; 
  }else if (((a >= s1) && (a <= s2)) && 
            ((b >= s1) && (b <= s2))){ 
    return true ; 
    }else if (((a >= s15) && (a <= s16)) && 
            ((b >= s15) && (b <= s16))){ 
    return true ; 
    }else if (((a >= s3) && (a <= s4)) && 
            ((b >= s3) && (b <= s4))){ 
    return true ; 
    }else if (((a >= s5) && (a <= s6)) && 
            ((b >= s5) && (b <= s6))){ 
    return true ; 
    }else if (((a >= s7) && (a <= s8)) && 
            ((b >= s7) && (b <= s8))){ 
    return true ; 
    }else if (((a >= s9) && (a <= s10)) && 
            ((b >= s9) && (b <= s10))){ 
    return true ; 
    }else if (((a >= s11) && (a <= s12)) && 
            ((b >= s11) && (b <= s12))){ 
    return true ; 
    }else if (((a >= s13) && (a <= s14)) && 
            ((b >= s13) && (b <= s14))){ 
    return true ; 
  }else { 
    return false; 
  }
}

//find_king reads a chess board array and returns the current 
//position of the king on a 8x8 chess board. 
int find_king (char board[64]){ 
  int counter = 0;
  for (int x=0; x < 64; x++){ 
    if (board[x] == 75){ 
      return counter; 
    }else{ 
      counter++; 
    } 
  }
  return counter;
}

//can_capture_king reads a chess board array and returns true 
//if and only if the king can be captured from the current position.   
bool can_capture_king(char board[64]){
  int k = (find_king(board));
  int counter = 0; 
  for (int x = 0; x < 64; x++){ 
    if ((board[x] == 81) &&
        ((same_cdr(k, counter)) == 1)){
      return true; 
    } else { 
      counter++; 
    }
  }
  return false; 
} 

//king_capture reads a chessboard array and a integer k and determines
//if the king can be captured from the new position k. 
//Requires: 0 <= l <= 63
bool king_capture (char board[64], int k){ 
  int counter = 0; 
  for (int x = 0; x < 64; x++){ 
    if ((board[x] == 81) &&
        ((same_cdr(k, counter)) == 1)){
      return true; 
    } else { 
      counter++; 
    }
  }
  return false; 
} 


//is_checkmate reads a chessboard array and returns true if only 
//only if the king can be captured from the current position and all
//the adjacent positions. 
bool is_checkmate(char board[64]){ 
  int k = (find_king(board)); 
  if (can_capture_king(board)){ 
    if ((k == 0) && 
       (king_capture (board,1)) &&
       (king_capture (board, 8)) &&
       (king_capture (board, 9))){ 
      return true; 
    }else if ((k == 7) &&
              (king_capture (board, 6)) && 
              (king_capture (board, 14)) && 
              (king_capture (board, 15))){ 
      return true; 
    }else if ((k==63) && 
              (king_capture (board, 62)) && 
              (king_capture (board, 55)) && 
              (king_capture (board, 54))){ 
      return true; 
    }else if ((k==56) && 
              (king_capture (board, 49)) &&
              (king_capture (board, 57)) && 
              (king_capture (board, 48))){
      return true;
    }else if (((k == 1) ||
              (k == 2) ||
              (k == 3) ||
              (k == 4) ||
              (k == 5) ||
              (k == 6)) && 
        ((king_capture(board, (k - 1))) &&
         (king_capture(board, (k + 1))) &&
         (king_capture(board, (k + 7))) &&
         (king_capture(board, (k + 8))) &&
         (king_capture(board, (k + 9))))) {
        return true; 
    }else if (((k == 57) ||
              (k == 58) ||
              (k == 59) ||
              (k == 60) ||
              (k == 61) ||
              (k == 62)) && 
        ((king_capture(board, (k - 1))) &&
         (king_capture(board, (k + 1))) &&
         (king_capture(board, (k - 7))) &&
         (king_capture(board, (k - 8))) &&
         (king_capture(board, (k - 9))))) {
        return true; 
    }else if (((k == 8) ||
              (k == 16) ||
              (k == 24) ||
              (k == 32) ||
              (k == 40) ||
              (k == 48)) && 
        ((king_capture(board, (k - 8))) &&
         (king_capture(board, (k + 1))) &&
         (king_capture(board, (k + 9))) &&
         (king_capture(board, (k + 8))) &&
         (king_capture(board, (k - 7))))) {
        return true;
    }else if (((k == 55) ||
              (k == 15) ||
              (k == 23) ||
              (k == 31) ||
              (k == 39) ||
              (k == 47)) && 
        ((king_capture(board, (k - 1))) &&
         (king_capture(board, (k + 8))) &&
         (king_capture(board, (k + 7))) &&
         (king_capture(board, (k - 8))) &&
         (king_capture(board, (k - 9))))) {
        return true; 
    }else if ((king_capture(board, (k- 9))) &&
              (king_capture(board, (k- 8))) &&
              (king_capture(board, (k- 7))) &&
              (king_capture(board, (k+ 9))) &&
              (king_capture(board, (k+ 8))) &&
              (king_capture(board, (k+ 7))) &&
              (king_capture(board, (k+ 1))) &&
              (king_capture(board, (k- 1)))){
      return true;
    }else{
      return false;
    }
  }else { 
    return false; 
  }
}
  
      
      
         
      
      
       
//**FOR TESTING PURPOSES**
      
/*int main(){ 
  //print_board(board1); 
  printf("%d\n", (10-18)%8);
  assert(same_cdr(0, 7) == 1);
  assert(same_cdr(0, 8) == 1);
  assert(same_cdr(0, 1) == 1);
  assert(same_cdr(0, 9) == 1);
  assert(same_cdr(18, 9) == 1);
  assert(same_cdr(27, 9) == 1);
  assert(same_cdr(33, 9) == 1);
  assert(same_cdr(24, 9) == 0);
  assert(same_cdr(32, 9) == 0);
 // printf("%d\n", find_king(board1));
 // printf("%d\n", can_capture_king(board1));
 // printf("%d\n", can_capture_king(board2));
 // printf("%d\n", can_capture_king(board3));
//  printf("%d\n", king_capture(board4, 0));
 // assert(is_checkmate(board5) == 1);
 // assert(is_checkmate(board6) == 1);
 // assert(is_checkmate(board1) == 0);
 // assert(can_capture_king(board5) == 1); 
 // assert(is_checkmate(board7) == 0); 
 // assert(is_checkmate(board8) == 0); 



        

}
    
*/

  
