/*
Dijkstra求最短路 II
url: https://www.acwing.com/problem/content/852/
*/
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
typedef pair<int, int> PII;
const int N = 100010, M = 200010, INF = 0x3f3f3f3f;
int n, m, s;
int tot, head[N], ver[M], edge[M], nxt[M];
bool vis[N];
int dis[N];
priority_queue<PII, vector<PII>, greater<PII>> Q;
void add(int x, int y, int d)
{
    ver[++tot] = y;
    edge[tot] = d;
    nxt[tot] = head[x];
    head[x] = tot;
}
void dijkstra()
{
    vis[s] = 0;
    dis[s] = 0;
    Q.push(make_pair(0, s));
    while (!Q.empty())
    {
        int x = Q.top().second;
        Q.pop();
        if (vis[x])
            continue;
        vis[x] = true;
        for (int i = head[x]; i; i = nxt[i])
        {
            int y = ver[i];
            if (dis[x] + edge[i] < dis[y])
            {
                dis[y] = dis[x] + edge[i];
                Q.push(make_pair(dis[y], y));
            }
        }
    }
}
int main()
{
    memset(dis, 0x3f, sizeof(dis));
    s = 1;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }
    dijkstra();
    dis[n] == INF ? printf("-1 ") : printf("%d ", dis[n]);
    return 0;
}