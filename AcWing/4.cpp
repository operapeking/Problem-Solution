/*
多重背包问题 I
url: https://www.acwing.com/problem/content/4/
*/
#include <algorithm>
#include <iostream>
using namespace std;
const int N = 110;
int n, V;
int v[N], w[N], s[N];
int f[N][N];
int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> V;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i] >> w[i] >> s[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= V; j++)
        {
            f[i][j] = f[i - 1][j];
            for (int k = 0; k <= s[i] && v[i] * k <= j; k++)
                f[i][j] = max(f[i][j], f[i - 1][j - v[i] * k] + w[i] * k);
        }
    }
    cout << f[n][V];
    return 0;
}