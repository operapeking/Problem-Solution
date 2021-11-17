/*
第k个数
url: https://www.acwing.com/problem/content/788/
*/
#include <algorithm>
#include <iostream>
using namespace std;
int n, k, a[100005], last, num;
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(1 + a, 1 + a + n);
    for (int i = 1; i <= n; i++)
    {
        if (a[i] != last)
        {
            num++;
        }
        if (num == k)
        {
            cout << a[i];
        }
        a[i] = last;
    }
}