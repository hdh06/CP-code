#include <bits/stdc++.h>

#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 1001
#endif

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
typedef vector<int> vi;
typedef vector<ll> vl;

bool const SINGLE_TEST = 1;

int const N = 2e5 + 1;

ii dp[N];

void optimize(ii &ans, ii &x){
	if (x.st < ans.st){
		ans = x; return;
	}
	if (x.st == ans.st && ans.nd < x.nd){
		ans = x; return;
	}
}

ii calc(int p){
	if (p == 0) return {0, 0};
	if (dp[p].st != -1) return dp[p];
	int sum = 0;
	ii ans = {INT_MAX, 0};
	for (int i = 1; sum + i <= p;){
		sum += i++;
		ii z = calc(p - sum);
		z.nd += i * z.st, z.st += i;
		optimize(ans, z);
	}
	return dp[p] = ans;
}

void solve(){
	int p; cin >> p;
	
	memset(dp, -1, sizeof dp);
	
	cout << calc(p).st << " " << calc(p).nd << "\n";
}

/*
	int ans1 = 0; ll ans2 = 0;
	while (p > 0){
		int sum = 0, i = 1;
		while (sum + i <= p) sum += i++;
		ans2 += ans1 * i, ans1 += i;
		p -= sum;
		cout << ans1 << " " << ans2;
	}
*/

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);
	int t;
	if (SINGLE_TEST) t = 1;
	else cin >> t;
	while (t--) solve();
	return 0;
}//it's coding time!