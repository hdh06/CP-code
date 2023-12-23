#include <bits/stdc++.h>

using namespace std;

int const N = 1e6 + 1;
int const MOD = 1000000123;

typedef long long ll;

ll s;

int emrua(int n, int cnt1, int cnt2, bool is){
	if (n == s) return (!is && cnt1 == 1 && cnt2 == 0);

	int ans = 0;
	for (int d = 0; d <= 9; d++)
		(ans += emrua(n + 1, (cnt1 + (d & 1)) % 2, (cnt2 + !is * (d % 2 == 0)) % 2, is & (d == 0))) %= MOD;
	return ans;
}
void solve(){
	cout << emrua(0, 0, 0, 1) << "\n";
}

int main(){
	while (cin >> s) solve();
	return 0;
}