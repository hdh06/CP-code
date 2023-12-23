#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n, a = 19999, b = 19998;
    cin >> n;
    while (n >= a)
    {
        long long temp = b*(n/a);
        n %= a;
        n += temp;
    }
    return 0;
}
    