#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll const INF = -1e13;
int const N = 1001;

ll dp[N] = {}; bool p[N][N] = {};
int n, m;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> m;

	for (int i = 1; i <= n; i++) dp[i] = INF;

	for (int i = 1; i <= n; i++){
		dp[0] = (i == 1? 0: INF);
		for (int j = 1; j <= m; j++){
			ll up = dp[j];
			ll left = dp[j - 1];

			cin >> dp[j];

			if (up + dp[j] > left + dp[j]){
				dp[j] += up;
				p[i][j] = 1;
			}
			else{
				dp[j] += left;
				p[i][j] = 0;
			}
		}
	}

	cout << dp[m] << "\n" << m + n - 1 << "\n";

	vector<int> mlist;
	for (int i = n, j = m; j > 0 && i > 0;){
		mlist.push_back(i*10000 + j);
		if (p[i][j]) i--;
		else j--;
	}

	reverse(mlist.begin(), mlist.end());

	for (auto x: mlist) cout << x / 10000 << " " << x % 10000 << "\n";
	return 0;
}