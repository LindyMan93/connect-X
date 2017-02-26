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
    int index = move(board, 1, bWidth, bHeight, 1);
    printf("index: %i\n", index);

    index = move(board, 1, bWidth, bHeight, 1);
    printf("index: %i\n", index);
    index = move(board, 1, bWidth, bHeight, 1);
    printf("index: %i\n", index);
    index = move(board, 1, bWidth, bHeight, 1);
    printf("index: %i\n", index);
    index = move(board, 1, bWidth, bHeight, 1);
    printf("index: %i\n", index);
    index = move(board, 1, bWidth, bHeight, 1);
    printf("index: %i\n", index);
    index = move(board, 1, bWidth, bHeight, 1);
    printf("index: %i\n", index);



    printBoard(board, bWidth, bHeight);

    free(board);
    return 0;
}