#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1e5 + 10;

int stk[N], x;
string cmd;
int tt = -1, m;
int main()
{
    cin >> m;
    while(m -- )
    {
        cin >> cmd;
        if(cmd == "push")
        {
            cin >> x;
            stk[ ++ tt ] = x;
        }
        else if(cmd == "query")
        {
            cout << stk[tt] << endl;
        }
        else if(cmd == "pop")
        {
            if(tt) tt -- ;
        }
        else if(cmd == "empty")
        {
            if(tt == 0) cout << "YES" << endl ;
            else cout << "NO" << endl;
        }
    }
    return 0;
}
