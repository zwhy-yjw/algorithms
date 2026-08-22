#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;
int m;

int q[N];
int hh = 0, tt = -1;

int x;
string cmd;

int main()
{
    cin >> m;
    while (m -- )
    {
        cin >> cmd;
        if(cmd == "push")
        {
            cin >> x;
            q[ ++ tt ] = x;
        }
        else if(cmd == "empty")
        {
            if(hh > tt) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
        else if(cmd == "pop")
        {
            hh ++ ;
        }
        else if(cmd == "query")
        {
            if(hh <= tt) cout << q[hh];
            cout << endl;
        }
    }
    return 0;
}
