/*
 * ============================================================
 *  程序设计题 02 —— 统计及格人数与及格率
 *  题目：n 个成绩中，统计 >=60 的人数，并计算及格率（百分数，保留 1 位小数）。
 *  满分思路：
 *   1) 遍历数组，用计数器统计满足条件的个数；
 *   2) 及格率 = 及格人数 / 总人数 * 100，注意转 double 避免整数除法；
 *   3) 人数用指针参数带回，及格率用 return 返回（一次得到两个结果）。
 * ============================================================
 */
#include <stdio.h>

double passRate(int score[], int n, int *passCount)
{
    int i, cnt = 0;
    for (i = 0; i < n; i++)
        if (score[i] >= 60)        /* 条件判断 + 计数，是设计题最基础的套路 */
            cnt++;
    *passCount = cnt;
    return n > 0 ? (double)cnt / n * 100.0 : 0.0;   /* 防空数组除 0 */
}

int main(void)
{
    int score[10] = {55, 60, 78, 42, 90, 88, 59, 61, 100, 30};
    int pass;
    double rate = passRate(score, 10, &pass);
    printf("及格人数 = %d，及格率 = %.1f%%\n", pass, rate);  /* 6 和 60.0% */
    return 0;
}
