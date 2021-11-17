/*
动态中位数
url: https://www.acwing.com/problem/content/108/
*/
#include <iostream>
#include <queue>
using namespace std;
int P;
int main()
{
    cin >> P;
    while (P--)
    {
        int m, n;
        cin >> m >> n;
        cout << m << " " << (n + 1) / 2 << endl;
        priority_queue<int> down;
        priority_queue<int, vector<int>, greater<int>> up;
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            if (down.empty() || x <= down.top())
                down.push(x);
            else
                up.push(x);
            if (down.size() > up.size() + 1)
                up.push(down.top()), down.pop();
            if (up.size() > down.size())
                down.push(up.top()), up.pop();
            if (i % 2)
            {
                cout << down.top() << " ";
                if (++cnt % 10 == 0)
                    puts("");
            }
        }
        if (cnt % 10)
            puts("");
    }
    return 0;
}