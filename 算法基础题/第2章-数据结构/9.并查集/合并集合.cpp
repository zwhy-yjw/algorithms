#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1e5 + 10;

int n, m;
int a, b;
int p[N];

char cmd[2];

int find(int x)
{
    if(x == p[x]) return x;
    else return p[x] = find(p[x]);
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i ++ ) p[i] = i;
    while (m -- )
    {
        cin >> cmd >> a >> b;
        if(cmd[0] == 'M')
        {
            if(find(a) == find(b)) continue;
            p[find(a)] = find(b);
        }
        else 
        {
            if(find(a) == find(b)) puts("Yes");
            else puts("No");
        }
    }
    return 0;
}
