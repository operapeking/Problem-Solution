/*
郁闷的出纳员
url: https://www.acwing.com/problem/content/952/
*/
#include <iostream>

using namespace std;
const int N = 300010, inf = 1e9;
int n, Min, delta;

struct Node
{
    int val, fa, son[2];
    int size;
    void Init(int _val, int _fa)
    {
        val = _val;
        fa = _fa;
    }
} tr[N];
int root, idx;

void PushUp(int x)
{
    tr[x].size = tr[tr[x].son[0]].size + tr[tr[x].son[1]].size + 1;
}

void Rotate(int x)
{
    int y = tr[x].fa, z = tr[y].fa;
    if (tr[z].son[0] == y)
    {
        if (tr[y].son[0] == x) // Zig
        {
            tr[z].son[0] = x;
            tr[y].son[0] = tr[x].son[1];
            tr[tr[x].son[1]].fa = y;
            tr[x].son[1] = y;
        }
        else // Zag
        {
            tr[z].son[0] = x;
            tr[y].son[1] = tr[x].son[0];
            tr[tr[x].son[0]].fa = y;
            tr[x].son[0] = y;
        }
    }
    else
    {
        if (tr[y].son[0] == x) // Zig
        {
            tr[z].son[1] = x;
            tr[y].son[0] = tr[x].son[1];
            tr[tr[x].son[1]].fa = y;
            tr[x].son[1] = y;
        }
        else // Zag
        {
            tr[z].son[1] = x;
            tr[y].son[1] = tr[x].son[0];
            tr[tr[x].son[0]].fa = y;
            tr[x].son[0] = y;
        }
    }
    tr[x].fa = z;
    tr[y].fa = x;
    PushUp(y), PushUp(x);
}

void Splay(int x, int k)
{
    int y = tr[x].fa, z = tr[y].fa;
    while (y != k)
    {
        if (z != k)
        {
            if ((tr[y].son[1] == x) ^ (tr[z].son[1] == y))
                Rotate(x);
            else
                Rotate(y);
        }
        Rotate(x);
        y = tr[x].fa, z = tr[y].fa;
    }
    if (!k)
        root = x;
}

int Insert(int val)
{
    int u = root, fa = 0;
    while (u)
    {
        fa = u;
        if (tr[u].val > val)
            u = tr[u].son[0];
        else
            u = tr[u].son[1];
    }
    u = ++idx;
    tr[u].Init(val, fa);
    if (fa)
    {
        if (tr[fa].val > val)
            tr[fa].son[0] = u;
        else
            tr[fa].son[1] = u;
    }
    Splay(u, 0);
    return u;
}

int GetNextByVal(int val)
{
    int u = root, res;
    while (u)
    {
        if (tr[u].val >= val)
        {
            res = u;
            u = tr[u].son[0];
        }
        else
            u = tr[u].son[1];
    }
    return res;
}

int GetValByRank(int Rank)
{
    int u = root;
    while (u)
    {
        if (tr[tr[u].son[0]].size >= Rank)
            u = tr[u].son[0];
        else if (tr[tr[u].son[0]].size + 1 == Rank)
            return tr[u].val;
        else
            Rank -= tr[tr[u].son[0]].size + 1, u = tr[u].son[1];
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> Min;
    int L = Insert(-inf), R = Insert(inf);
    int tot = 0;
    while (n--)
    {
        char op[5];
        int k;
        cin >> op >> k;
        if (op[0] == 'I') // 增加一个员工
        {
            if (k >= Min)
            {
                k -= delta; // 与其他员工一致（k + delta 是当前实际工资）
                Insert(k);
                tot++;
            }
        }
        else if (op[0] == 'A')
            delta += k; // 为所有员工加工资
        else if (op[0] == 'S')
        { // 减工资
            delta -= k;
            R = GetNextByVal(Min - delta); // 删除离职的员工(第一个 x + delta >= Min 之前的所有人)
            Splay(R, 0), Splay(L, R);
            tr[L].son[1] = 0;
            PushUp(L), PushUp(R);
        }
        else if (op[0] == 'F')
        { // 查询第 k 多的工资
            if (tr[root].size - 2 < k)
                cout << "-1"
                     << "\n";
            else
                cout << GetValByRank(tr[root].size - k) + delta << "\n"; // 查询第 k 大的数（平衡树中为顺序）
        }
    }
    cout << tot - (tr[root].size - 2);
    return 0;
}