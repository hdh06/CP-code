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
#define file "makelist"

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

int const N = 51, K = 1501;
int const MOD = 1e9 + 7;

int n, k;
string arr[N][K];

namespace sub12{
	bool isSubstr(string &a, string &b){
		bool fl = 1;
		for (int i = 0; i < b.size() - 1; i++) if (b[i] != a[i]) fl = 0;
		if (fl) return true;
		fl = 1;
		for (int i = 1; i < b.size(); i++) if (b[i] != a[i - 1]) fl = 0;
		return fl;
	}
	int dp[N][K];
	int calc(int i, int pre){
		if (i == n + 1) return 1;

		int &ans = dp[i][pre];
		if (ans != -1) return ans;
		ans = 0;
		for (int j = 1; j <= k; j++) if (pre == 0 || isSubstr(arr[i - 1][pre], arr[i][j]))
			(ans += calc(i + 1, j)) %= MOD;
		return ans;
	}

	void solve(){
		memset(dp, -1, sizeof dp);
		cout << calc(1, 0) << "\n";
	}
}

namespace sub3{
	int dp[N][K];
	struct node{
		node* trie[26];
		int ans;
	};

	void insert(node* root, int i, int j){
		node* v = root;
		for (auto x: arr[i][j]){
			if (!v -> trie[x - 'a'])
				v -> trie[x - 'a'] = new node;
			v = v -> trie[x - 'a']; 
		}
		(v -> ans += dp[i][j]) %= MOD;
	}
	int find(node* root, string &s){
		node* v = root;
		int ans = 0;
		for (int i = 0; i < s.size() - 1; i++){
			if (!v -> trie[s[i] - 'a'])
				break;
			
			v = v -> trie[s[i] - 'a'];
		}
		(ans += v -> ans) %= MOD;
		int tmp = v -> ans;
		node* atmp = v;
		v -> ans = 0;
		v = root;
		for (int i = 1; i < s.size(); i++){
			if (!v -> trie[s[i] - 'a'])
				break;
			v = v -> trie[s[i] - 'a'];
		}
		(ans += v -> ans) %= MOD;
		atmp -> ans = tmp;
		return ans;
	}



	void solve(){
		for (int i = 1; i <= k; i++) dp[1][i] = 1;
		for (int i = 1; i <= n - 1; i++){
			node* tree = new node;
			for (int j = 1; j <= k; j++)
				insert(tree, i, j);
			
			for (int j = 1; j <= k; j++)
				dp[i + 1][j] = find(tree, arr[i + 1][j]);
		}

		int ans = 0;
		for (int i = 1; i <= k; i++) (ans += dp[n][i]) %= MOD;
		
		cout << ans << "\n";

		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= k; j++)
				cerr << dp[i][j] << " \n"[j == k];
	}
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	freopen(file".inp", "r", stdin);
	freopen(file".out", "w", stdout);

	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= k; j++)
			cin >> arr[i][j];

	if (n <= 50 && k <= 100)
		sub12::solve();
	else
		sub3::solve();
	return 0;
}//khong phai _HDH, _HDH ko xai template!!!