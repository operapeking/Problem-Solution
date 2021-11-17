/*
去掉多余的空格
url: https://www.acwing.com/problem/content/768/
*/
#include <algorithm>
#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
string a;
bool b;
int main()
{
    int i = 0;
    while (cin >> a)
    {
        if (i != 0)
            cout << " ";
        i++;
        for (int i = 0; i < a.size(); i++)
        {
            cout << a[i];
        }
    }

    return 0;
}