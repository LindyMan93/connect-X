#include <CUnit/CUnit.h>
#include <CUnit/CUError.h>
#include <CUnit/TestDB.h>
#include <CUnit/TestRun.h>
#include <CUnit/Automated.h>
#include <CUnit/Basic.h>
#include <CUnit/Console.h>
#include <CUnit/CUCurses.h>
#include <CUnit/Win.h>


//int maxi(int i1, int i2)
//{
//    return (i1 > i2) ? i1 : i2;
//}
//
//void test_maxi(void)
//{
//    CU_ASSERT(maxi(0,2) == 2);
//    CU_ASSERT(maxi(0,-2) == 0);
//    CU_ASSERT(maxi(2,2) == 2);
//}

int horizontalWin(int *board, int pNum, int index, int w, int h, int size){
    return checkRow();
}

void checkHorizontal(){
    int* board;
    // connect 4
    int toWin = 4;

    createBoard(&board, 7, 7);
    move(board, 1, 7, 7, 1);
    move(board, 1, 7, 7, 2);
    move(board, 1, 7, 7, 3);
}