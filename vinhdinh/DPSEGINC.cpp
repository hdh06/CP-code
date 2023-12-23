#include <bits/stdc++.h>

using namespace std;

int const N = 6001;

typedef long long ll;

int main(){
	int n;
	cin >> n;

	ll arr[N];

	for (int i = 1; i <= n; i++) cin >> arr[i];

	int dp[N] = {};
	int p[N] = {};
	int maxn = 0;
	for (int i = 1; i <= n; i++){
		dp[i] = 1; p[i] = i;
		for (int j = i - 1; j >= 1; j--) if (arr[i] % arr[j] == 0){
			if (dp[j] + 1 > dp[i]){
				dp[i] = dp[j] + 1;
				p[i] = j;
			}
		}
		if (dp[maxn] < dp[i]){
			maxn = i;
		}
	}

	cout << dp[maxn] << endl;

	vector<int> ans;
	while(p[maxn] != maxn){
		ans.push_back(maxn);
		maxn = p[maxn];
	}

	reverse(ans.begin(), ans.end());

	cout << maxn << " ";
	for (auto i: ans) cout << i << " "; 

	return 0;
}