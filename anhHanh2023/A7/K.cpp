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
#define file "puzzles"

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


int const N = 7e5 + 1;

int n;
string s[N];
int maxx[26][26];
int dp[N][26];

void maximize(int &x, int v){
	if (x == -1 || x < v) x = v;
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	#ifdef ONLINE_JUDGE
		freopen(file".inp", "r", stdin);
		freopen(file".out", "w", stdout);
	#endif

	cin >> n;
	
	for (int i = 1; i <= n; i++)
		cin >> s[i];
	
	for (int i = 1; i <= n; i++){
		int d = s[i].front() - 'a';
		dp[i][d] = s[i].size();
		for (int c = 0; c < 26; c++) if (maxx[c][d] > 0)
			maximize(dp[i][c], maxx[c][d] + s[i].size());
		for (int c = 0; c < 26; c++)
			maximize(maxx[c][s[i].back() - 'a'], dp[i][c]);
	
		// debug(maxx[s[i][0] - 'a'] + s[i].size());
	}
	
	int ans = 0;
	for (int i = 1; i <= n; i++)
		for (int c = 0; c < 26; c++)
			if (dp[i][c] > 0 && s[i].back() == c + 'a')
				maximize(ans, dp[i][c]);
	
	cout << ans << "\n";
	return 0;
}//khong phai _HDH, _HDH ko xai template!!!
