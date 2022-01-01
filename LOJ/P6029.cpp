/*
#6029. 「雅礼集训 2017 Day1」市场
url: https://loj.ac/p/6029
*/
#include <cmath>
#include <iostream>

using namespace std;
const int N = 100010;
int n, q;
int mn[N << 2], mx[N << 2], tag[N << 2];
long long sum[N << 2], ans;

inline void Update(int p, int l, int r, int val)
{
    mn[p] += val;
    mx[p] += val;
    sum[p] += 1ll * (r - l + 1) * val;
    tag[p] += val;
}

inline void PushDown(int p, int l, int r)
{
    if (!tag[p])
        return;
    int mid = (r + l) >> 1;
    Update(p << 1, l, mid, tag[p]);
    Update(p << 1 | 1, mid + 1, r, tag[p]);
    tag[p] = 0;
}

inline void PushUp(int p)
{
    mn[p] = min(mn[p << 1], mn[p << 1 | 1]);
    mx[p] = max(mx[p << 1], mx[p << 1 | 1]);
    sum[p] = sum[p << 1] + sum[p << 1 | 1];
}

void Addition(int p, int l, int r, int x, int y, int val)
{
    if (x <= l && r <= y)
        return Update(p, l, r, val);

    PushDown(p, l, r);
    int mid = (l + r) >> 1;
    if (x <= mid)
        Addition(p << 1, l, mid, x, y, val);
    if (mid < y)
        Addition(p << 1 | 1, mid + 1, r, x, y, val);
    PushUp(p);
}

inline int Div(int x, int y)
{
    return floor(1.0 * x / y);
}

void Division(int p, int l, int r, int x, int y, int val)
{
    if (x <= l && r <= y && Div(mn[p], val) - mn[p] == Div(mx[p], val) - mx[p])
        return Update(p, l, r, Div(mn[p], val) - mn[p]);

    PushDown(p, l, r);
    int mid = (l + r) >> 1;
    if (x <= mid)
        Division(p << 1, l, mid, x, y, val);
    if (mid < y)
        Division(p << 1 | 1, mid + 1, r, x, y, val);
    PushUp(p);
}

int AskMininum(int p, int l, int r, int x, int y)
{
    if (x <= l && r <= y)
        return mn[p];

    PushDown(p, l, r);
    int mid = (l + r) >> 1, res = __INT_MAX__;
    if (x <= mid)
        res = min(res, AskMininum(p << 1, l, mid, x, y));
    if (mid < y)
        res = min(res, AskMininum(p << 1 | 1, mid + 1, r, x, y));
    return res;
}

long long AskSum(int p, int l, int r, int x, int y)
{
    if (x <= l && r <= y)
        return sum[p];

    PushDown(p, l, r);
    int mid = (l + r) >> 1;
    long long res = 0;
    if (x <= mid)
        res += AskSum(p << 1, l, mid, x, y);
    if (mid < y)
        res += AskSum(p << 1 | 1, mid + 1, r, x, y);
    return res;
}

int main()
{
    // freopen("market.in", "r", stdin);
    // freopen("market.out", "w", stdout);
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        Addition(1, 0, n - 1, i, i, val);
    }
    while (q--)
    {
        int op, l, r, k;
        cin >> op >> l >> r;
        switch (op)
        {
        case 1:
            cin >> k;
            Addition(1, 0, n - 1, l, r, k);
            break;

        case 2:
            cin >> k;
            Division(1, 0, n - 1, l, r, k);
            break;

        case 3:
            cout << AskMininum(1, 0, n - 1, l, r) << "\n";
            break;

        default:
            cout << AskSum(1, 0, n - 1, l, r) << "\n";
            break;
        }
    }
    return 0;
}