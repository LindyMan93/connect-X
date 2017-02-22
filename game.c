/********************************************************************/
/* Game.c                                                           */
/* Author:                                                          */
/*  Derrik Fleming         */
/*  CIS343       */
/********************************************************************/
/* The following methods aid in the game play of ConnectX.          */
/*                                                                  */
/********************************************************************/


#include "game.h"

/********************************************************************/
/* This method checks   */
/*                               */
/*                                                                  */
/********************************************************************/
int isComplete(int *board, int pNum, int index, int w, int h,
                  int size, int toWin) {
    // isComplete false by default
    int isComplete = 0;

    // check for win
    if (checkRow(board, pNum, index, w, h, size) >= toWin ||
            checkCol(board, pNum, index, w, h, size) >= toWin ||
            checkDiagLTR(board, pNum, index, w, h, size) >= toWin ||
            checkDiagRTL(board, pNum, index, w, h, size) >= toWin){
        // isComplete TRUE
        isComplete = 1;
    }

    return isComplete;
}

/********************************************************************/
/* This method checks   */
/*                               */
/*                                                                  */
/********************************************************************/
int nextValid(int *board, int curIndex, int w, int h,
               int size) {
    // isValid true
    int isValid = 1;

    // if curIndex is not current player's, or if the current index
    //    is in a perimeter row/col
    if (board[curIndex] != playerNum || w % curIndex == 0 ||
            w % curIndex == w - 1 || curIndex < w  ||
            curIndex > (size - w)) {
        // isValid false
        isValid = 0;
    }

    return isValid;
}

/********************************************************************/
/* This method checks   */
/*                               */
/*                                                                  */
/********************************************************************/
int checkRow(int *board, int pNum, int curIndex, int w,
             int h, int size) {
    int count = 1;

    int curIndex = index;
    // look "left"
    for (; w % curIndex != 0;) {
        if (board[curIndex] == playerNum) {
            curIndex -= 1;
            count++;
        }
        if (nextValid(board, pNum, curIndex, w, h, size) == false) {
            break;
        }
    }

    // look "right"
    curIndex = index;
    for (; w % curIndex != w - 1;) {
        if (board[curIndex] == playerNum) {
            curIndex += 1;
            count++;
        }
        if (nextValid(board, pNum, curIndex, w, h, size) == false) {
            break;
        }
    }

    return count;
}

/********************************************************************/
/* This method checks   */
/*                               */
/*                                                                  */
/********************************************************************/
int checkCol(int *board, int pNum, int index, int w,
             int h, int size) {
    int count = 1;

    // look "down"
    for (int i = 0; curIndex >= 0; i++) {
        if (board[curIndex] == playerNum) {
            curIndex = index - (w * i);
            count++;
        }
        if (nextValid(board, pNum, curIndex, w, h, size) == false) {
            break;
        }
    }

    return count;
}

/********************************************************************/
/* This method checks   */
/*                               */
/*                                                                  */
/********************************************************************/
int checkDiagLowLeftUpRight(int *board, int pNum, int index,
                            int w, int h, int size) {
    int count = 1;

    // look "low-left"
    int curIndex = index;
    for (int i = 0; w % curIndex != 0; i++) {
        curIndex = index - (i * (w + 1));

        if (board[curIndex] == playerNum) {
            count++;
        }
        if (nextValid(board, pNum, curIndex, w, h, size) == false) {
            break;
        }
    }

    // look "up-right"
    curIndex = index;
    for (int i = 0; w % curIndex != w - 1; i++) {
        curIndex = index + (i * (w + 1));

        if (board[curIndex] == playerNum) {
            count++;
        }
        if (nextValid(board, pNum, curIndex, w, h, size) == false) {
            break;
        }
    }

    return count;
}

/********************************************************************/
/* This method checks   */
/*                               */
/*                                                                  */
/********************************************************************/
int checkDiagLowRightUpLeft(int *board, int pNum, int index,
                            int w, int h, int size) {
    int count = 0;

    // look "low-right"
    int curIndex = index;
    for (int i = 0; w % curIndex != 0; i++) {
        curIndex = index - (i * (w - 1));

        if (board[curIndex] == playerNum) {
            count++;
        }

        if (nextValid(board, pNum, curIndex, w, h, size) == false) {
            break;
        }
    }

    // look "up-left"
    curIndex = index;
    for (int i = 0; w % curIndex != w - 1; i++) {
        curIndex = index + (i * (w - 1));

        if (board[curIndex] == playerNum) {
            count++;
        }
        if (nextValid(board, pNum, curIndex, w, h, size) == false) {
            break;
        }
    }

    return count;
}
/********************************************************************/
/*                                                                  */
/*                                                                  */
/********************************************************************/
int createBoard(int **board, int w, int h){
    int size = length * width;

    //allocate board size
    *board = malloc(size * sizeof(int));

    //init board to all zeros (unplayed val)
    for(int i = 0; i < size; i++){
        (*board)[i] = 0;
    }

    return size;
}

/********************************************************************/
/* Places the players in the selected column, returns index if      */
/* column not full, if column full returns -1.                      */
/*                                                                  */
/********************************************************************/
int move(int *board, int size, int height, int width, int pNum, int pCol){
    //the first available index in the selected column
    int playedIndex = playedCol - 1;

    // iterating through each row to find the first available index
    //   in the selected column
    int curIndex;
    for (int i = 0; i < height; i++) {
        curIndex = (i * width) + playedIndex;
        // index is available
        if(board[curIndex] == 0) {
            playedIndex = curIndex;
            break;
        }
        // column full
        if(i == height - 1){
            playedIndex = -1;
        }
    }

    return playedIndex;
}

/********************************************************************/
/*  */
/*  */
/*  */
/********************************************************************/
int gameComplete(){

}

/********************************************************************/
/* Prints a char array of the current board to the screen  */
/*  */
/*  */
/********************************************************************/
void printBoard(){

}

/********************************************************************/
/*  */
/*  */
/*  */
/********************************************************************/
void printGameState(){

}

/********************************************************************/
/*  */
/*  */
/*  */
/********************************************************************/
int saveGame(int name){

}

/********************************************************************/
/*  */
/*  */
/*  */
/********************************************************************/
int loadGame(int name){

}