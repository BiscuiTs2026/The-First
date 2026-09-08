/*
 * ============================================================
 *  02_variables.c —— 变量、常量与基本数据类型
 *  对应考点：整型/实型/字符型、常量与变量、sizeof、ASCII 码
 *  编译运行：gcc -Wall -Wextra -std=c99 02_variables.c -o 02_variables
 * ============================================================
 */
#include <stdio.h>

int main(void)
{
    /* ---------- 1. 四种最常用的基本类型 ---------- */
    int    age   = 18;          /* 整型，用 %d 输出，通常占 4 字节 */
    float  score = 95.5f;       /* 单精度浮点，用 %f，字面量后加 f，4 字节 */
    double pi    = 3.1415926;   /* 双精度浮点，用 %lf/%f，8 字节，精度更高 */
    char   grade = 'A';         /* 字符型，用 %c，占 1 字节，单引号且只放一个字符 */

    printf("age   = %d\n", age);
    printf("score = %.1f\n", score);   /* %.1f：保留 1 位小数 */
    printf("pi    = %.4f\n", pi);     /* %.4f：保留 4 位小数 */
    printf("grade = %c\n", grade);

    /* ---------- 2. const 常量：定义后不能再被修改 ---------- */
    const int DAYS = 7;
    printf("一周有 %d 天\n", DAYS);

    /* ---------- 3. sizeof：求类型/变量占用的字节数（二级常考） ---------- */
    printf("字节数 int=%d float=%d double=%d char=%d\n",
           (int)sizeof(int), (int)sizeof(float),
           (int)sizeof(double), (int)sizeof(char));

    /* ---------- 4. char 的本质是“小整数”，对应 ASCII 码表 ---------- */
    char ch = 'A';
    printf("字符 %c 的 ASCII 码是 %d\n", ch, ch);          /* A -> 65 */
    printf("'A'+1 得到字符 %c，ASCII 码 %d\n", ch + 1, ch + 1); /* B -> 66 */
    printf("小写 a 与大写 A 相差 %d（大小写转换靠 ±32）\n", 'a' - 'A');

    return 0;
}
