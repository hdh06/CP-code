#include <bits/stdc++.h>

using namespace std;

int main(){
	vector<array<int, 3> > w;
	int a, b;
	cin >> a;
	int i = 1;
	while(a != 0){
		cin >> b;
		w.push_back({a, b, i});
		i ++;
		cin >> a;
	}

	sort(w.begin(), w.end());

	int n = w.size();

	vector<int> dp(n), p(n); int maxn = 0, maxp = 0;
	for (int i = 0; i < n; i++){
		dp[i] = 1; p[i] = i;
		for (int j = i - 1; j >= 0; j--) if (w[i][0] > w[j][0] && w[j][1] > w[i][1]){
			if (dp[i] < dp[j] + 1){
				dp[i] = dp[j] + 1;
				p[i] = j;
			}
		}
		if (maxn < dp[i]){
			maxn = dp[i];
			maxp = i;
		}
	}

	cout << maxn << endl;
	vector<int> ans;
	while(p[maxp] != maxp){
		ans.push_back(maxp);
		maxp = p[maxp];
	}

	ans.push_back(maxp);

	reverse(ans.begin(), ans.end());

	for (auto x: ans) cout << w[x][2] << " ";
	return 0;
}