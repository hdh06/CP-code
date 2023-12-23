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
	return x ^ ((1 << (n + 1)) - 1);
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);
	ll n; cin >> n;
	int arr[1000001];

	// cerr << c(n, log2(n));

	for (int i = n; i >= 0;){
		if (i == 0){
			arr[0] = 0;
			break;
		}
		int z = log2(i);
		for (int l = c(i, z), r = i; l < r; l++, r--)
			arr[l] = r, arr[r] = l;
		i = c(i, z) - 1;
	}

	cout << n * (n + 1) << "\n";
	for (int i = 0; i <= n; i++)
		cout << arr[i] << " ";
	return 0;
}//chua len ech bot, toi xai template ;-;