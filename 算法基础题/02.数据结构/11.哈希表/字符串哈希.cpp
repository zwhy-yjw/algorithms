#include <iostream>
#include <cstring>
#include <algorithm>

typedef unsigned long long ULL;

using namespace std;
const int N = 100003, P = 131;

int n, m;
ULL h[N], p[N];

char str[N];

ULL get(int l, int r)
{
    return h[r] - h[l - 1] * p[r - l + 1];
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    cin >> str + 1;
    p[0] = 1;
    
    for(int i = 1; i <= n; i ++ )
    {
        h[i] = h[i - 1] * P + str[i];
        p[i] = p[i - 1] * P;
    }
    
    while (m -- )
    {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        
        if(get(l1, r1) == get(l2, r2)) puts("Yes");
        else puts("No");
    }
    
    return 0;
}
