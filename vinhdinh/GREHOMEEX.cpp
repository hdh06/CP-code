#include <bits/stdc++.h>

using namespace std;

int cnt[10];

int main(){
	int n; cin >> n;
	
	vector<int> ans;
	for (int i = 1; i <= n; i++){
		int x; cin >> x;
		if (x % 3 == 0)
			ans.push_back(x);
		else cnt[x]++;
	}
	
	for (int d = 9; d >= 0; d--) if (d % 3 != 0){
		for (int i = 1; i <= cnt[d] / 3 * 3; i++)
			ans.push_back(d);
			
		cnt[d] = cnt[d] % 3;
		int pos = -1;
		for (int i = d - 1; i >= 0; i--) if (i % 3 + d % 3 == 3)
			if (cnt[d] <= cnt[i] % 3){
				pos = i;
				break;
			}
		if (pos == -1)
		else{
			ans.push_back()
		}
	}
	
	sort(ans.begin(), ans.end(), greater<int>());
	if (ans.size() == 0 || ans.back() != 0)
		cout << "-1\n";
	else for (auto x: ans) cout << x;
	return 0;
}