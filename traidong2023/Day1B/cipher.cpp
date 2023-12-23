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
#define file "cipher"

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

bool const SINGLE_TEST = 0;

int const N = 51;

int n;
string s;
int dp[N][26][26];

string f;


int trace[N][26][26];

int calc(int i, int a, int b){
	// debug(i, a, b);
	if (i == n){
		// debug(f);.
		return 1;
	}
	
	int &ans = dp[i][a][b];
	if (ans != -1) return ans;
	ans = 0;
	if (i == n - 2){
		if ( (a + s[i + 1] - 'A') % 26 == s[i - 1] - 'A'){
			// f.pb(s[i + 1]);
			if (calc(i + 1, b, s[i + 1] - 'A')){
				trace[i][a][b] = s[i + 1] - 'A';
				ans = min(2, ans + calc(i + 1, b, s[i + 1] - 'A'));
			}
			// f.pob();
		}
	}else{
		for (int j = 0; j < 26; j++) if ((a + j) % 26 == s[i - 1] - 'A'){
			if (calc(i + 1, b, j)){
				trace[i][a][b] = j;
				// f.pb(j + 'A');
				ans = min(2, ans + calc(i + 1, b, j));
				// f.pob();
			}
		}
	}
			
	return ans;
}

void solve(){
	cin >> s;
	n = s.size();
	int cnt = 0;
	
	memset(dp, -1, sizeof dp);
	
	int a = 0, b = 0;
	for (int i = 0; i < 26; i++){
		if (calc(2, i, s[0] - 'A')) a = i, b = s[0] - 'A';
		cnt = min(2, cnt + calc(2, i, s[0] - 'A'));
	}
	
	if (cnt == 1){
		cout << (char)(a + 'A') << (char)(b + 'A');
		for (int i = 2; i < n; i++){
			int c = trace[i][a][b];
			a = b;
			b = c;
			cout << (char)(c + 'A');
		}
	}else cout << "AMBIGUOUS";
	cout << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	freopen(file".inp", "r", stdin);
	freopen(file".out", "w", stdout);
	int t;
	if (SINGLE_TEST) t = 1;
	else cin >> t;
	while (t--) solve();
	return 0;
}//khong phai _HDH, _HDH ko xai template!!!