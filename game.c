/********************************************************************/
/* Game.c                                                           */
/* Author:                                                          */
/*  Derrik Fleming                                                  */
/*  CIS343-01 with Prof Ira Woodring                                */
/********************************************************************/
/* The following methods aid in the game play of ConnectX.          */
/*                                                                  */
/********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "game.h"

/********************************************************************/
/* This method checks if any win conditions have been met. The last */
/* played index is passed in, if it coincides with a series of      */
/* indexes that are also associated with the same player whose sum  */
/* is greater than toWin, isComplete's value is set to 1,           */
/* indicating the game has been one by pNum.                        */
/*                                                                  */
/********************************************************************/
int isComplete(int *board, int pNum, int index, int w, int h,
                  int size, int toWin) {
    // isComplete 0 by default
    int isComplete = 0;

    // check for win
    if (checkRow(board, pNum, index, w, h, size) >= toWin ||
            checkCol(board, pNum, index, w, h, size) >= toWin ||
            checkDiagLowLeftUpRight(board, pNum, index, w, h, size) >= toWin ||
            checkDiagLowRightUpLeft(board, pNum, index, w, h, size) >= toWin){
        // isComplete TRUE
        isComplete = 1;
    }

    return isComplete;
}

/********************************************************************/
/* This method checks if the index in board[curIndex] is equal to   */
/* pNum. If it is not, isValid's value is set to 0, (false).        */
/*                                                                  */
/********************************************************************/
int isValid(int *board, int pNum, int index, int w, int h, int size) {
    // isValid true
    int isValid = 1;

    // if curIndex is not current player's, or if the current index
    //    is in a perimeter row/col
    if (board[index] != pNum) {
        isValid = 0;
    }
    return isValid;
}

/********************************************************************/
/* This method returns the sum of the row series board[index] is a  */
/* part of.                                                         */
/*                                                                  */
/********************************************************************/
int checkRow(int *board, int pNum, int index, int w,
             int h, int size) {
    int count = 0;

    // look "left"
    // iterates across row of index in "left" direction
    // break on perimeter col (index % w == 0) or
    // when board[index] != pNum
    for (int i = index; i >= 0 ; i--) {
        if (board[i] == pNum) {
            count++;
            printf("Index: %i, Count: %i\n\n", i, count);

        }
        if (i % w == 0 ||
                isValid(board, pNum, i, w, h, size) == 0) {
            printf("Exit on: %i\n\n", i);
            break;
        }
    }

    // look "right"
    // iterates across row of index in "right" direction
    // break on perimeter col (index % w == w - 1) or
    // when board[index] != pNum
    for (int i = index + 1; i < size ; i++) {
        if (board[i] == pNum) {
            count++;
            printf("Index: %i, Count: %i\n\n", i, count);
        }
        if (i % w == w - 1 ||
                isValid(board, pNum, i, w, h, size) == 0) {
            printf("Exit on: %i\n\n", i);
            break;
        }
    }

    return count;
}

/********************************************************************/
/* This method returns the sum of the col series board[index] is a  */
/* part of.                                                         */
/*                                                                  */
/********************************************************************/
int checkCol(int *board, int pNum, int index, int w, int h, 
             int size) {
    int count = 1;
    
    // look "down"
    // iterates "down" col of index
    // break when board[index] != pNum
    for (int i = index; i >= 0; i -= w) {
        if (board[i] == pNum) {
            count++;
            printf("Index: %i, Count: %i\n\n", i, count);
        }
        if(isValid(board, pNum, i, w, h, size) == 0) {
            break;
        }
    }

    return count;
}

/********************************************************************/
/* This method returns the sum of the diagonal series ("lower left  */
/* to upper right") board[index] is a part of.                      */
/*                                                                  */
/********************************************************************/
int checkDiagLowLeftUpRight(int *board, int pNum, int index, int w, 
                            int h, int size) {
    int count = 0;

    // look "down" and "left"
    // iterates diagonally "down" and "left" from index
    // break on perimeter col (index % w == 0) or
    // when board[index] != pNum
    for (int i = index; i >= 0; i -= w + 1) {
        if (board[i] == pNum) {
            count++;
            printf("Index: %i, Count: %i\n\n", i, count);
        }
        if (i % w == 0 ||
                isValid(board, pNum, i, w, h, size) == 0) {
            printf("Exit on: %i\n\n", i);
            break;
        }
    }

    // look "up" and "right"
    // iterates diagonally "up" and "right" from index
    // break on perimeter col (index % w == 0) or
    // when board[index] != pNum
    for (int i = index + w + 1; i < size; i += w + 1) {
        if (board[i] == pNum) {
            count++;
            printf("Index: %i, Count: %i\n\n", i, count);
        }
        if (i % w == w - 1 ||
                isValid(board, pNum, i, w, h, size) == 0) {
            printf("Exit on: %i\n\n", i);
            break;
        }
    }

    return count;
}

/********************************************************************/
/* This method returns the sum of the diagonal series ("lower right */
/* to upper left") board[index] is a part of.                       */
/*                                                                  */
/********************************************************************/
int checkDiagLowRightUpLeft(int *board, int pNum, int index, int w, 
                            int h, int size) {
    int count = 0;

    // look "down" and "right"
    // iterates diagonally "down" and "right" from index
    // break on perimeter col (index % w == 0) or
    // when board[index] != pNum
    int i = index;
    for (int i = index; i >= 0; i -= w - 1) {
        if (board[i] == pNum) {
            count++;
            printf("Index: %i, Count: %i\n\n", i, count);
        }
        if (i % w == w - 1 ||
                isValid(board, pNum, i, w, h, size) == 0) {
            printf("Exit on: %i\n\n", i);
            break;
        }
    }

    // look "up" and "left"
    // iterates diagonally "up" and "left" from index
    // break on perimeter col (index % w == 0) or
    // when board[index] != pNum
    for (int i = index + w - 1; i < size; i += w - 1) {
        if (board[i] == pNum) {
            count++;
            printf("Index: %i, Count: %i\n\n", i, count);
        }
        else if (i % w == 0 ||
                 isValid(board, pNum, i, w, h, size) == 0) {
            printf("Exit on: %i\n\n", i);
            break;
        }
    }

    return count;
}
/********************************************************************/
/* This method allocates memory for the specified width and height  */
/* and initializes the board to all zeroes (unplayed/"empty"        */
/* value).                                                          */
/********************************************************************/
int createBoard(int **board, int w, int h) {
    int size = w * h;

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
int move(int *board, int pNum, int w, int h, int pCol) {
    //the first available index in the selected column
    int pIndex = pCol - 1;

    // iterating through each row to find the first available index
    //   in the selected column
    int curIndex;
    for (int i = 0; i < h; i++) {
        curIndex = (i * w) + pIndex;
        // index is available
        if(board[curIndex] == 0) {
            pIndex = curIndex;
            board[pIndex] = pNum;
            break;
        }
        // column full
        if(i == h - 1){
            pIndex = -1;
        }
    }

    return pIndex;
}

/********************************************************************/
/* Prints a char array of the current board to the console.         */
/*                                                                  */
/********************************************************************/
void printBoard(int *board, int w, int h) {
    for (int i = h - 1; i >= 0; i--) {
        printf("|");
        for (int j = 0; j < w; j++) {
            printf("| %d |", board[i * w + j]);
        }
        printf("|\n");
    }
    printf("\n\n");


//    if (pNum == 1) {
//        pNum = 2;
//    }
//    else {
//        pNum = 1;
//    }
//    printf("Player %d select a column: ", pNum);

}

/********************************************************************/
/*  */
/*  */
/*  */
/********************************************************************/
int saveGame(int name){

    return name;
}

/********************************************************************/
/*  */
/*  */
/*  */
/********************************************************************/
int loadGame(int name){

    return name;
}