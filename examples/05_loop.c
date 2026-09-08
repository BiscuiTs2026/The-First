/*
 * ============================================================
 *  05_loop.c —— 循环结构：for / while / do-while，break / continue
 *  对应考点：累加累乘、计数、三种循环区别、break 与 continue、循环嵌套
 *  编译运行：gcc -Wall -Wextra -std=c99 05_loop.c -o 05_loop
 * ============================================================
 */
#include <stdio.h>

int main(void)
{
    /* ---------- 1. for：次数已知首选，求 1+2+...+100 ---------- */
    int sum = 0;
    for (int i = 1; i <= 100; i++)
        sum += i;
    printf("1~100 之和 = %d\n", sum);       /* 5050 */

    /* ---------- 2. while：求 5!（阶乘），累乘初值为 1 ---------- */
    int n = 5;
    long fact = 1;
    int k = 1;
    while (k <= n) {
        fact *= k;
        k++;
    }
    printf("%d! = %ld\n", n, fact);         /* 120 */

    /* ---------- 3. do-while：先执行一次再判断，循环体至少执行 1 次 ---------- */
    int count = 0;
    do {
        count++;
    } while (count < 3);
    printf("do-while 结束时 count = %d\n", count);   /* 3 */

    /* ---------- 4. break 结束整个循环；continue 只跳过本次 ---------- */
    for (int i = 1; i <= 5; i++) {
        if (i == 3) continue;   /* 跳过 3，直接进入 i=4 */
        if (i == 5) break;      /* 到 5 直接结束循环 */
        printf("%d ", i);
    }
    printf("\n");               /* 结果：1 2 4 */

    /* ---------- 5. 循环嵌套：打印左下三角形（二维遍历雏形） ---------- */
    for (int row = 1; row <= 3; row++) {
        for (int col = 1; col <= row; col++)
            printf("*");
        printf("\n");
    }

    return 0;
}
