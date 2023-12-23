#include <bits/stdc++.h>

using namespace std;

typedef array<int, 3> iii;

iii vtc(iii a, iii b){
	return {b[0] - a[0], b[1] - a[1], b[2] - a[2]};
}

void norm(iii &x){
	int UCLN = gcd(x[0], gcd(x[1], x[2]));
	return {x[0] / UCLN, x[1] / UCLN, x[2] / UCLN};
}

int main(){
	int n; cin >> n;
	vector<iii> arr(n);
	for (auto &x: arr) cin >> x[0] >> x[1] >> x[2];

	int zero = 0, k = 0;

	for (int i = 0; i < n; i++){
		unordered_map<iii, int> m;
		for (int j = 0; j < n; j++) if (i != j){
			if (arr[i] == arr[j]) zero++;
			else{
				iii tmp = vtc(arr[i], arr[j]);
				if (tmp[2] <= 0) continue;
				norm(tmp);
				m[tmp]++;
			}
		}

		int ans = 0;

		for (int j = 0; j < n; j++) if (i != j){
			iii tmp = vtc(arr[i], arr[j]);
			ans = max(ans, m[tmp]);
		}

		k = max(k, ans;)
	}

	cout << zero + 1 + k;
	return 0;
}