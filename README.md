# The-First · 计算机二级 C 语言学习仓库

这里记录 **全国计算机等级考试（NCRE）二级 C 语言程序设计** 的学习笔记、练习代码与历年真题。

## 一、考试题型与分值

| 题型 | 分值 | 说明 |
|---|---|---|
| 选择题 | 40 分 | 含公共基础知识 10 分（数据结构、程序设计、软件工程、数据库） |
| 程序填空题 | 18 分 | 在空缺处补全代码 |
| 程序改错题 | 18 分 | 找出并改正指定行的错误 |
| 程序设计题 | 24 分 | 按要求编写完整函数 / 程序 |

## 二、目录结构（建议）

```
.
├── examples/  # 知识点配套可运行示例（01~19，按学习顺序编号）
├── notes/     # 知识点笔记、语法总结
├── choice/    # 选择题练习
├── fill/      # 程序填空题
├── correct/   # 程序改错题
├── design/    # 程序设计题
└── exams/     # 历年真题与模拟题
```

## 三、如何编译运行一个 C 程序

### 方式 1：命令行 gcc（MinGW / Dev-C++ 自带）

```bash
# 基本编译
gcc hello.c -o hello
hello            # Windows 下生成并运行 hello.exe

# 推荐：开启全部警告、指定 C99 标准，便于发现问题
gcc -Wall -Wextra -std=c99 hello.c -o hello
```

### 方式 2：图形化 IDE

直接用 **Dev-C++**、**Visual Studio**、**Code::Blocks** 或 **VC++ 6.0** 打开 `.c` 文件，点击「编译 / 运行」即可（二级考试机试环境多为 Visual C++ 或 Dev-C++）。

## 四、核心知识脉络（复习路线）

1. C 语言基础：数据类型、运算符、输入输出
2. 三种结构：顺序、选择（if/switch）、循环（for/while/do-while）
3. 数组（一维、二维、字符数组与字符串）
4. 函数（定义、调用、参数传递、递归）
5. 指针（变量指针、数组指针、字符串指针、指针作函数参数）
6. 结构体、共用体、枚举
7. 编译预处理、文件操作
8. 常用算法：排序、查找、穷举、递归、字符串处理

## 五、代码示例索引

### examples/ —— 知识点配套示例（均可用 `gcc -Wall -Wextra -std=c99` 零警告编译运行）

| 编号 | 文件 | 知识点 |
|---|---|---|
| 01 | 01_hello.c | 程序结构、main、printf |
| 02 | 02_variables.c | 数据类型、常量、sizeof、ASCII |
| 03 | 03_input_output.c | printf 格式符、宽度对齐、scanf 与 & |
| 04 | 04_selection.c | if/else if、逻辑运算、switch 穿透 |
| 05 | 05_loop.c | for/while/do-while、break/continue、循环嵌套 |
| 06 | 06_array.c | 一维数组遍历、求和/最值/逆序 |
| 07 | 07_function.c | 函数声明定义、值传递、递归 |
| 08 | 08_array_2d.c | 二维数组、行列遍历、主对角线 |
| 09 | 09_string.c | '\0'、strlen/sizeof、string.h、字符统计转换 |
| 10 | 10_pointer_basic.c | 指针基础：& 取址、* 解引用 |
| 11 | 11_pointer_array.c | 数组名即地址、a[i]≡*(a+i)、指针遍历 |
| 12 | 12_pointer_function.c | 指针作函数参数、传址调用 |
| 13 | 13_struct.c | 结构体、共用体、枚举、typedef |
| 14 | 14_preprocess_scope.c | 宏定义、全局/局部、static |
| 15 | 15_file_io.c | 文件 fopen/fprintf/fscanf/fclose |
| 16 | 16_bubble_sort.c | 冒泡排序 |
| 17 | 17_selection_sort.c | 选择排序 |
| 18 | 18_search.c | 顺序查找、折半（二分）查找 |
| 19 | 19_classic_math.c | 素数、水仙花数、斐波那契、最大公约数 |

> 建议学习顺序：01→15 打语法基础，16→19 练算法，再进入下面的题型实战。

### 题型实战（fill / correct / design）

| 目录 | 文件 | 题型与考点 |
|---|---|---|
| fill | 01_fill_array_avg.c | 填空：数组遍历累加求平均 |
| fill | 02_fill_string_digit.c | 填空：字符串中统计数字字符 |
| correct | 01_correct_swap.c | 改错：值传递失效 → 指针传址交换 |
| correct | 02_correct_common.c | 改错：`=`与`==`、整数除法、scanf 漏 & |
| design | 01_design_max_index.c | 设计：求最大值及其下标 |
| design | 02_design_pass_rate.c | 设计：统计及格人数与及格率 |

## 六、Git 常用命令

```bash
git add .                 # 暂存所有改动
git commit -m "提交说明"   # 提交
git push                  # 推送到 GitHub
git pull                  # 拉取远程更新
```

> 小提示：本仓库通过本地代理访问 GitHub（仅对本仓库生效），推送前请确保代理软件处于开启状态。
