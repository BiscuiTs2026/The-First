/*
 * ============================================================
 *  19_classic_math.c —— 二级高频经典算法小题合集
 *  内容：素数判断、水仙花数、斐波那契数列、辗转相除求最大公约数
 *  编译运行：gcc -Wall -Wextra -std=c99 19_classic_math.c -o 19_classic_math
 * ============================================================
 */
#include <stdio.h>

int isPrime(int n);   /* 是素数返回 1，否则 0 */
int gcd(int a, int b);/* 辗转相除法求最大公约数 */

int main(void)
{
    /* ---------- 1. 素数：只能被 1 和自身整除，输出 100~150 的素数 ---------- */
    printf("100~150 的素数：");
    for (int i = 100; i <= 150; i++)
        if (isPrime(i)) printf("%d ", i);
    printf("\n");

    /* ---------- 2. 水仙花数：三位数，各位数字立方和等于它本身 ---------- */
    printf("所有水仙花数：");
    for (int n = 100; n <= 999; n++) {
        int b = n / 100;        /* 百位 */
        int s = n / 10 % 10;    /* 十位 */
        int g = n % 10;         /* 个位 */
        if (b*b*b + s*s*s + g*g*g == n) printf("%d ", n);
    }
    printf("\n");

    /* ---------- 3. 斐波那契数列前 10 项：1 1 2 3 5 8 ... ---------- */
    printf("斐波那契前 10 项：");
    long f1 = 1, f2 = 1;
    for (int i = 1; i <= 5; i++) {
        printf("%ld %ld ", f1, f2);
        f1 = f1 + f2;
        f2 = f2 + f1;           /* 注意用上一步更新后的 f1，成对向前滚动 */
    }
    printf("\n");

    /* ---------- 4. 最大公约数 GCD 与最小公倍数 LCM ---------- */
    int a = 24, b = 18, g = gcd(a, b);
    printf("gcd(%d,%d) = %d，lcm = %d（lcm = a/gcd*b）\n",
           a, b, g, a / g * b);
    return 0;
}

int isPrime(int n)
{
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++)   /* 只需试除到根号 n */
        if (n % i == 0) return 0;      /* 能整除说明有别的因子，不是素数 */
    return 1;
}

int gcd(int a, int b)
{
    while (b != 0) {     /* 反复：(a,b)->(b,a%b)，直到余数为 0 */
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
