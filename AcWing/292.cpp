/*
炮兵阵地
url: https://www.acwing.com/problem/content/294/
*/
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int N = 14, M = 1 << 12, MOD = 1e8;

int n, m;
int g[110];
vector<int> state;
int cnt[M];
int f[2][M][M];
bool check(int state)
{
    for (int i = 0; i < m; i++)
        if ((state >> i & 1) && ((state >> i + 1 & 1) | (state >> i + 2 & 1)))
            return false;
    return true;
}
int count(int state)
{
    int res = 0;
    for (int i = 0; i < m; i++)
        res += state >> i & 1;
    return res;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c;
            cin >> c;
            if (c == 'H')
                g[i] += 1 << j;
        }
    }
    for (int i = 0; i < 1 << m; i++)
        if (check(i))
        {
            state.push_back(i);
            cnt[i] = count(i);
        }
    for (int i = 1; i <= n + 2; i++)
        for (int j = 0; j < state.size(); j++)
            for (int k = 0; k < state.size(); k++)
                for (int u = 0; u < state.size(); u++)
                {
                    int a = state[j], b = state[k], c = state[u];
                    if ((a & b) | (b & c) | (a & c))
                        continue;
                    if (g[i - 1] & a | g[i] & b)
                        continue;
                    f[i & 1][j][k] = max(f[i & 1][j][k], f[i - 1 & 1][u][j] + cnt[b]);
                }
    cout << f[n + 2 & 1][0][0] << endl;
    return 0;
}