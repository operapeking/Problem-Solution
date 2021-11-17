/*
最长公共子序列
url: https://www.acwing.com/problem/content/899/
*/
#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
const int MAXN = 10005;
int N, M;
int f[MAXN][MAXN];
char a[MAXN], b[MAXN];
int main()
{
    cin >> N >> M;
    scanf("%s", a + 1);
    scanf("%s", b + 1);
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            if (a[i] == b[j])
                f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
        }
    }
    cout << f[N][M];
    return 0;
}