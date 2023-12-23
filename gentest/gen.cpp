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
typedef vector<int> vi;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l, ll r){return uniform_int_distribution<ll>(l, r)(rd);}

int const N = 1e5 + 1;

vi g[N];

string f;

void rebuild(int v){
	for (auto u: g[v]) rebuild(u);
	if (g[v].size() == 0) f.pb('a');
	else f.pb(g[v].size() + '0');
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	// freopen(file".inp", "r", stdin);
	freopen("f.inp", "w", stdout);
	int n = rand(2, 10);
	
	for (int i = 2; i <= n; i++){
		int p = rand(1, i - 1);
		g[p].pb(i);
	}

	rebuild(1);

	cout << f;
	return 0;
}