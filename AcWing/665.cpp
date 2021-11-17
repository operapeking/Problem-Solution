/*
倍数
url: https://www.acwing.com/problem/content/667/
*/
#include <algorithm>
#include <iostream>
using namespace std;
int a, b;
int main()
{
    cin >> a >> b;
    if (a < b)
    {
        swap(a, b);
    }
    if (a % b == 0)
        cout << "Sao Multiplos";
    else
        cout << "Nao sao Multiplos";
    return 0;
}