/*
动态树
url: https://www.acwing.com/problem/content/2541/
*/
#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, m;
struct Node
{
    int s[2], p, v;
    int sum, rev;
} tr[N];
int stk[N];

void PushReverse(int x) // 旋转子树 x
{
    swap(tr[x].s[0], tr[x].s[1]);
    tr[x].rev ^= 1;
}

void PushUp(int x) // 向上传异或
{
    tr[x].sum = tr[tr[x].s[0]].sum ^ tr[x].v ^ tr[tr[x].s[1]].sum;
}

void PushDown(int x) // 向下传懒标记（是否旋转）
{
    if (tr[x].rev)
    {
        PushReverse(tr[x].s[0]), PushReverse(tr[x].s[1]);
        tr[x].rev = 0;
    }
}

bool IsRoot(int x) // 是否是当前 Splay 的根节点
{
    return tr[tr[x].p].s[0] != x && tr[tr[x].p].s[1] != x;
}

void Rotate(int x) // Splay 旋转
{
    int y = tr[x].p, z = tr[y].p;
    int k = tr[y].s[1] == x;
    if (!IsRoot(y))
        tr[z].s[tr[z].s[1] == y] = x;
    tr[x].p = z;
    tr[y].s[k] = tr[x].s[k ^ 1], tr[tr[x].s[k ^ 1]].p = y;
    tr[x].s[k ^ 1] = y, tr[y].p = x;
    PushUp(y), PushUp(x);
}

void Splay(int x) // Splay
{
    int top = 0, r = x;
    stk[++top] = r;
    while (!IsRoot(r))
        stk[++top] = r = tr[r].p;
    while (top)
        PushDown(stk[top--]);
    while (!IsRoot(x))
    {
        int y = tr[x].p, z = tr[y].p;
        if (!IsRoot(y))
            if ((tr[y].s[1] == x) ^ (tr[z].s[1] == y))
                Rotate(x);
            else
                Rotate(y);
        Rotate(x);
    }
}

void Access(int x) // 建立一条从根到 x 的路径，同时将 x 变成 splay 的根节点
{
    int z = x;
    for (int y = 0; x; y = x, x = tr[x].p)
    {
        Splay(x);
        tr[x].s[1] = y, PushUp(x);
    }
    Splay(z);
}

void MakeRoot(int x) // 将 x 旋转到原树的根节点
{
    Access(x);
    PushReverse(x);
}

int FindRoot(int x) // 当前子树的根节点
{
    Access(x);
    while (tr[x].s[0])
        PushDown(x), x = tr[x].s[0];
    Splay(x);
    return x;
}

void Split(int x, int y) // 给 x 和 y 之间的路径建立一个 splay，其根节点是 y
{
    MakeRoot(x);
    Access(y);
}

void Link(int x, int y) // 添加 x 到 y 的边
{
    MakeRoot(x);
    if (FindRoot(y) != x)
        tr[x].p = y;
}

void Cut(int x, int y) // 删除 x 到 y 的边
{
    MakeRoot(x);
    if (FindRoot(y) == x && tr[y].p == x && !tr[y].s[0])
    {
        tr[x].s[1] = tr[y].p = 0;
        PushUp(x);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> tr[i].v;
    while (m--)
    {
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 0)
        {
            Split(x, y);
            cout << tr[y].sum << "\n";
        }
        else if (t == 1)
            Link(x, y);
        else if (t == 2)
            Cut(x, y);
        else
        {
            Splay(x);
            tr[x].v = y;
            PushUp(x);
        }
    }
    return 0;
}