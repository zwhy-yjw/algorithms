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
