#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 100010;

int m;
int h[N];
int ph[N], hp[N];
int sz;

void heap_swap(int a, int b)
{
    swap(ph[hp[a]], ph[hp[b]]);
    swap(hp[a], hp[b]);
    swap(h[a], h[b]);
}

void down(int u)
{
    int t = u;
    if(u * 2 <= sz && h[u * 2] < h[t]) t = u * 2;
    if(u * 2 + 1 <= sz && h[u * 2 + 1] < h[t]) t = u * 2 + 1;
    if(t != u)
    {
        heap_swap(u, t);
        down(t);
    }
}

void up(int u)
{
    while(u / 2 && h[u / 2] > h[u]) 
    {
        heap_swap(u, u / 2);
        u >>= 1; 
    }
}

int main()
{
    cin >> m;
    int k, x;
    int j = 0;
    string cmd;
    while (m -- )
    {
        cin >> cmd;
        if(cmd == "I")
        {
            cin >> x;
            sz ++ ;
            j ++ ;
            ph[j] = sz;
            hp[sz] = j;
            h[sz] = x;
            up(sz);
        }
        else if(cmd == "PM") cout << h[1] << endl;
        else if(cmd == "DM")
        {
            heap_swap(1, sz);
            sz -- ;
            down(1);
        }
        else if(cmd == "D")
        {
            cin >> k;
            k = ph[k];
            heap_swap(k, sz);
            sz -- ;
            down(k), up(k);
        }
        else if(cmd == "C")
        {
            cin >> k >> x;
            k = ph[k];
            h[k] = x;
            down(k), up(k);
        }
    }
    return 0;
}
