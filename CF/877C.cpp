#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin >> n;

	vector<int> ans;
	for (int i = 2; i <= n; i += 2) ans.push_back(i);
	for (int i = 1; i <= n; i += 2) ans.push_back(i);
	for (int i = 2; i <= n; i += 2) ans.push_back(i);

	cout << ans.size() << "\n";
	for (auto x: ans) cout << x << " ";
 	return 0;
}