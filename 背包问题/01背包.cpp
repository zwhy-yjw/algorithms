// 朴素做法
// #include <iostream>
// #include <cstring>
// #include <algorithm>

// using namespace std;
// const int N = 1010;

// int n, m;
// int f[N][N];
// int v[N], w[N];

// int main()
// {
//     cin >> n >> m;
//     for(int i = 1; i <= n; i ++ ) cin >> v[i] >> w[i];

//     for(int i = 1; i <= n; i ++ )
//         for(int j = 1; j <= m; j ++ )
//         {
//             f[i][j] = f[i - 1][j];
//             if(j >= v[i]) f[i][j] = max(f[i - 1][j], f[i - 1][j - v[i]] + w[i]);
//         }

//         cout << f[n][m] << endl;
//     return 0;
// }


// 一维写法
#include <iostream>
#include <cstring>
#include <algorithm>
 
using namespace std;
const int N = 1010;

int n, m;
int f[N];
int v[N], w[N];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];

    for (int i = 1; i <= n; i++)
        for (int j = m; j >= v[i]; j--)
            f[j] = max(f[j], f[j - v[i]] + w[i]);


    cout << f[m] << endl;
    return 0;
}

