/*
星星还是树
url: https://www.acwing.com/problem/content/3170/
*/
#include <bits/stdc++.h>

using namespace std;
typedef pair<double, double> PDD;
const int N = 55;
int n;
PDD a[N];
double ans = 1e8;

double Rand(double l, double r)
{
    return 1.0 * rand() / RAND_MAX * (r - l) + l;
}

double Dis(double x1, double y1, double x2, double y2)
{
    double X = x1 - x2;
    double Y = y1 - y2;
    return sqrt(X * X + Y * Y);
}

double Sum(double x, double y)
{
    double res = 0;
    for (int i = 1; i <= n; i++)
    {
        res += Dis(x, y, a[i].first, a[i].second);
    }
    ans = min(ans, res);
    return res;
}

void SimulateAnneal()
{
    PDD p(Rand(0, 1e4), Rand(0, 1e4));
    for (double t = 1e4; t > 1e-2; t *= 0.99)
    {
        PDD np(p.first + Rand(-t, t), p.second + Rand(-t, t));
        double delta = Sum(np.first, np.second) - Sum(p.first, p.second);
        if (exp(-delta / t) > Rand(0, 1))
            p = np;
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%lf%lf", &a[i].first, &a[i].second);
    for (int i = 1; i <= 100; i++)
        SimulateAnneal();
    printf("%.lf", ans);
    return 0;
}