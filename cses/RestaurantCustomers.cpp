#include <bits/stdc++.h>

using namespace std;

int const N = 2*1e5 + 5;

int main(){
	int n;
	cin >> n;

	vector<pair<int, int> > arr;

	for (int i = 1; i <= n; i++){
		int a, b;
		cin >> a >> b;
		arr.push_back({a, 1});
		arr.push_back({b, -1});
	}

	sort(arr.begin(), arr.end());

	int dem = 0;
	int max_dem = 0;

	for (auto p: arr){
		dem += p.second;
		max_dem = max(max_dem, dem);
	}

	cout << max_dem << endl;
	return 0;
}