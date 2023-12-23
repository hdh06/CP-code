#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 1;

int n;
int arr[N];

pair<int, int> dp[N];
#define st first
#define nd second

int p[N];

int main(){
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	
	pair<int, int> ans = {0, 0};
	for (int i = 1; i <= n; i++){
		pair<int, int> k = {0, 0};
		for (int u = 1; 1LL * u * u <= arr[i]; u++) if (arr[i] % u == 0){
			k = max(k, dp[u]);
			k = max(k, dp[arr[i] / u]);
		}
		p[i] = k.nd;
		k.st++, k.nd = i;
		dp[arr[i]] = max(dp[arr[i]], k);
		ans = max(ans, k);
	}
	
	cout << ans.st << "\n";
	vector<int> z;
	while (ans.nd){
		z.push_back(ans.nd);
		ans.nd = p[ans.nd];
	}
	reverse(z.begin(), z.end());
	for (auto x: z) cout << x << " ";
	return 0;
}