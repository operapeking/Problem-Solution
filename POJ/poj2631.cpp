#include <iostream>
#include <algorithm>

using namespace std;
const int N = 10000, M = 20000;
int idx, head[N + 10], ver[M + 10], edge[M + 10], nxt[M + 10];
bool vis[N];
int dis[N];
int ans;

void add(int u, int v, int w)
{
    ver[++idx] = v;
    edge[idx] = w;
    nxt[idx] = head[u];
    head[u] = idx;
}

void dfs(int u)
{
    vis[u] = true;
    for (int i = head[u]; i; i = nxt[i])
    {
        int v = ver[i];
        if (vis[v])
            continue;
        dfs(v);
        ans = max(ans, dis[u] + dis[v] + edge[i]);
        dis[u] = max(dis[u], dis[v] + edge[i]);
    }
}

int main()
{
    int u, v, w;
    while (cin >> u >> v >> w)
    {
        add(u, v, w);
        add(v, u, w);
    }
    dfs(1);
    cout << ans;
    return 0;
}