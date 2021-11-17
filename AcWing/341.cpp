/*
最优贸易
url: https://www.acwing.com/problem/content/343/
*/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
int a, b;
const int N = 1e7 + 5, M = 1e7 + 5;
int tot, edge[3][N], nxt[3][N], head[3][M], c[N], c1[N], k[N];
void add(int x, int y, int z)
{
    tot++;
    edge[z][tot] = y, nxt[z][tot] = head[z][x], head[z][x] = tot;
}
bool d[M];
int main()
{
    queue<int> q;
    q.push(1);
    cin >> a >> b;
    for (int i = 1; i <= a; i++)
    {
        cin >> k[i];
    }
    for (int i = 1; i <= b; i++)
    {
        int o, u, p;
        cin >> o >> u >> p;
        add(o, u, 0);
        add(u, o, 1);
        if (p == 2)
        {
            add(u, o, 0);
            add(o, u, 1);
        }
    }
    memset(c, 0x3f3f3f, sizeof c);
    while (!q.empty())
    {
        int o = q.front();
        q.pop();
        c[o] = min(c[o], k[o]);
        for (int i = head[0][o]; i; i = nxt[0][i])
        {
            if (c[o] < c[edge[0][i]])
            {
                c[edge[0][i]] = c[o];
                q.push(edge[0][i]);
            }
        }
    }
    q.push(a);
    while (!q.empty())
    {
        int o = q.front();
        q.pop();
        c1[o] = max(c1[o], k[o]);
        for (int i = head[1][o]; i; i = nxt[1][i])
        {
            if (c1[o] > c1[edge[1][i]])
            {
                c1[edge[1][i]] = c1[o];
                q.push(edge[1][i]);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= a; i++)
    {
        ans = max(ans, c1[i] - c[i]);
    }
    cout << ans;
    return 0;
}