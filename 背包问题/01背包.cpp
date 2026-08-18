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

// i 代表已经加入考虑的物品数量，每多处理一个物品，就进入下一轮更新
// 我们会用上一轮（处理完前 i-1 个物品）的结果，来推导这一轮（处理完前 i 个物品）的 f [j]
// 状态转移前提为 j >= v[i]，只有背包容量能装下当前物品才执行更新
// 如果 j 从小到大正序遍历会产生错误：
// i 循环固定不变时，会先更新数值更小的 j 对应的 f[j]；
// 后续更新大容量 j 时，大 j 减去物品体积 v [i] 恰好等于之前已经更新过的小 j。
// 本轮所有f[j]的计算本应全部基于上一轮原始数据，
// 但大容量j计算时获取到的 f[j - v[i]] 是本轮修改后的新值，而非上一轮旧数据，造成数值污染、
// 价值虚高。等同于同一物品被选取两次，违背 01 背包每件物品仅能选一次的规则。
// 逆序从m往v[i]遍历 j 可以规避该问题：
// 更新顺序为先处理大容量、后处理小容量。修改大容量 j 时，
// 更小下标位置的 f 数组还未被本轮循环改动，完整保存着上一轮未更新的原始值。
// 全程计算使用的都是上一轮数据，不会复用本轮已经更新过的数值，严格保证每件物品最多选取一次。
// for(int i = 1; i <= n; i ++ )
//         for(int j = m; j >= v[i]; j -- )
//             f[j] = max(f[j], f[j - v[i]] + w[i]);