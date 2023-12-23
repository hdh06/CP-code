#include <bits/stdc++.h>
#define MAX 100000
typedef long long ll;

using namespace std;

int main() {
    ll n, arr[MAX], chan = 0, le = 0;
    cin >> n;
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] % 2 == 0) chan ++;
        else le++;
    }
    if (chan == le) cout << 0;
    else if (chan > le)
    {
        sort(arr,arr+n); ll tong = 0;
        for (ll i = 0,dem = 0; dem < chan - le - 1; i++) if (arr[i] % 2 == 0)
        {
            tong += arr[i];
            dem ++;
        }
        cout << tong;
    }
    else
    {
        sort(arr,arr+n); ll tong = 0;
        for (ll i = 0,dem = 0; dem < le - chan - 1; i++) if (arr[i] % 2 != 0)
        {
            tong += arr[i];
            dem ++;
        }
        cout << tong;
    }
    return 0;
}
    