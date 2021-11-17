/*
平方矩阵 II
url: https://www.acwing.com/problem/content/756/
*/
#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
    int n;
    while (cin >> n)
    {
        if (n == 0)
            return 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                printf("%d ", abs(i - j) + 1);
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}