// ConsoleApplication2.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include <iomanip>
#pragma warning(disable:4996)

int main()
{
    std::cout << "Hello World!\n";
    int a, b, c, e, f, g, h, i, j;
    
    printf("請輸入現在時間(時:分:秒)");
    scanf_s("%d:%d:%d",& a,& b,& c);

    printf("請輸入經過時間(時:分:秒)");
    scanf_s("%d:%d:%d ",& e, &f,& g);
    
    h = a + e;
    i = b + f;
    j = c + g; 

    if (j >= 60)
    {
        i++;
        j -= 60;
    }

    if (i >= 60)
    {
        h++;
        i -= 60;
    }

    if (h >= 60)    
        h -= 60;
        
   
    printf("現在時間:%d:%d:%d ", h, i, j);

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
