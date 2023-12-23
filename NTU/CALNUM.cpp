#include <bits/stdc++.h>

using namespace std;

template<typename T> T gcd(T a, T b) { return (b == 0? a : gcd(b, a % b)); }
template<typename T> T lcm(T a, T b) { return a / gcd(a, b) * b; }

typedef long long ll;

string L, R;

ll dp[19][19 * 9][19 * 81];

ll calc(int i, int sum, int sump){
	if (i == 0) return gcd(sum , sump) == 1;
	
	ll &ans = dp[i][sum][sump];
	if (ans != -1) return ans;
	ans = 0;
	for (int d = 0; d <= 9; d++)
		ans += calc(i - 1, sum + d, sump + d * d);
	
	return ans;
}

ll calc(string x){
	int sum = 0, sum_p = 0;
	ll ans = 0;
	for (int i = 0; i < x.size(); i++){
		for (int d = 0; d < x[i] - '0'; d++)
			ans += calc(x.size() - i - 1, sum + d, sum_p + d * d);
		sum += x[i] - '0';
		sum_p += (x[i] - '0') * (x[i] - '0');
	}
	return ans;
}

void solve(){
	cin >> L >> R;
	
	R = '0' + R;
	int i = R.size() - 1;
	while (R[i] == '9') R[i] = '0', i--;
	R[i]++;
	if (R[0] == '0') R.erase(0, 1);   
	
	cout << max(0LL, calc(R) - calc(L)) << "\n";
}

int main(){
	memset(dp, -1, sizeof dp);
	int t; cin >> t;
	while (t--) solve();
	return 0;
}