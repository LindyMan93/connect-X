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
#include <stdbool.h>
int checkHorizontal();
int checkVertical();
int checkDiagonalLeft();
int checkDiagonalRight();
int move();
int gameComplete();
void printBoard();
void printGameState();

#endif //CONNECTX_GAME_H
