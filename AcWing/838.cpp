/*
堆排序
url: https://www.acwing.com/problem/content/840/
*/
#include <cstdio>
#include <queue>
using namespace std;
int n, m;
priority_queue<int, vector<int>, greater<int>> Q;
int main()
{
    scanf("%d%d", &n, &m);
    while (n--)
    {
        int in;
        scanf("%d", &in);
        Q.push(in);
    }
    while (m--)
    {
        printf("%d ", Q.top());
        Q.pop();
    }
}