/*
多重背包问题 II
url: https://www.acwing.com/problem/content/5/
*/
#include <algorithm>
#include <iostream>
using namespace std;
const int N = 2010, M = 25000;
int n, V, cnt;
int v[M], w[M];
int f[N];
int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> V;
    for (int i = 1; i <= n; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        int k = 1;
        while (k <= z)
        {
            cnt++;
            v[cnt] = k * x;
            w[cnt] = k * y;
            z -= k;
            k <<= 1;
        }
        if (z)
        {
            cnt++;
            v[cnt] = z * x;
            w[cnt] = z * y;
        }
    }
    for (int i = 1; i <= cnt; i++)
        for (int j = V; j >= v[i]; j--)
            f[j] = max(f[j], f[j - v[i]] + w[i]);
    cout << f[V];
    return 0;
}