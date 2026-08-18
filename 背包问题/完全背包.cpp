// 朴素做法 超时
// #include <iostream>
// #include <cstring>
// #include <algorithm>

// using namespace std;
// const int N = 1010;

// int n, m;
// int v[N], w[N];
// int f[N][N];


// int main()
// {
//     cin >> n >> m;
//     for(int i = 1; i <= n; i ++ ) cin >> v[i] >> w[i];

//     for(int i = 1; i <= n; i ++ )
//         for(int j = 0; j <= m; j ++ )
//         {
//             f[i][j] = f[i - 1][j];
//             for(int k = 0; k * v[i] <= j; k ++ )
//                 f[i][j] = max(f[i - 1][j], f[i - 1][j - k * v[i]] + k * w[i]);
//         }

//     cout << f[n][m] << endl; 
//     return 0;
// }


// 优化k
// #include <iostream>
// #include <cstring>
// #include <algorithm>

// using namespace std;
// const int N = 1010;

// int n, m;
// int v[N], w[N];
// int f[N][N];


// int main()
// {
//     cin >> n >> m;
//     for(int i = 1; i <= n; i ++ ) cin >> v[i] >> w[i];

//     for(int i = 1; i <= n; i ++ )
//         for(int j = 0; j <= m; j ++ )
//         {
//             f[i][j] = f[i - 1][j];
//             if(j >= v[i]) f[i][j] = max(f[i - 1][j], f[i][j - v[i]] + w[i]);
//         }
//     cout << f[n][m] << endl; 
//     return 0;
// }
// //k=0 对应的 “不选第 i 件”，只是这众多方案里的第一个，
//它的数值依然是 f[i-1][j]（来自上一层）。
// 我们把第一个方案的数值先放进 f[i][j] 里，之后每枚举一个新的 k，
// 就拿新方案的数值，和 f[i][j] 里已经存的 “当前最优值” 比，更大就更新
//完全背包朴素展开式里，f[i][j] 是对 k=0、1、2…… 所有情况取最大值，所有项都来自i-1层。
//把f[i][j-v]也做同样展开，
//会发现：f[i][j-v] + w 正好等于 f[i][j] 展开式里「除了 f [i-1][j] 之外的所有项」。
//因此可以等价替换：不用枚举所有 k，只需要比较「不选第 i 件」
//和「在当前 i 层的 j-v 基础上再多选 1 件」，就能覆盖选 0 个、1 个、2 个…… 的全部情况


//一维再优化
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1010;

int n, m;
int v[N], w[N];
int f[N];


int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];

    for (int i = 1; i <= n; i++)
        for (int j = v[i]; j <= m; j++)
            f[j] = max(f[j], f[j - v[i]] + w[i]);

    cout << f[m] << endl;
    return 0;
}