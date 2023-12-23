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
#define file "SIMPLE"

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

int const N = 1e5 + 1;

int n;
string s;

int psum[N][26];

int cntDval(int l, int r){
	int cnt = 0;
	for (int i = 0; i < 26; i++) if (psum[r][i] - psum[l - 1][i]) cnt++;
	return cnt;
}

namespace sub2{
	void solve(){
		int d = 1, l = 1, L = 1, R = 1;
		for (int i = 1; i <= n; i++){
			for (int j = i + 1; j <= n; j++){
				int a = cntDval(i, j), b = j - i + 1;
				debug(a, b, i, j);
				if (d * b > a * l) d = a, l = b, L = i, R = j;
			}
		}
		cout << L << " " << R << "\n";
	}
}

namespace sub5{
	bool maximize(pll &x, pll v){
		if (x.st * v.nd > x.nd * v.st){
			x = v;
			return true;
		}
		return false;
	}

	void solve(){
		pll ans = {1, 1}, pos = {1, 1};
		for (int i = 1; i <= n; i++){
			int j = i;
			for (int d = 1; d <= 26 && j; d++){
				for (int k = log2(j); k >= 0; k--)
					if (cntDval(max(1, j - (1 << k)), i) <= d)
						j = max(1, j - (1 << k));

				if (maximize(ans, mp(d, i - j + 1))) pos = mp(j, i);
				j--;
			}
		}
		cout << pos.st << " " << pos.nd << "\n";
	}
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	freopen(file".inp", "r", stdin);
	freopen(file".out", "w", stdout);

	cin >> n;
	cin >> s;

	s = ' ' + s;

	for (int i = 1; i <= n; i++)
		psum[i][s[i] - 'a']++;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < 26; j++)
			psum[i][j] += psum[i - 1][j];

	// if (n <= 2000)
	// 	sub2::solve();
	// else
		sub5::solve();
	return 0;
}//khong phai _HDH, _HDH ko xai template!!!