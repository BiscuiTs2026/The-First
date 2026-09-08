/*
 * ============================================================
 *  13_struct.c —— 结构体 struct、共用体 union、枚举 enum、typedef
 *  对应考点：结构体打包不同类型数据、. 与 -> 访问、结构体数组、
 *            typedef 起别名、枚举即整数、共用体共享内存
 *  编译运行：gcc -Wall -Wextra -std=c99 13_struct.c -o 13_struct
 * ============================================================
 */
#include <stdio.h>

/* 结构体：把描述同一对象的不同类型数据“打包”成一个整体 */
struct Student {
    char  name[20];
    int   age;
    float score;
};

/* typedef 给类型起别名，之后可直接用 Point，不必每次写 struct */
typedef struct {
    int x, y;
} Point;

/* 枚举：给一组相关整数取名字，默认从 0 开始依次 +1 */
enum Week { MON, TUE, WED, THU, FRI, SAT, SUN };

/* 共用体：所有成员共用同一块内存，同一时刻只应使用其中一个成员 */
union Data {
    int  i;
    char c;
};

int main(void)
{
    /* ---------- 1. 结构体变量：初始化 + 用 . 访问成员 ---------- */
    struct Student s1 = {"Zhang", 19, 88.5f};
    printf("学生：%s，%d 岁，%.1f 分\n", s1.name, s1.age, s1.score);
    s1.score = 92.0f;
    printf("修改后分数：%.1f\n", s1.score);

    /* ---------- 2. 结构体数组：存放一批对象并遍历 ---------- */
    struct Student cls[3] = {
        {"Li",   18, 70.0f},
        {"Wang", 20, 95.0f},
        {"Zhao", 19, 81.0f}
    };
    float total = 0;
    for (int i = 0; i < 3; i++)
        total += cls[i].score;
    printf("三人平均分：%.2f\n", total / 3);       /* 82.00 */

    /* ---------- 3. typedef 别名；结构体指针用 -> 访问成员 ---------- */
    Point p = {3, 4};
    Point *pp = &p;
    printf("点(%d,%d)，通过指针 pp->x = %d\n", p.x, p.y, pp->x);

    /* ---------- 4. 枚举本质是有名字的整数 ---------- */
    printf("MON=%d，SUN=%d\n", MON, SUN);         /* 0 和 6 */
    enum Week today = WED;
    printf("today = %d（对应周三）\n", today);     /* 2 */

    /* ---------- 5. 共用体共享内存：大小取最大成员 ---------- */
    union Data d;
    d.i = 65;
    printf("共用体 d.i=%d，按字符看 d.c=%c（同一块内存的两种解读）\n", d.i, d.c);
    printf("sizeof(union Data) = %d\n", (int)sizeof(union Data)); /* 4 */

    return 0;
}
