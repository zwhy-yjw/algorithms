#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;

queue<string> q;
unordered_map<string, int> d;

int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};

int bfs(string state)
{
    string end = "12345678x";
    
    q.push(state);
    d[state] = 0;
    
    while(q.size())
    {
        auto t = q.front();
        q.pop();
        
        if(t == end) return d[t];
        
        int distance = d[t];
        int k = t.find('x');
        
        for(int i = 0; i < 4; i ++ )
        {
            int a = k / 3 + dx[i], b = k % 3 + dy[i];
            if(a >= 0 && a < 3 && b >= 0 && b < 3)
            {
                swap(t[a * 3 + b], t[k]);
                if(!d.count(t))
                {
                    d[t] = distance + 1;
                    q.push(t);
                }
                swap(t[a * 3 + b], t[k]);
            }
            
        }
        
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string state;
    
    for(int i = 0; i < 9; i ++ )
    {
        char c[2];
        cin >> c;
        state += c;
    }
    
    cout << bfs(state) << endl;
    return 0;
}