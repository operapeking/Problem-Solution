/*
01背包问题
url: https://www.acwing.com/problem/content/2/
*/
#include <algorithm>
#include <iostream>
using namespace std;
const int N = 1010;
int n, V;
int v, w;
int f[N];
int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> V;
    for (int i = 1; i <= n; i++)
    {
        cin >> v >> w;
        for (int j = V; j >= v; j--)
            f[j] = max(f[j], f[j - v] + w);
    }
    cout << f[V];
    return 0;
}