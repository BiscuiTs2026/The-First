/*
 * ============================================================
 *  09_string.c —— 字符数组与字符串
 *  对应考点：'\0' 结束标志、strlen 与 sizeof 区别、string.h 常用函数、
 *            手写字符统计与大小写转换
 *  编译运行：gcc -Wall -Wextra -std=c99 09_string.c -o 09_string
 * ============================================================
 */
#include <stdio.h>
#include <string.h>      /* strlen / strcpy / strcat / strcmp 都在此声明 */

int main(void)
{
    /* 字符串本质：末尾藏着一个 '\0'（ASCII 为 0）作为结束标志 */
    char s1[] = "hello";          /* 实际占 6 个位置：h e l l o \0 */
    char s2[20] = "world";
    printf("s1 = %s\n", s1);

    /* ---------- 1. sizeof 与 strlen 的区别（二级高频陷阱） ---------- */
    printf("sizeof(s1) = %d（数组总字节，含 \\0），strlen(s1) = %d（有效长度，不含 \\0）\n",
           (int)sizeof(s1), (int)strlen(s1));     /* 6 和 5 */

    /* ---------- 2. 常用字符串库函数 ---------- */
    char buf[40];
    strcpy(buf, s1);             /* 复制：buf <- "hello"，目标数组要够大 */
    strcat(buf, " ");           /* 追加一个空格 */
    strcat(buf, s2);            /* 追加：buf = "hello world" */
    printf("拼接结果：%s，长度 = %d\n", buf, (int)strlen(buf));
    printf("strcmp(\"abc\",\"abd\") = %d（前者小→负数；相等→0；前者大→正数）\n",
           strcmp("abc", "abd"));

    /* ---------- 3. 手写统计：字母 / 数字 / 其它各有几个（常考） ---------- */
    char text[] = "Abc123!!";
    int letter = 0, digit = 0, other = 0;
    for (int i = 0; text[i] != '\0'; i++) {          /* 遇到 '\0' 结束 */
        if ((text[i] >= 'a' && text[i] <= 'z') ||
            (text[i] >= 'A' && text[i] <= 'Z'))
            letter++;
        else if (text[i] >= '0' && text[i] <= '9')
            digit++;
        else
            other++;
    }
    printf("「%s」中 字母=%d 数字=%d 其它=%d\n", text, letter, digit, other); /* 3 3 2 */

    /* ---------- 4. 手写小写转大写：大写字母 = 小写字母 - 32 ---------- */
    char t[] = "cLang";
    for (int i = 0; t[i] != '\0'; i++)
        if (t[i] >= 'a' && t[i] <= 'z')
            t[i] = t[i] - 32;
    printf("转大写：%s\n", t);               /* CLANG */

    return 0;
}
