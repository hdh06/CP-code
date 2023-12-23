#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;

	vector<int> arr(n);	

	for (auto &x: arr) cin >> x;

	sort(arr.begin(), arr.end());
	
	long long sum = 0; int dem = 0;
	for (auto x: arr){
		if (x >= sum) dem++, sum += x;
	}

	cout << dem;
	return 0;
}