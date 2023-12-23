#include <bits/stdc++.h>

using namespace std;

typedef array<int, 2> ii;

int main(){
	int n;	

	cin >> n;

	vector<ii> arr(n);

	for (auto &x: arr) cin >> x[1] >> x[0];

	sort(arr.begin(), arr.end(), greater<ii>());
	
	long long turn = 1, tong = 0;
	for (auto x: arr){
		if (turn > 0){
			tong += x[1];
			turn += x[0] - 1;
		} 
	}

	cout << tong;
	return 0;
}