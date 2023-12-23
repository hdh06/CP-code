#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;

	vector<int> arr(n);

	for (auto &x: arr) cin >> x;

	int t = 1;
	for (int i = 0; i < n; i++){
		if (arr[i] == t) t++;
	}

	cout << n - t + 1;
	return 0;
}