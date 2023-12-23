#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;

	vector<int> arr(n + 1, 0);

	for (int i = 0; i < n; i++) cin >> arr[i];

	set<int> myset;

	int maxn = 0;

	int L = 0;

	myset.insert(arr[0]);

	for (int i = 1; i < n; i++){
		maxn = max(maxn, (int)myset.size());
		if (myset.find(arr[i]) != myset.end()){
			while (arr[L] != arr[i]) myset.erase(arr[L++]);
			myset.erase(arr[L++]);
		}
		myset.insert(arr[i]);
		// for (auto x: myset) cout << x << " "; cout << endl;
	}

	maxn = max(maxn, (int)myset.size());
	
	cout << maxn;
	return 0;
}