/*
金明的预算方案
url: https://www.acwing.com/problem/content/489/
*/
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
typedef pair<int, int> PII;
const int N = 65, M = 32010;
int n, m;
PII master[N];
vector<PII> servent[N];
int f[M];
int main()
{
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= n; i++)
    {
        int v, p, q;
        scanf("%d%d%d", &v, &p, &q);
        p *= v;
        if (!q)
            master[i] = make_pair(v, p);
        else
            servent[q].push_back(make_pair(v, p));
    }
    for (int i = 1; i <= n; i++)
    {
        int num = 1 << servent[i].size();
        for (int u = m; u >= 0; u--)
        {
            for (int j = 0; j < num; j++)
            {
                int v = master[i].first, w = master[i].second;
                for (int k = 0; k < servent[i].size(); k++)
                {
                    if (j >> k & 1)
                    {
                        v += servent[i][k].first;
                        w += servent[i][k].second;
                    }
                }
                if (u >= v)
                {
                    f[u] = max(f[u], f[u - v] + w);
                }
            }
        }
    }
    printf("%d\n", f[m]);
    return 0;
}