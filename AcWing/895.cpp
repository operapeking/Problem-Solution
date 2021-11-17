/*
最长上升子序列
url: https://www.acwing.com/problem/content/897/
*/
#include <algorithm>
#include <iostream>
using namespace std;
const int N = 1010;
int n, a, f[N], cnt;
int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i <= n; i++)
        f[i] = -__INT_MAX__;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        if (a > f[cnt])
        {
            f[++cnt] = a;
            continue;
        }
        int x = lower_bound(f + 1, f + 1 + cnt, a) - f;
        f[x] = a;
    }
    cout << cnt;
    return 0;
}