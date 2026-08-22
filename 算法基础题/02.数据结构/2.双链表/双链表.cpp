#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;

int e[N], l[N], r[N], idx;
int m;

void init()//01互指，占用两个下标，插入的数从2开始
{
    r[0] = 1;
    l[1] = 0;
    idx = 2;
}

void add_k(int k, int x) // 新的往旧的指, 旧变新
{
    //第k个插入的数下标为k + 1
    e[idx] = x;
    r[idx] = r[k];
    l[idx] = k;
    l[r[k]] = idx;
    r[k] = idx ++;
}

void remove(int k) 
{
    r[l[k]] = r[k];
    l[r[k]] = l[k];
}

int main()
{
    init();
    int k, x;    
    cin >> m;
    string cmd;
    while (m -- )
    {
        cin >> cmd;
        if(cmd == "L")
        {
            cin >> x;
            add_k(0, x);
        }
        else if(cmd == "R")
        {
            cin >> x;
            add_k(l[1], x);
        }
        else if(cmd == "D")
        {
            cin >> k;
            remove(k + 1);
            
        }
        else if(cmd == "IL")
        {
            cin >> k >> x;
            add_k(l[k + 1], x);
        }
        else
        {
            cin >> k >> x;
            add_k(k + 1, x);
        }
        
    }
    for(int i = r[0]; i != 1; i = r[i]) cout << e[i] << ' ';
    cout << endl;
    return 0;
}
