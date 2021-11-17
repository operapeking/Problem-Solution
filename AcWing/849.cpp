/*
Dijkstra求最短路 I
url: https://www.acwing.com/problem/content/851/
*/
#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
int n, m;
int u, v, w;
int a[505][505];
int d[505];
bool V[505];
void dijkstra()
{
    for (int i = 1; i < n; i++)
    {
        int x = 0;
        for (int j = 1; j <= n; j++)
        {
            if (!V[j] && (x == 0 || d[j] < d[x]))
                x = j;
        }
        V[x] = 1;
        for (int j = 1; j <= n; j++)
        {
            d[j] = min(d[j], d[x] + a[x][j]);
        }
    }
}
int main()
{
    memset(a, 0x3f, sizeof a);
    memset(d, 0x3f, sizeof d);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v >> w;
        a[u][v] = min(a[u][v], w);
    }
    d[1] = 0;
    dijkstra();
    if (d[n] == 0x3f3f3f3f)
        cout << -1 << " ";
    else
        cout << d[n] << " ";
    return 0;
}