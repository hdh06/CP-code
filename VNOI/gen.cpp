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
#define file "EZTASK"

typedef long long ll;
typedef pair<int, int> pii;
typedef array<int, 3> iii;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l, ll r){return uniform_int_distribution<ll>(l, r)(rd);}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	freopen(file".inp", "w", stdout);
	// freopen(file".out", "w", stdout);
	int n = rand(1, 10);
	cout << n << "\n";
	for (int i = 1; i <= n; i++)
		cout << rand(-100, 100) << " ";
	return 0;
}//chua len ech bot, toi xai template ;-;