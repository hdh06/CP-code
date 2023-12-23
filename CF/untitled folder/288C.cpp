#include <bits/stdc++.h>

using namespace std;
#define all(x) x.begin(), x.end()
#define st first
#define nd second
#define lb lower_bound
#define ub upper_bound
#define sz(x) (int)x.size()
#define pb push_back
#define ob pop_back
#define file "TEMPLATE"

typedef long long ll;
typedef pair<int, int> pii;
typedef array<int, 3> iii;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l, ll r){return uniform_int_distribution<ll>(l, r)(rd);}

int c(int x, int n){
	return x ^ ((1 << n) - 1);
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);
	ll n; cin >> n;
	cout << n * (n + 1) / 2 << "\n";
	int arr[1000001];

	while (n >= 0){
		int z = log2(n);
		for (int l = c(n, z), r = n; l < r; l++, r--)
			arr[l] = r, arr[r] = l;
		n = c(n, z) - 1;
	}

	for (int i = 0; i <= n; i++)
		cout << arr[i] << " ";
	return 0;
}//chua len ech bot, toi xai template ;-;