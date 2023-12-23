#include <bits/stdc++.h>

#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 1606
#endif

using namespace std;
#define all(x) x.begin(), x.end()
#define mp make_pair
#define st first
#define nd second
#define lb lower_bound
#define ub upper_bound
#define sz(x) (int)x.size()
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define file "obilazak"

typedef long long ll;
typedef unsigned long long ull;
typedef long double ldb;
typedef string str;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef array<int, 3> iii;
typedef array<ll, 3> lll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ii> vii;
typedef vector<pll> vll;
typedef vector<bool> vb;
typedef vector<ldb> vd;

int const K = 11;

int p[1 << K];

vi ans[K];

void calc(int l, int r, int h){
	if (r < l) return;
	int mid = (l + r) >> 1;
	ans[h].pb(p[mid]);
	calc(l, mid - 1, h + 1);
	calc(mid + 1, r, h + 1);
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	#ifdef ONLINE_JUDGE
		freopen(file".inp", "r", stdin);
		freopen(file".out", "w", stdout);
	#endif

	int k; cin >> k;
	for (int i = 1; i < (1 << k); i++)
		cin >> p[i];

	calc(1, (1 << k) - 1, 0);
	for (int i = 0; i < K; i++)
		for (int j = 0; j < ans[i].size(); j++)
			cout << ans[i][j] << " \n"[j == ans[i].size() - 1];
	return 0;
}//khong phai _HDH, _HDH ko xai template!!!