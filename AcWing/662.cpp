/*
点的坐标
url: https://www.acwing.com/problem/content/664/
*/
#include <iostream>
using namespace std;
float a, b;
int main()
{
    cin >> a >> b;
    if (a > 0 && b > 0)
    {
        cout << "Q1";
        return 0;
    }
    if (a > 0 && b < 0)
    {
        cout << "Q4";
        return 0;
    }
    if (a < 0 && b < 0)
    {
        cout << "Q3";
        return 0;
    }
    if (a < 0 && b > 0)
    {
        cout << "Q2";
        return 0;
    }
    if (a == 0 && b == 0)
    {
        cout << "Origem";
        return 0;
    }
    if (a == 0)
    {
        cout << "Eixo Y";
        return 0;
    }
    cout << "Eixo X";
    return 0;
}