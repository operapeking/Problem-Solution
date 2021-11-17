/*
单链表
url: https://www.acwing.com/problem/content/828/
*/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int a, b;
const int maxn = 1e6 + 5;
int idx, head;
int c[maxn];
int ne[maxn];
void out(int x)
{
    if (ne[x] == -1)
        return;
    printf("%d ", c[x]);
    out(ne[x]);
}
int main()
{
    cin >> a;
    memset(ne, -1, sizeof ne);
    for (int i = 1; i <= a; i++)
    {
        char o[2];
        cin >> o;
        if (o[0] == 'H')
        {
            int p;
            cin >> p;
            idx++;
            c[idx] = p;
            ne[idx] = head;
            head = idx;
        }
        else if (o[0] == 'I')
        {
            int p, l;
            cin >> p >> l;
            idx++;
            c[idx] = l;
            ne[idx] = ne[p];
            ne[p] = idx;
        }
        else if (o[0] == 'D')
        {
            int p;
            cin >> p;
            if (p == 0)
                head = ne[head];
            else
            {
                ne[p] = ne[ne[p]];
            }
        }
    }
    out(head);
    return 0;
}