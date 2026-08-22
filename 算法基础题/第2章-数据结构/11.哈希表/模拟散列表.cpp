//开放寻址法

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 200003, null = 0x3f3f3f3f;

int h[N];
int m, x;
char cmd[2];


int find(int x)
{
    int k = ((x % N) + N) % N;
    while(h[k] != null && h[k] != x)
    {
        k ++ ;
        if(k == N) k = 0;
    }
    return k;
}


int main()
{
    cin >> m;
    memset(h, 0x3f, sizeof h);
    
    while (m -- )
    {
        cin >> cmd >> x;
        int k = find(x);
        if(cmd[0] == 'I') h[k] = x;
        else 
        {
            if(h[k] == x) puts("Yes");
            else puts("No");
        }
    }
    return 0;
}
