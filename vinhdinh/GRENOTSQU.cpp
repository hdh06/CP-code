#include <bits/stdc++.h>

using namespace std;

int calc(int x){
	int can = sqrt(x);
	return min(x - can*can, (can + 1)*(can + 1) - x);
}

int main(){
	int n; cin >> n;
	vector<int> arr(n); 
	for (auto &x: arr) cin >> x;

	sort(arr.begin(), arr.end(), [](int a, int b){
		if (calc(a) == calc(b)) return a < b;
		return calc(a) < calc(b);
	});

	// for (auto x: arr) cout << x << " ";

	long long dem = 0;
	for (int i = 0; i < n / 2; i++)	dem += calc(arr[i]);
	for (int i = n / 2; i < n; i++) dem += (calc(arr[i]) == 0) + (arr[i] == 0);

	cout << dem;
	return 0;
}