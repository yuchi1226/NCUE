#include <iostream>
#include <stdio.h>
#include <stdlib.h>


char func1(int a)
{
    
    
	if (0 <= a && a <= 12)
        printf("黑桃");
    if (13 <= a && a <= 25)
        printf("紅心");
    if (26 <= a && a <= 38)
        printf("方塊");
    if (39 <= a && a <= 51)
        printf("梅花");
}


char func2(int a)
{
    char A, J, Q, K;
    
	if (a == 0 || a == 13 || a == 26 || a == 39)
        printf("A") ;
    if (a == 1 || a == 14 || a == 27 || a == 40)
        printf("2");
    if (a == 2 || a == 15 || a == 28 || a == 41)
        printf("3");
    if (a == 3 || a == 16 || a == 29 || a == 42)
        printf("4");
    if (a == 4 || a == 17 || a == 30 || a == 43)
        printf("5");
    if (a == 5 || a == 18 || a == 31 || a == 44)
        printf("6");
    if (a == 6 || a == 19 || a == 32 || a == 45)
        printf("7");
    if (a == 7 || a == 20 || a == 33 || a == 46)
        printf("8");
    if (a == 8 || a == 21 || a == 34 || a == 47)
        printf("9");
    if (a == 9 || a == 22 || a == 35 || a == 48)
        printf("10");
    if (a == 10 || a == 23 || a == 36 || a == 49)
        printf("J") ;
    if (a == 11 || a == 24 || a == 37 || a == 50)
        printf("Q");
    if (a == 12 || a == 25 || a == 38 || a == 51)
        printf("K");
    
}

int main()
{
    int a;
    

    printf("請輸入一數字:");
    scanf("%d", &a);
    
    func1(a);
	func2(a);

    if (a < 0 || a >= 52)
        printf("超出範圍…");


}
