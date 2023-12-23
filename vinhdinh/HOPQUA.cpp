#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int const N = 2e6 + 1;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	int n, d; cin >> n >> d;	

	int fre[N] = {}, t;
	for (int i = 1; i <= n; i++){
		cin >> t;
		fre[t]++;
	}

	int fsum[N] = {};
	for (int i = 1; i < N; i++)
		fsum[i] = fsum[i - 1] + fre[i];
	

	ll tong = 0, sum = 0;

	for (int i = 1; i < N; i++){
		sum = fsum[i - 1] - fsum[max(0, i - d - 1)];
		tong += 1LL*fre[i]*(sum*(sum - 1)/2);
		tong += 1LL*(fre[i] - 1)*(fre[i] - 2)*fre[i]/6;
		tong += 1LL*(fre[i]*(fre[i]-1)/2)*sum;
		// if (fre[i] != 0) cout << sum << " ";
	}

	cout << tong;
	return 0;
}