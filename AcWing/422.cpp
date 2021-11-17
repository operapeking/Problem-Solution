/*
校门外的树
url: https://www.acwing.com/problem/content/424/
*/
#include <iostream>
using namespace std;
int l, m;
int r[10005];
int a, b, ans = 0;
int main()
{
    cin >> l >> m;
    for (int i = 0; i <= l; i++)
    {
        r[i] = 1;
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> a >> b;
        for (int j = a; j <= b; j++)
        {
            r[j] = 0;
        }
    }
    for (int i = 0; i <= l; i++)
    {
        if (r[i] == 1)
            ans++;
    }
    cout << ans;
    return 0;
}