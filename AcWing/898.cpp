/*
数字三角形
url: https://www.acwing.com/problem/content/900/
*/
#include <iostream>
using namespace std;
int n, map[505][505], ans[505][505];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cin >> map[i][j];
            ans[i][j] = map[i][j];
        }
    }
    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            ans[i][j] = map[i][j] + max(ans[i + 1][j], ans[i + 1][j + 1]);
        }
    }
    cout << ans[1][1];
    return 0;
}