/*
spfa求最短路
url: https://www.acwing.com/problem/content/853/
*/
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;
typedef pair<int, int> PII;
const int N = 100010, M = 200010;
int n, m, s;
int tot, head[N], ver[M], edge[M], nxt[M];
int dist[N];
bool vis[N];

void add(int u, int v, int w)
{
    ver[++tot] = v;
    edge[tot] = w;
    nxt[tot] = head[u];
    head[u] = tot;
}

void spfa()
{
    queue<PII> Q;
    memset(dist, 0x3f, sizeof(dist));
    dist[s] = 0;
    Q.push(make_pair(0, s));
    while (!Q.empty())
    {
        int x = Q.front().second;
        Q.pop();
        for (int i = head[x]; i; i = nxt[i])
        {
            int y = ver[i];
            if (dist[y] > dist[x] + edge[i])
            {
                dist[y] = dist[x] + edge[i];
                vis[y] = true;
                Q.push(make_pair(dist[y], y));
            }
        }
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    s = 1;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
    }
    spfa();
    if (dist[n] == 0x3f3f3f3f)
        cout << "impossible\n";
    else
        cout << dist[n];
    return 0;
}