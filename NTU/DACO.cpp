#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin >> n;
	
	vector<int> arr(n + 1);
	for (int i = 1; i <= n; i++) cin >> arr[i];
	
	vector<int> dp(n + 1);
	for (int i = 1; i <= n; i++){
		dp[i] = 1;
		for (int j = 1; j < i; j++)	if (arr[j] < arr[i])
			dp[i] = max(dp[i], dp[j] + 1);
	}
	
	int pos = 0;
	for (int i = 1; i <= n; i++)
		if (dp[i] > dp[pos]) pos = i;
		
	vector<int> ans;
	while (1){
		ans.push_back(arr[pos]);
		bool y = 0;
		for (int j = 1; j < pos; j++) if (arr[pos] > arr[j] && dp[pos] == dp[j] + 1)
			{pos = j, y = 1; break;}		
		if (!y) break;
	}
	
	reverse(ans.begin(), ans.end());
	
	cout << ans.size() << "\n";
	for (auto x: ans) cout << x << " ";
	return 0;
}