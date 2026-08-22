# Trie字符串统计

## 题目描述

维护一个字符串集合，支持两种操作：

- `I x` 向集合中插入一个字符串 x
- `Q x` 询问一个字符串在集合中出现了多少次

共有 N 个操作，所有输入的字符串总长度不超过 10^5，字符串仅包含小写英文字母。

## 输入格式

第一行包含整数 N，表示操作数。

接下来 N 行，每行包含一个操作指令，指令为 `I x` 或 `Q x` 中的一种。

## 输出格式

对于每个询问指令 `Q x`，都要输出一个整数作为结果，表示 x 在集合中出现的次数。

每个结果占一行。

## 数据范围

1 ≤ N ≤ 10^5

字符串仅包含小写英文字母

## 输入样例

```
5
I abc
Q abc
Q ab
I ab
Q ab
```

## 输出样例

```
1
0
1
```

## 思路

Trie（字典树）：

- `son[N][26]`：每个节点的 26 个孩子指针（字符集为小写字母）
- `cnt[N]`：以某个节点结尾的单词出现次数
- `idx`：节点编号（0 是根节点）

- **insert**：从根出发，逐字符走，没有该孩子则创建，走到底后 `cnt[p]++`
- **query**：从根出发，逐字符走，中途走不通则返回 0，走到底返回 `cnt[p]`

插入和查询的时间复杂度均为 O(字符串长度)。

## 参考代码

```cpp
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1e5 + 10;

int m, idx; 
int son[N][26], cnt[N];

char str[N]; 
char cmd[2];

void insert(char str[])
{
    int p = 0;
    for(int i = 0; str[i]; i ++ )
    {
        int j = str[i] - 'a';
        if(!son[p][j]) son[p][j] = ++ idx ;
        p = son[p][j];
    }//循环结束读完一个单词
    cnt[p] ++ ;
}

int query(char str[])
{
    int p = 0;
    for(int i = 0; str[i]; i ++ )
    {
        int j = str[i] - 'a';
        if(!son[p][j]) return 0;
        p = son[p][j];//单词存在，p结点走到单词最后一位
    }
    return cnt[p];
}

int main()
{
    cin >> m;
    while (m -- )
    {
        cin >> cmd >> str;
        if(cmd[0] == 'I')  insert(str);
        else cout << query(str) << endl;
    }
    return 0;
}
```
