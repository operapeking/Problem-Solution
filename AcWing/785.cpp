/*
快速排序
url: https://www.acwing.com/problem/content/787/
*/
#include <algorithm>
#include <iostream>
using namespace std;
int n, a[100005];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}