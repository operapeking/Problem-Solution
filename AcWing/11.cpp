/*
背包问题求方案数
url: https://www.acwing.com/problem/content/11/
*/
#include <iostream>
#include <cstring>
using namespace std;
const int N = 1010, mod = 1e9 + 7;
int n, m;
int f[N], g[N];
int main()
{
    cin >> n >> m;
    memset(f, -0x3f, sizeof(f));
    f[0] = 0;
    g[0] = 1;
    for (int i = 0; i < n; i++)
    {
        int v, w;
        cin >> v >> w;
        for (int j = m; j >= v; j--)
        {
            int maxv = max(f[j], f[j - v] + w);
            int cnt = 0;
            if (maxv == f[j])
                cnt += g[j];
            if (maxv == f[j - v] + w)
                cnt += g[j - v];
            g[j] = cnt % mod;
            f[j] = maxv;
        }
    }
    int res = 0;
    for (int i = 0; i <= m; i++)
        res = max(res, f[i]);
    int cnt = 0;
    for (int i = 0; i <= m; i++)
    {
        if (res == f[i])
            cnt = (cnt + g[i]) % mod;
    }
    cout << cnt << endl;
    return 0;
}