#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> arr(n + 1);
	for (int i = 0; i < n; i++){
		cin >> arr[i];
	}
	if (n <= 2){
		cout << max(arr[0], arr[1]);
		return 0;
	}
	sort(arr.begin(), arr.end() - 1);
	int tong = 0;
	int i = n - 1;
	for (; i > 2; i-=2){
		tong += min(arr[1] + arr[0] + arr[i] + arr[1], arr[i] + arr[0] + arr[i - 1] + arr[0]);
		// cout << tong << "+=" << arr[1] <<  "+" <<  arr[0] << "+" << arr[i] << "+" << arr[1] << endl;
	}
	if (i == 2) tong += arr[2] + arr[0];
	tong += arr[1];
	cout << tong;
	return 0;
}