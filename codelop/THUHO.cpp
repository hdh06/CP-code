#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(),x.end()
#define stfu system("sudo poweroff")
#define ll long long
#define file "TEST"

mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rd); }

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        // freopen(file".inp", "r", stdin), freopen(file".out", "w", stdout);
    int n, m;
    cin >> n >> m;
    int tong = 0;
    int k = m;
    for (int i = 1; i <= n; i++){
        int a;
        cin >> a;
        int temp = a - k;
        a = max(0, temp);
        int prek = k;
        k = abs(min(0, temp));
        tong += prek - k;
        temp = a - m;
        a = max(0,temp);
        k = abs(min(0, temp));
        tong += m - min(m,k);
    }
    cout << tong;
//    cerr << "\nTime executed: " << (ldb)clock() / (ldb)CLOCKS_PER_SEC << " sec";
    return 0;
}