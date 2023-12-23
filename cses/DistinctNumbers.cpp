#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++){
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	int dem = 1, cur = arr[0];
	for (int i = 1; i < n; i++){
		if (arr[i] != cur){
			cur = arr[i];
			dem++;
		}
	}
	cout << dem;
	return 0;
}