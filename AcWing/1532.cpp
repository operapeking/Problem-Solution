/*
找硬币
url: https://www.acwing.com/problem/content/1534/
*/
#include <algorithm>
#include <iostream>
using namespace std;
int n, m;
int a[100005];
int a1, a2;
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        int j = n;
        while (a[i] + a[j] > m)
            j--;
        if (a[i] + a[j] == m && i != j)
        {
            printf("%d %d", a[i], a[j]);
            return 0;
        }
    }
    printf("No Solution");
    return 0;
}