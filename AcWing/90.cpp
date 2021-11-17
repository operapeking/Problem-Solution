/*
64位整数乘法
url: https://www.acwing.com/problem/content/92/
*/
#include <cstdio>
typedef unsigned long long ULL;
using namespace std;
ULL mul(ULL a, ULL b, ULL p)
{
    ULL ans = 0;
    while (b)
    {
        if (b & 1)
            ans = (ans + a) % p;
        a = (a << 1) % p;
        b >>= 1;
    }
    return ans;
}
int main()
{
    ULL a, b, p;
    scanf("%llu%llu%llu", &a, &b, &p);
    printf("%llu", mul(a, b, p));
    return 0;
}