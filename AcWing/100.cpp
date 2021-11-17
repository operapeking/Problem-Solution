/*
增减序列
url: https://www.acwing.com/problem/content/102/
*/
#include <algorithm>
#include <iostream>
using namespace std;
const int N = 100010;
long long n, a[N], b[N], p, q;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        b[i] = a[i] - a[i - 1];
    for (int i = 2; i <= n; i++)
    {
        if (b[i] > 0)
            p += b[i];
        else
            q -= b[i];
    }
    cout << max(p, q) << "\n"
         << abs(p - q) + 1 << endl;

    return 0;
}