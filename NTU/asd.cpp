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
    int n, a, b;
    cin >> n >> a >> b;
    if (n % __gcd(a,b) != 0){
        cout << -1;
        return 0;
    }
    // if (a < b) swap(a,b);
    for (int i = 0; i * b <= n;i++){
        if((n - b*i) % a == 0){
            cout << i + (n - b*i)/a;
            return 0;
        }
    }
    cout << -1;
//    cerr << "\nTime executed: " << (ldb)clock() / (ldb)CLOCKS_PER_SEC << " sec";
    return 0;
}
    