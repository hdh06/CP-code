#include <bits/stdc++.h>

#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 1001
#endif

using namespace std;

typedef long long ll;

int const N = 3e5 + 1;
int const L = 30;
int const MOD = 1019972207;

template<typename T> T gcd(T a, T b) { return (b == 0? a : gcd(b, a % b)); }
template<typename T> T lcm(T a, T b) { return a / gcd(a, b) * b; }

namespace sub12{
	void solve(){
		int n; cin >> n;
		ll arr[N];
		for (int i = 1; i <= n; i++)
			cin >> arr[i];

		ll ans = 0;
		for (int i = 1; i <= n; i++){
			ll minn = LLONG_MAX, g = 0;
			for (int j = i; j <= n; j++){
				minn = min(minn, arr[j]);
				g = gcd(g, arr[j]);
				(ans += (minn % MOD) * (g % MOD) % MOD) %= MOD;
			}
		}
		cout << ans << "\n";
	}
}

namespace sub3{
	void solve(){
		int n; cin >> n;
		ll arr[N];
		for (int i = 1; i <= n; i++) cin >> arr[i];
		int l[N] = {}, r[N] = {};
		stack<int> st;
		for (int i = 1; i <= n; i++){
			while (!st.empty() && arr[st.top()] > arr[i]) st.pop();
			if (!st.empty()) l[i] = st.top() + 1;
			else l[i] = 1;
			st.push(i);
		}
		while (!st.empty()) st.pop();
		for (int i = n; i >= 1; i--){
			while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
			if (!st.empty()) r[i] = st.top() - 1;
			else r[i] = n;
			st.push(i);
		}
		ll ans = 0;
		for (int i = 1; i <= n; i++){
			// debug(l[i], r[i]);
			(ans += (arr[i] % MOD) * (arr[i] % MOD) % MOD * (i - l[i] + 1) % MOD * (r[i] - i + 1) % MOD) %= MOD;
		}
		cout << ans << "\n";
	}
}

#define file "sum-min-gcd"

int main(){
	ios_base::sync_with_stdio(0); // the
	cin.tie(nullptr);			  // magical
	cout.tie(nullptr);			  // lines
	freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);
	int SuB; cin >> SuB;
	if (SuB == 3) sub3::solve();
	else
		sub12::solve();
	
	return 0;
}