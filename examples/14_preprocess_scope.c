/*
 * ============================================================
 *  14_preprocess_scope.c —— 预处理宏、全局/局部变量、static 存储类别
 *  对应考点：#define 宏（含带参宏及括号问题）、文本替换本质、
 *            全局与局部同名遮蔽、static 局部变量的值保留
 *  编译运行：gcc -Wall -Wextra -std=c99 14_preprocess_scope.c -o 14_preprocess_scope
 * ============================================================
 */
#include <stdio.h>

#define PI 3.14159              /* 不带参宏：预处理时做纯文本替换 */
#define SQUARE(x) ((x) * (x))   /* 带参宏：每个参数、整体都要加括号 */
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int g = 100;                    /* 全局变量：定义在函数外，本文件各函数可见 */

void counter(void)
{
    static int cnt = 0;         /* static 局部变量：整个程序只初始化一次，
                                   函数调用结束后值仍然保留 */
    cnt++;
    printf("counter 第 %d 次被调用\n", cnt);
}

int main(void)
{
    printf("PI = %f\n", PI);
    printf("SQUARE(5) = %d\n", SQUARE(5));             /* 25 */
    printf("SQUARE(2+3) = %d（宏有括号才正确；没括号会被替换成 2+3*2+3=11）\n",
           SQUARE(2 + 3));                              /* ((2+3)*(2+3)) = 25 */
    printf("MAX(8,6) = %d\n", MAX(8, 6));              /* 8 */

    /* 局部变量与全局变量同名时，局部在作用域内“遮蔽”全局 */
    int g = 5;
    printf("此处访问到的是局部 g = %d（全局同名变量被遮蔽）\n", g);

    /* static 让 cnt 记住上一次的值，所以输出 1、2、3 而不是三个 1 */
    counter();
    counter();
    counter();

    /*
     * 小结：
     *  - #define 是“编译前文本替换”，不占类型检查、不分配内存；
     *    const 变量有类型、受编译器检查，现代代码更推荐 const。
     *  - 普通局部变量每次进函数重新创建；加 static 后只创建一次、值持续保留。
     */
    return 0;
}
