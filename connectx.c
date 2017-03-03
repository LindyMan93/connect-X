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
#include <string.h>
#include "handler.h"
#include "game.h"

/********************************************************************/
/* Prints a representation of the current board to the console.     */
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
}

int main(int argc, char** argv) {
    int* board;
    int bHeight = 7;
    int bWidth = 7;
    int toWin = 4;
    int pNum = 1;
    int isComplete = 0;
    struct arguments args;
    int index=0;


    setup(argc, argv, &args);
    bWidth = args.width;
    bHeight = args.height;
    toWin = args.connect;

    if(toWin > bWidth && toWin > bHeight){
        printf("Invalid game settings detected.\n");
        printf("Reverting to default game type.\n");
        bHeight = 7;
        bWidth = 7;
        toWin = 4;
    }

    createBoard(&board, bWidth, bHeight);
    int size = bHeight * bWidth;

    while(isComplete == 0) {
        int pCol = -1;
        char input[30];
        printBoard(board, bWidth, bHeight);
        while(pCol == -1) {

            printf("Player %i, select a column (1-%i): ", pNum, bWidth);

            scanf("%s", input);
            if(strcmp("s", input) == 1 || strcmp("-s", input) == 1){
                printf("Please enter a filename: ");
                scanf("%s", input);
            }

            if (atoi(input) <= bWidth || atoi(input) > 0){
                pCol = atoi(input);
                break;
            }
        }

        index = move(board, pNum, bWidth, bHeight, pCol);


        // check if last played piece caused end-game state
        isComplete = gameState(board, pNum, index, bWidth,
                                bHeight, size, toWin);

        // player's turn over
        pNum = pNum == 1 ? 2 : 1;

    }
    free(board);
    return 0;
}