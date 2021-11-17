/*
翻硬币
url: https://www.acwing.com/problem/content/1210/
*/
#include <cstdio>
#include <cstring>
#include <iostream>
char a[105], b[105];
int ans;
using namespace std;
int main()
{
    scanf("%s", a);
    scanf("%s", b);
    for (int i = 0; i < strlen(a); i++)
    {
        if (a[i] != b[i])
        {
            if (b[i + 1] == '*')
                b[i + 1] = 'o';
            else
                b[i + 1] = '*';
            ans++;
        }
    }
    cout << ans;
}