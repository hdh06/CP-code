#include <bits/stdc++.h>

using namespace std;
#define all(x) x.begin(), x.end()
#define st first
#define nd second
#define lb lower_bound
#define ub upper_bound
#define sz(x) (int)x.size()
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define file "TEMPLATE"

typedef long long ll;
typedef pair<int, int> ii;
typedef array<int, 3> iii;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rd);}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	// freopen(file".inp", "r", stdin);
	freopen("f.inp", "w", stdout);
	int n = rand(5, 5), q = rand(5, 5);
	cout << n << " " << q << "\n";
	for (int i = 1; i <= n; i++)
		cout << rand(-5, 5) << " \n"[i == n];
	
	for (int i = 1; i <= q; i++){
		int t = rand(0, 2);
		int l = rand(1, n), r = rand(1, n);
		while (l > r) l = rand(1, n), r = rand(1, n);
		cout << t << " ";
		if (t == 2){
			cout << l << " " << r << "\n";
		}
		if (t == 1){
			cout << l << " " << r << " " << rand(-5, 5) << "\n";
		}
		if (t == 0){
			cout << l << " " << r << " " << rand(-5, 5) << "\n";
		}
	}
	return 0;
}//chua len ech bot, toi xai template ;-;