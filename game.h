/********************************************************************/
/* Game.h                                                           */
/* Author:                                                          */
/*  Derrik Fleming         */
/*  CIS343       */
/********************************************************************/
/* The following methods aid in the game play of ConnectX.          */
/*                                                                  */
/********************************************************************/

#ifndef CONNECTX_GAME_H
#define CONNECTX_GAME_H

#include <stdio.h>
#include <stdlib.h>

int isComplete(int *board, int pNum, int index, int w, int h,
               int size, int toWin);
int checkRow(int *board, int pNum, int index, int w,
             int h, int size);
int checkCol(int *board, int pNum, int index, int w, int h,
             int size);
int checkDiagLowLeftUpRight(int *board, int pNum, int index,
                            int w, int h, int size);
int checkDiagLowRightUpLeft(int *board, int pNum, int index,
                            int w, int h, int size);
int createBoard(int **board, int w, int h);
int move(int *board, int pNum, int w, int h, int pCol);
void printBoard(int *board, int w, int h);
int saveGame(int name);
int loadGame(int name);


#endif //CONNECTX_GAME_H
