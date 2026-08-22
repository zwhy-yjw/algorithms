#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1e5 + 10;

int n, m;
int a, b;

int p[N], sz[N];
char cmd[5];

int find(int x)
{
    if(x == p[x]) return x;
    else return p[x] = find(p[x]);
}

int main()
{
    cin >> n >> m;
    
    for(int i = 1; i <= n; i ++ ) p[i] = i, sz[i] = 1;
    
    while (m -- )
    {
        cin >> cmd;
        if(cmd[0] == 'C')
        {
            cin >> a >> b;
            if(find(a) == find(b)) continue;
            sz[find(b)] += sz[find(a)];
            p[find(a)] = find(b);
        }
        else if(cmd[1] == '1')
        {
            cin >> a >> b;
            if(find(a) == find(b)) puts("Yes");
            else puts("No");
        }
        else 
        {
            cin >> a;
            cout << sz[find(a)] << endl;
        }
    }
    return 0;
}
