#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;

	vector<int> arr(n + 1, 0), f(n + 1, INT_MAX), p(n + 1);

	for (int i = 1; i <= n; i++) cin >> arr[i];	

	f[0] = INT_MIN;

	int maxn = 0;
	for (int i = 1; i <= n; i++){
		p[i] = lower_bound(f.begin(), f.end(), arr[i]) - f.begin();

		f[p[i]] = arr[i];
		maxn = max(maxn, p[i]);
	}	
	cout << maxn << endl;
	
	int pos = maxn;
	vector<int> ans;

	for (int i = n; i >= 1; i--){
		if (p[i] == pos){
			ans.push_back(i);
			pos--;
		}
	}

	reverse(ans.begin(), ans.end());

	for (auto x: ans) cout << x << " ";
}

/*
6
1 2 2 4 3 6
*/