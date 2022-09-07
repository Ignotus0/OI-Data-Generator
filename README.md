一个便捷实用的数据生成器 By Ignotus。

版本编号 v1.0, All Rights Reserved.

本数据生成器的数据点格式参考 UOJ。

### 使用方法

1. 将 `Data_Generator.cpp` 和 `randlib.h` 置于同一目录下。
2. 如果生成数据时希望同时得到标准答案，则需在同一目录下新建 `std.cpp` 文件，在此添加您的标准程序，并**保证其能够正常编译**。默认编译命令为 `g++ std.cpp -o std -std=c++14 -O2 -Wl,--stack=1073741824`。
3. 生成数据时请根据个人需要调整参数，可以调整的参数如下：
    + `has_subtasks`，是否存在子任务。
    + `subtasks`，如果 `has_subtasks = false`，该变量会被忽略，否则代表题目共包含的子任务数量。
    + `test_cases`，数据点总数。
    + `subtask_end[]`，如果不存在子任务则忽略，否则为一个长度等于 `subtasks` 的数组，第 $i$ 个元素代表第 $i+1$ 个子任务的最后一个测试点编号。注意必须满足 `subtask_end[subtasks - 1] = test_cases`。
    + 如果不存在子任务，则每个测试点等分，分值为 `100 / test_cases`，**注意这里 `test_cases` 的值必须是 $100$ 的约数**。
    + 否则在 `subtask_score[]` 中输入每个子任务的分值，第 $i$ 个元素代表第 $i+1$ 个子任务的分值。**所有元素之和必须等于 $100$。**
    + `pre` 代表前缀名，即选手建子目录时的文件夹名称。
    + 比如，一个叫做 `aceakioi` 的题目，第 $2024$ 个测试点的输入文件，就会被命名为 `aceakioi2024.in`。
    + `PATH` 是你希望存储生成数据的路径。**路径中只能包含可作为文件名的 ASCII 字符。**（注意：本生成器会在每次生成是自动在该路径下建立一个名字为 `pre` 的文件夹，并在第一次使用时显示“找不到路径 `./pre`”，这是正常现象，忽略即可。如果子目录下已经存在一个名字为 `pre` 的文件夹，则程序会询问你是否删除 `pre` 并建立新文件夹。**如果希望程序正常运行，请允许其删除+覆盖，注意这个删除+覆盖操作不可逆。**）
    + `TL` 和 `ML` 分别代表时间限制（秒）和空间限制（MB），这些限制会在题目配置文件中显示。
    + `comp` 为答案比较方式，会影响题目在 OJ 上的配置，具体见[这里](https://universaloj.github.io/post/%E4%BC%A0%E7%BB%9F%E9%A2%98%E9%85%8D%E7%BD%AE.html)。
    + 如果不希望运行标准程序，只希望生成数据查看效果，请注释掉 `#define GENERATE_AND_SOLVE`。
    + 如果不希望生成题目配置文件 `problem.conf`，请注释掉 `#define GENERATE_CONFIG`。
4. 在 `gen(int Testid)` 函数中实现你的数据生成器，`Testid` 为数据点编号。生成数据时可以使用 `randlib.h` 中预置的函数，详见下方 `randlib.h` 使用说明。
5. **不要修改除了上述参数部分和 `gen()` 函数外的任何内容，随意修改可能会有无法预知的后果。** 当然，你可以在 `randlib.h` 中自己添加一些常用的函数。

注：源程序的压缩包中提供了一份带子任务的，生成 A+B Problem 数据的模板。

### `randlib.h` 使用说明

+ `randomInt(l, r)`：随机生成 `int` 范围内， $[l,r]$ 中的整数。
+ `randomLong(l, r)`：随机生成 `long long` 范围内， $[l,r]$ 中的整数。
+ `randomSequence(n, l, r)`：随机生成长度为 $n$ 的序列，值域为 $[l,r]$。
+ `randomPerm(n)`：随机生成长度为 $n$ 的，$[1,n]$ 的排列。
+ `randomPoints(n, x_low, x_high, y_low, y_high)`：随机生成 $n$ 个二维平面上的点，横坐标 $[x_{low},x_{high}]$，纵坐标 $[y_{low},y_{high}]$。
+ `randomTree(n)`：随机生成一棵 $n$ 个结点的树，树高期望 $\log n$。
+ `Chain(n)`：生成 $n$ 个点的链。
+ `Flower(n)`：生成 $n$ 个点的菊花图。
+ `randomConnectedGraph(n, m)`：生成 $n$ 个点，$m$ 条边的无向连通图。图不带边权。
+ `OutputGraph(n, m)`：生成并乱序输出 $n$ 个点，$m$ 条边的无向连通图。图不带边权。
+ `OutputDAG(n, m)`：生成并输出 $n$ 个点，$m$ 条边的有向无环图（即，保证图是一个 DAG）。图不带边权。