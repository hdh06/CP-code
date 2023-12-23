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
#define file "fiel"

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

int maxK;

int const N = 1e5 + 1, K = 21;

ll dp[N][K];

int n;
string s;

int nnol[N];

int get(int &i){
	int ans = 0;
	while ('0' <= s[i] && s[i] <= '9'){
		ans = 10 * ans + (s[i] - '0');
		i++;
	}
	return ans;
}

void solve(){	
	cin >> s;
	
	n = 0;
	stack<int> st;
	for (int i = 0; i < s.size(); i++){
		if (s[i] == 'o' || s[i] == 'p' || s[i] == ',') continue;
		if (s[i] == '(')
			st.push(++n);
		else if (s[i] == ')'){
			int x = st.top(); st.pop();
			int y = st.top(); st.pop();
			int v = st.top();
			// v -> x, v -> y
			nnol[v] = nnol[x] + nnol[y] + 1;
			for (int i = 0; i <= nnol[v]; i++){
				dp[v][i] = 0;
				for (int j = 0; j <= i; j++){
					if (j < i) dp[v][i] = max(dp[v][i], dp[x][j] * dp[y][i - j - 1]);
					dp[v][i] = max(dp[v][i], dp[x][j] + dp[y][i - j]);
				}
			}
		}else{
			st.push(++n);
			dp[n][0] = get(i);
			nnol[n] = 0;
			i--;
		}
	}
	cout << dp[1][min(maxK, n)] << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);
	int t;
	if (SINGLE_TEST) t = 1;
	else cin >> t >> maxK;
	while (t--) solve();
	return 0;
}//khong phai _HDH, _HDH ko xai template!!!