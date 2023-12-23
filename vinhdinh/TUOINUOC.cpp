#include <bits/stdc++.h>
typedef long long ll;

//¯\_(ツ)_/¯ Huy

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int i;
    cin >> i;
    int maxn = i;
    for (int y = 1; y < k - 1; y++)
    {
        int j;
        cin >> j;
        maxn = max(maxn, (j - i)/2 + 1);
        i = j;
    }
    cin >> i;
    maxn = max(maxn, n - i + 1);
    cout << maxn;
    return 0;
}
    