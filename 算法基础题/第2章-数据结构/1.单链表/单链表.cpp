#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;
int m;
int head, ne[N], e[N], idx;

void init()
{
    head = -1, idx = 0;
}

void add_head(int x)
{
    e[idx] = x, ne[idx] = head, head = idx ++ ;
}

void add_k(int k, int x)
{
    e[idx] = x, ne[idx] = ne[k], ne[k] = idx ++ ;
}

void remove(int k)
{
    ne[k] = ne[ne[k]];
}

int main()
{
    init();
    int x, k;
    char cmd;
    cin >> m;
    while (m -- )
    {   
        cin >> cmd;
        if(cmd == 'H')
        {
            cin >> x;
            add_head(x);
        }
        else if(cmd == 'D')
        {
            cin >> k;
            if(!k) head = ne[head];
            else remove(k - 1);
        }
        else
        {
            cin >> k >> x;
            add_k(k - 1, x);
        }
    }
    for(int i = head; i != -1; i = ne[i]) cout << e[i] << ' ';
    return 0;
}