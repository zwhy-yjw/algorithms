#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;
int n;
int a[N], stk[N];

int main()
{
    cin >> n;    
    for(int i = 0; i < n; i ++ ) cin >> a[i];
    int tt = 0;
    for(int i = 0; i < n; i ++ )
    {
        while(tt && stk[tt] >= a[i]) tt -- ;
        if(tt) cout << stk[tt] << ' ';
        else cout << - 1 << ' ';
        stk[ ++ tt ] = a[i];
    }
    return 0;
}
