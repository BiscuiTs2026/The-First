/*
 * ============================================================
 *  15_file_io.c —— 文件读写（二级最后一道大题常考）
 *  对应考点：FILE 指针、fopen 的 "w"/"r" 模式、fclose、
 *            fprintf 写、fscanf 读、打开失败判断
 *  编译运行：gcc -Wall -Wextra -std=c99 15_file_io.c -o 15_file_io
 *  说明：运行后会在程序所在目录生成数据文件 15_data.txt
 * ============================================================
 */
#include <stdio.h>

int main(void)
{
    const char *path = "15_data.txt";

    /* ---------- 1. 写文件："w" 不存在就创建，已存在则清空重写 ---------- */
    FILE *fw = fopen(path, "w");
    if (fw == NULL) {                 /* 打开失败（如无权限）必须判断 */
        printf("文件写入打开失败\n");
        return 1;
    }
    fprintf(fw, "Li 85\n");
    fprintf(fw, "Wang 92\n");
    fprintf(fw, "Zhao 78\n");
    fclose(fw);                       /* 用完必须关闭，刷新并释放资源 */
    printf("已写入文件 %s\n", path);

    /* ---------- 2. 读文件："r" 只读方式打开 ---------- */
    FILE *fr = fopen(path, "r");
    if (fr == NULL) {
        printf("文件读取打开失败\n");
        return 1;
    }

    char name[20];
    int score, sum = 0, count = 0, max = -1;
    /* 用 fscanf 的返回值（成功读取的数据项个数）控制循环，
       比直接用 feof 判断更稳妥，可避免多读一次 */
    while (fscanf(fr, "%s %d", name, &score) == 2) {
        printf("读到：%s\t%d\n", name, score);
        sum += score;
        count++;
        if (score > max) max = score;
    }
    fclose(fr);

    if (count > 0)
        printf("共 %d 人，平均 %.1f，最高 %d\n",
               count, (double)sum / count, max);   /* 85.0 和 92 */

    /*
     * 常用模式补充：
     *  "w" 写（清空重建）  "r" 读   "a" 追加   "rb"/"wb" 二进制读写
     * 字符级：fputc(ch,fp) 写一个字符，fgetc(fp) 读一个字符
     */
    return 0;
}
