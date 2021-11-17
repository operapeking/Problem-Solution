/*
通信线路
url: https://www.acwing.com/problem/content/342/
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1000000 + 10, M = 10000000 + 10;

int n, p, k;
int tot = 0;
priority_queue<pair<int, int>> q;
struct node
{
    int ver, nex, edge;
} po[M];
int head[N], dis[N];
bool v[N];

void add(int x, int y, int z)
{
    po[++tot].ver = y, po[tot].edge = z;
    po[tot].nex = head[x], head[x] = tot;
}

void dijkstra()
{
    memset(dis, 0x3f, sizeof(dis));
    dis[1] = 0;
    q.push(make_pair(0, 1));
    while (q.size())
    {
        int x = q.top().second;
        q.pop();
        if (v[x])
            continue;
        v[x] = true;
        for (int i = head[x]; i; i = po[i].nex)
        {
            int y = po[i].ver, z = max(po[i].edge, dis[x]);
            if (dis[y] > z)
            {
                dis[y] = z;
                q.push(make_pair(-dis[y], y));
            }
        }
    }
}

int main()
{
    scanf("%d%d%d", &n, &p, &k);
    for (int i = 1, x, y, z; i <= p; i++)
    {
        scanf("%d%d%d", &x, &y, &z);
        add(x, y, z);
        add(y, x, z);
        for (int j = 1, z1 = 0; j <= k; j++)
        {
            add(x + (j - 1) * n, y + j * n, z1);
            add(y + (j - 1) * n, x + j * n, z1);
            add(x + j * n, y + j * n, z);
            add(y + j * n, x + j * n, z);
        }
    }
    for (int i = 1, z = 0; i <= k; i++)
        add(i * n, (i + 1) * n, z);

    dijkstra();

    if (dis[(k + 1) * n] == 1061109567)
        puts("-1");
    else
        printf("%d", dis[(k + 1) * n]);
    return 0;
}