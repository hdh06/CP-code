#include <bits/stdc++.h>

#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 1000
#endif

using namespace std;
typedef long long ll;

int const N = 1e5 + 1;

int main(){
	ios_base::sync_with_stdio(0); // the
	cin.tie(nullptr);			  // magical
	cout.tie(nullptr);			  // lines
	int n; cin >> n;
	
	pair<ll, ll> p[N];
	for (int i = 1; i <= n; i++)
		cin >> p[i].first >> p[i].second;
	
	ll ans = (p[1].first - p[n].first) * (p[1].second + p[n].second);
	for (int i = 2; i <= n; i++)
		ans += (p[i].first - p[i - 1].first) * (p[i].second + p[i - 1].second);
	
	
	cout << setprecision(6) << fixed << abs(ans) * 0.5L;
	return 0;
}