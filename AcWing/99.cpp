/*
激光炸弹
url: https://www.acwing.com/problem/content/101/
*/
#include <iostream>
using namespace std;
const int N = 5010;
int n, R, x, y, w, ans;
int s[N][N];
int main()
{
    cin >> n >> R;
    R = min(R, 5002);
    for (int i = 0; i < n; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        x++, y++;
        s[x][y] += w;
    }
    for (int i = 1; i <= 5001; i++)
    {
        for (int j = 1; j <= 5001; j++)
        {
            s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
        }
    }
    for (int i = R; i <= 5001; i++)
    {
        for (int j = R; j <= 5001; j++)
        {
            ans = max(ans, s[i][j] - s[i - R][j] - s[i][j - R] + s[i - R][j - R]);
        }
    }
    cout << ans;
    return 0;
}