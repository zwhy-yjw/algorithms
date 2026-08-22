# KMP字符串

## 题目描述

给定一个模式串 S，以及一个模板串 P，所有字符串中只包含大小写英文字母以及阿拉伯数字。

模板串 P 在模式串 S 中多次作为子串出现。

求出模板串 P 在模式串 S 中所有出现的位置的起始下标。

## 输入格式

第一行输入整数 N，表示字符串 P 的长度。

第二行输入字符串 P。

第三行输入整数 M，表示字符串 S 的长度。

第四行输入字符串 S。

## 输出格式

共一行，输出所有出现位置的起始下标（下标从 0 开始计数），整数之间用空格隔开。

## 数据范围

1 ≤ N ≤ 10^5

1 ≤ M ≤ 10^6

## 输入样例

```
3
aba
5
ababa
```

## 输出样例

```
0 2
```

## 思路

KMP 算法，核心是 **next 数组**：

- `ne[i]`：前缀 p[1..i] 中最长相等前后缀的长度（不含自身）
- 求 next：用双指针，`while(j && p[i] != p[j+1]) j = ne[j]`，匹配则 `j++`，`ne[i] = j`
- 匹配过程：遍历 s，`while(j && s[i] != p[j+1]) j = ne[j]`，若 `s[i] == p[j+1]` 则 `j++`，当 `j == n` 时匹配成功，输出 `i - n`，然后 `j = ne[j]` 继续找下一个

时间复杂度 O(N + M)。

## 参考代码

```cpp
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1e5 + 10, M = 1e6 + 10;
char p[N], s[M];
int n, m;
int ne[N];

int main()
{
    cin >> n >> p + 1 >> m >> s + 1;
    //求ne过程
    for(int i = 2, j = 0; i <= n; i ++ )
    {
        while(j && p[i] != p[j + 1]) j = ne[j];
        if(p[i] == p[j + 1]) j ++ ;
        ne[i] = j;
    }
    //kmp匹配过程
    for(int i = 1, j = 0; i <= m; i ++ )
    {
        while(j && s[i] != p[j + 1]) j = ne[j];
        if(s[i] == p[j + 1]) j ++ ;
        if(j == n)
        {
            cout << i - n << ' ';
            j = ne[j];
        }
    }
    return 0;
}
```
