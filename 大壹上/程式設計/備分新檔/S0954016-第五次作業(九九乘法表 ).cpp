﻿// 九九乘法表.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>


int main()
{
    std::cout << "Hello World!\n";
    int a,b,c; 

    for (a=1,b=1,c=1;a<10,b<10,c<10;a++,b++,c++)
    {
        printf("1*%d=%-2d 2*%d=%-2d 3*%d=%-2d", a, 1 * a, b, 2 * b, c, 3 * c);
        printf("\n");
    }
 
    printf("\n");

    for (a = 1, b = 1, c = 1; a < 10, b < 10, c < 10; a++, b++, c++)
    {
        printf("4*%d=%-2d 5*%d=%-2d 6*%d=%-2d", a, 4 * a, b, 5 * b, c, 6 * c);
        printf("\n");
    }

    printf("\n");

    for (a = 1, b = 1, c = 1; a < 10, b < 10, c < 10; a++, b++, c++)
    {
        printf("7*%d=%-2d 8*%d=%-2d 9*%d=%-2d", a, 7 * a, b, 8 * b, c, 9 * c);
        printf("\n");
    }

    printf("\n");







}

// 執行程式: Ctrl + F5 或 [偵錯] > [啟動但不偵錯] 功能表
// 偵錯程式: F5 或 [偵錯] > [啟動偵錯] 功能表

// 開始使用的提示: 
//   1. 使用 [方案總管] 視窗，新增/管理檔案
//   2. 使用 [Team Explorer] 視窗，連線到原始檔控制
//   3. 使用 [輸出] 視窗，參閱組建輸出與其他訊息
//   4. 使用 [錯誤清單] 視窗，檢視錯誤
//   5. 前往 [專案] > [新增項目]，建立新的程式碼檔案，或是前往 [專案] > [新增現有項目]，將現有程式碼檔案新增至專案
//   6. 之後要再次開啟此專案時，請前往 [檔案] > [開啟] > [專案]，然後選取 .sln 檔案
