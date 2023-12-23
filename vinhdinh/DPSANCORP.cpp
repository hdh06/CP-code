#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef array<ll, 3> iii;

int const N = 5001;
int n;

iii arr[N];
ll dp[N], lend[N];
ll maxn;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	int t; cin >> t;
	while(t--){
		cin >> n;	

		for (int i = 1; i <= n; i++){
			ll a, b, c;
			cin >> a >> b >> c;
			arr[i] = {a, a + b, c};
			lend[i] = a + b;
		}

		sort(arr + 1, arr + n + 1, [](iii a, iii b){
			if (a[1] == b[1]) return a[0] < b[0];
			return a[1] < b[1];
		});

		sort(lend + 1, lend + n + 1);
		dp[0] = 0;
		maxn = 0;
		for (int i = 1; i <= n; i++){
			dp[i] = arr[i][2];
			int k = upper_bound(lend + 1, lend + i, arr[i][0]) - (lend + 1);
			for (int j = k - (k == i); j > 0; j--) if (arr[i][0] >= arr[j][1]){
				dp[i] = max(dp[i], dp[j] + arr[i][2]);
			}
			maxn = max(maxn, dp[i]);
		}
		cout << maxn << '\n';
	}
	return 0;
}