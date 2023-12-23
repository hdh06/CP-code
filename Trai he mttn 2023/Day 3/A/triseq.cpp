#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin >> n;

	vector<array<int, 2> > arr(n);
	n = 0;
	for (auto &x: arr){
		cin >> x[0];
		x[1] = ++n;
	}

	sort(arr.begin(), arr.end());

	int L = 0, R = -1;

	int l = 0, r = -1;

	for (auto x: arr){
		r++;
		while (r - l + 1 >= 3 && arr[l][0] + arr[l + 1][0] <= x[0]) l++;
		if (r - l + 1 > R - L + 1)
			L = l, R = r;
	}

	cout << R - L + 1 << "\n";
	vector<int> out;
	for (int i = L; i <= R; i++) out.push_back(arr[i][1]);
	sort(out.begin(), out.end());
	for (auto x: out) cout << x << " ";
	return 0;
}