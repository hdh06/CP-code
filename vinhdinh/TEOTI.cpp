#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin >> n; 
	vector<int> arr(n + 1);

	for (int i = 1; i <= n; i++) cin >> arr[i];

	sort(arr.begin() + 1, arr.end());

	cout << arr[n / 2 + (n % 2 != 0)];

	return 0;
}