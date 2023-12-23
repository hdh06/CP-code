#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(),x.end()
#define stfu system("sudo poweroff")
#define ll long long
#define file "TEST"

mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rd); }

// ¯\_(ツ)_/¯ Huy

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        // freopen(file".inp", "r", stdin), freopen(file".out", "w", stdout);
    int a, b;
    cin >> a >> b;
    int dem = 0;
    queue<pair<int, int>> myque;
    while ((a >= 2 || b >= 2) && (a != 0 && b != 0)){
        if (a > b) {
            dem ++;
            a -= 2;
            b -= 1;
            myque.push({2,1});
        }
        else{
            dem ++;
            a -= 1;
            b -= 2;
            myque.push({1,2});
        }
    }
    cout << dem << endl;
    while (!myque.empty()){
        pair<int, int> kq = myque.front();
        myque.pop();
        cout << kq.first << " " << kq.second << endl;
    }
//    cerr << "\nTime executed: " << (ldb)clock() / (ldb)CLOCKS_PER_SEC << " sec";
    return 0;
}
    