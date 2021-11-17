/*
棋盘覆盖
url: https://www.acwing.com/problem/content/374/
*/
#include <cstring>
#include <iostream>
#include <utility>
using namespace std;
const int N = 110;
int n, t;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int color[N][N];
pair<int, int> match[N][N];
bool vis[N][N];
bool ban[N][N];

bool find(int x, int y)
{
    if (ban[x][y])
        return false;
    for (int i = 0; i < 4; i++)
    {
        int mx = x + dx[i], my = y + dy[i];
        if (1 <= mx && mx <= n && 1 <= my && my <= n && !vis[mx][my] && !ban[mx][my])
        {
            vis[mx][my] = true;
            if ((!match[mx][my].first && !match[mx][my].second) || find(match[mx][my].first, match[mx][my].second))
            {
                match[mx][my] = make_pair(x, y);
                return true;
            }
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> t;
    for (int i = 1; i <= t; i++)
    {
        int x, y;
        cin >> x >> y;
        ban[x][y] = true;
    }
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            memset(vis, 0, sizeof(vis));
            if ((i + j) % 2 && find(i, j))
                res++;
        }
    }
    cout << res;
    return 0;
}