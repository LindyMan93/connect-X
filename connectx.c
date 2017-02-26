/********************************************************************/
/* Connect-X                                                        */
/*    connectx.c                                                    */
/* Author                                                           */
/*  Derrik Fleming                                                  */
/*  CIS343-01 with Prof Ira Woodring                                */
/********************************************************************/
/* ConnectX.c runs the game loop for the Connect-X game. It prints  */
/* pre-game welcome message, and game play commences as the game    */
/* loop is entered. When the gameComplete flag is set the loop      */
/* exits and a post game message is printed to the console          */
/* alerting the player's the game has been won, and provides them   */
/* with post game options.                                          */
/*                                                                  */
/********************************************************************/


#include <stdio.h>
#include <stdlib.h>
//#include <argp.h>

#include "game.h"


int main() {
    int* board;
    int bHeight = 7;
    int bWidth = 7;
    int toWin = 4;

    int size = createBoard(&board, bWidth, bHeight);

    printf("Board created:\n");
    if(size == bHeight * bWidth){
        printBoard(board, bWidth, bHeight);
    }
    printf("p1 column 1:\n");
    move(board, 1, bWidth, bHeight, 2);

    printf("p1 column 2:\n");
    move(board, 1, bWidth, bHeight, 3);

    printf("p1 column 2:\n\n");
    move(board, 1, bWidth, bHeight, 3);

    printf("p1 column 3:\n\n");
    move(board, 1, bWidth, bHeight, 4);
    printf("p1 column 3:\n\n");
    move(board, 1, bWidth, bHeight, 4);
    printf("p1 column 3:\n\n");
    move(board, 1, bWidth, bHeight, 4);

    printf("p1 column 4:\n\n");
    move(board, 1, bWidth, bHeight, 5);
    printf("p1 column 4:\n\n");
    move(board, 1, bWidth, bHeight, 5);
    printf("p1 column 4:\n\n");
    move(board, 1, bWidth, bHeight, 5);
    printf("p1 column 4:\n\n");
    move(board, 1, bWidth, bHeight, 5);

    printBoard(board, bWidth, bHeight);
    int con = checkDiagLowLeftUpRight(board, 1, 25, bWidth, bHeight, 49);

    printf("connected: %d\n\n", con);

//    printf("p1 column 1:\n\n");
//    move(board, 1, bWidth, bHeight, 1);
//    printBoard(board, bWidth, bHeight);
//
//    printf("p2 column 6:\n\n");
//    move(board, 2, bWidth, bHeight, 6);
//    printBoard(board, bWidth, bHeight);


    free(board);
    return 0;
}