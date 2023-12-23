#include <bits/stdc++.h>

using namespace std;
typedef long long var;
const var maxn = 2e5;
    var a[maxn];
int main()
{
    ios_base::sync_with_stdio(0);
    var n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a+1, a+n+1);
    if(a[1] > 1)
    a[1]--;
    var MAX = a[1];
    for(int i = 2; i <= n; i++){
        if(a[i] > MAX+1)
            a[i]--;
        else
        if(a[i] == MAX)
            a[i]++;
        MAX = max(MAX, a[i]);
    }
    sort(a+1, a+n+1);
    var dem = 0;
    for(int i = 1; i <= n; i++)
        if(a[i] != a[i-1])
            dem++;
    cout << dem;
    return 0;
}
    