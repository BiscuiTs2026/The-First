/*
 * ============================================================
 *  04_selection.c —— 选择结构：if / else if / switch
 *  对应考点：关系运算、逻辑运算 && || !、多分支、switch 穿透与 break
 *  编译运行：gcc -Wall -Wextra -std=c99 04_selection.c -o 04_selection
 * ============================================================
 */
#include <stdio.h>

int main(void)
{
    /* ---------- 1. if - else if - else 多分支（成绩分档） ---------- */
    int score = 76;
    if (score >= 90)
        printf("优秀\n");
    else if (score >= 80)
        printf("良好\n");
    else if (score >= 60)
        printf("及格\n");          /* 76 落在这一档 */
    else
        printf("不及格\n");

    /* ---------- 2. 逻辑运算符：&& 与、|| 或、! 非 ---------- */
    int age = 20;
    if (age >= 18 && age <= 60)        /* 两个条件同时成立 */
        printf("成年且未到老年\n");
    if (!(age < 18))                  /* ! 对结果取反 */
        printf("不是未成年人\n");

    /* ---------- 3. switch：拿表达式去匹配 case，break 防止“穿透” ---------- */
    int day = 3;
    switch (day) {
        case 1: printf("周一\n"); break;
        case 2: printf("周二\n"); break;
        case 3: printf("周三\n"); break;   /* 命中这里 */
        default: printf("其他\n"); break;  /* default：都不匹配时执行 */
    }

    /* ---------- 4. 有意利用“穿透”：多个 case 共用同一段处理 ---------- */
    char g = 'B';
    switch (g) {
        case 'A':
        case 'B':
        case 'C':
            printf("等级 %c：通过\n", g);   /* A/B/C 都会落到这里 */
            break;
        case 'D':
            printf("等级 D：不通过\n");
            break;
        default:
            printf("无效等级\n");
    }

    return 0;
}
