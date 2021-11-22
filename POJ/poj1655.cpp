#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
const int N = 20010;
int T, n;
vector<int> nxt[N];
bool vis[N];
int SIZE[N];
int ans = __INT_MAX__, poi;

void dfs(int u)
{
    vis[u] = true;
    int max_part = 0;
    SIZE[u] = 1;
    for (int i = 0; i < nxt[u].size(); i++)
    {
        int v = nxt[u][i];
        if (vis[v])
            continue;
        dfs(v);
        max_part = max(max_part, SIZE[v]);
        SIZE[u] += SIZE[v];
    }
    max_part = max(max_part, n - SIZE[u]);
    if (ans > max_part)
    {
        ans = max_part;
        poi = u;
    }
}

int main()
{
    cin >> T;
    while (T--)
    {
        ans = __INT_MAX__;

        cin >> n;
        for (int i = 1; i <= n; i++)
            nxt[i].clear(), SIZE[i] = 0, vis[i] = false;
        for (int i = 1; i < n; i++)
        {
            int u, v;
            cin >> u >> v;
            nxt[u].push_back(v);
            nxt[v].push_back(u);
        }
        dfs(1);
        cout << poi << " " << ans << "\n";
    }
    return 0;
}