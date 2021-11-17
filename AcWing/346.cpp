/*
走廊泼水节
url: https://www.acwing.com/problem/content/348/
*/
#include <algorithm>
#include <iostream>
using namespace std;
const int N = 6010, M = 6010;
int n, m, fa[N];
long long s[N];
struct edges
{
    int x, y, z;
    bool operator<(edges &b) const
    {
        return z < b.z;
    }
} edge[M << 1];
int find(int x)
{
    if (x == fa[x])
        return x;
    return fa[x] = find(fa[x]);
}
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        m = n - 1;
        for (int i = 1; i <= n; i++)
            fa[i] = i, s[i] = 1;
        for (int i = 1; i <= m; i++)
        {
            int x, y, z;
            cin >> x >> y >> z;
            edge[i] = {x, y, z};
        }
        sort(edge + 1, edge + 1 + m);
        long long res = 0;
        for (int i = 1; i <= m; i++)
        {
            int x = find(edge[i].x), y = find(edge[i].y), z = edge[i].z;
            if (x != y)
            {
                res += (s[x] * s[y] - 1) * (z + 1);
                fa[x] = y;
                s[y] += s[x];
            }
        }
        cout << res << endl;
    }
    return 0;
}