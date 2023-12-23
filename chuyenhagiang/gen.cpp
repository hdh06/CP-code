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

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	// freopen(file".inp", "r", stdin);
	freopen("Chess.inp", "w", stdout);
	int n = 5;
	cout << n << "\n";
	for (int i = 1; i <= n; i++)
		cout << rand(1, 100) << " " << rand(1, 100) << "\n";
	return 0;
}//chua len ech bot, toi xai template ;-;