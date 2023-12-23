#include <bits/stdc++.h>

using namespace std;
typedef long long var;
const var maxn = 1e5+5;
var a[maxn], b[maxn];
int main()
{
    ios_base::sync_with_stdio(0);
    var n, k, sum = 0;
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i-1] - (a[i-1] + b[i-1])%k >= 0)
            b[i] = (a[i-1] + b[i-1]) % k, a[i-1] -= (a[i-1] + b[i-1])%k;
        sum += ((a[i-1]+b[i-1])) / k + ((a[i-1] + b[i-1]) % k != 0);
    }
    sum += ((a[n]+b[n])) / k + ((a[n] + b[n]) % k != 0);
    cout << sum;
    // for(int i = 1; i <= n; i++)
    //     cout << a[i]+b[i] << " ";
    return 0;
}
    