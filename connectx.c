/*********************************************************************/
/* Connect-X                                                         */
/*    connectx.c                                                     */
/* Author                                                            */
/*  Derrik Fleming         */
/*  CIS343       */
/*********************************************************************/
/* ConnectX.c runs the game loop for the Connect-X game. It prints   */
/* pre-game welcome message, and game play commences as the game     */
/* loop is entered. When the gameComplete flag is set the loop exits */
/* and a post game message is printed to the console alerting the    */
/* player's the game has been won, and provides them with post game  */
/* options.                                                          */
/*********************************************************************/


#include <stdio.h>
#include <stdlib.h>
//#include <argp.h>

#include "game.h"


int main() {
    int* board;
    int bLength = 7;
    int bWidth = 7;

    int size = createBoard(&board, bWidth, bLength);

    if(size == bLength * bWidth){
        printBoard(board, bWidth, bLength);
    }

    return 0;
}