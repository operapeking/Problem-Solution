/*
一个简单的整数问题2
url: https://www.acwing.com/problem/content/244/
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100010, M = 100010;
int n, m;
int a[N];
int s, t, b;
ll d[N << 2], lazy[N << 2];
ll ans;
void build(int l, int r, int p)
{
    if (l == r)
    {
        d[p] = a[l];
        return;
    }
    int mid = l + (r - l >> 1);
    build(l, mid, p << 1), build(mid + 1, r, p << 1 | 1);
    d[p] = d[p << 1] + d[p << 1 | 1];
    return;
}
void change(int l, int r, int p)
{
    if (s <= l && r <= t)
    {
        d[p] += (r - l + 1) * b;
        lazy[p] += b;
        return;
    }
    int mid = l + (r - l >> 1);
    if (lazy[p])
    {
        lazy[p << 1] += lazy[p], d[p << 1] += (mid - l + 1) * lazy[p];
        lazy[p << 1 | 1] += lazy[p], d[p << 1 | 1] += (r - mid) * lazy[p];
        lazy[p] = 0;
    }
    if (s <= mid)
        change(l, mid, p << 1);
    if (mid < t)
        change(mid + 1, r, p << 1 | 1);
    d[p] = d[p << 1] + d[p << 1 | 1];
    return;
}
void ask(int l, int r, int p)
{
    if (s <= l && r <= t)
    {
        ans += d[p];
        return;
    }
    int mid = l + (r - l >> 1);
    if (lazy[p])
    {
        lazy[p << 1] += lazy[p], d[p << 1] += (mid - l + 1) * lazy[p];
        lazy[p << 1 | 1] += lazy[p], d[p << 1 | 1] += (r - mid) * lazy[p];
        lazy[p] = 0;
    }
    if (s <= mid)
        ask(l, mid, p << 1);
    if (mid < t)
        ask(mid + 1, r, p << 1 | 1);
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, n, 1);
    while (m--)
    {
        char op[2];
        cin >> op;
        cin >> s >> t;
        if (op[0] == 'C')
        {
            cin >> b;
            change(1, n, 1);
        }
        else
        {
            ans = 0;
            ask(1, n, 1);
            cout << ans << endl;
        }
    }
    return 0;
}