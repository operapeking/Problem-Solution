/*
三角形
url: https://www.acwing.com/problem/content/666/
*/
#include <iostream>
#include <cstdio>
    using namespace std;
int main()
{
    double a, b, c;
    cin >> a >> b >> c;
    bool x = 0;
    if (a + b <= c)
        x = 1;
    if (a + c <= b)
        x = 1;
    if (b + c <= a)
        x = 1;
    if (x == 1)
    {

        double ans = (a + b) * c / 2.0;
        printf("Area = %.1lf", ans);
    }
    else
        printf("Perimetro = %.1lf", a + b + c);
    return 0;
}