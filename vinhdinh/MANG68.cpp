#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, m;
	cin >> n >> m;

	vector<int> arr(n *m);

	for (int i = 0; i < n*m; i++) cin >> arr[i];

	sort(arr.begin(), arr.end());

	for (int i = 1; i <= n * m; i++) cout << arr[i - 1] << " \n"[i % m == 0]; 
	return 0;
}