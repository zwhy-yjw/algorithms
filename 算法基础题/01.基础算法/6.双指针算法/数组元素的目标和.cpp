#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1e5 + 10;
int n, m, x;
int a[N], b[N];

int main()
{
    cin >> n >> m >> x;
    for(int i = 0; i < n; i ++ ) cin >> a[i];
    for(int j = 0; j < m; j ++ ) cin >> b[j];
    
    for(int i = 0, j = m - 1; i < n; i ++ )
    {
        while(j && a[i] + b[j] > x) j -- ;
        if(a[i] + b[j] == x)
        {
            cout << i << ' ' << j << endl;
            break;
        }
    }
    return 0;
}