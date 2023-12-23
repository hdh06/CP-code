#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); 
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++){
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	for (int i = 2; i < n; i++){
		if (arr[i - 2] + arr[i - 1] > arr[i]){
			cout << "YES";
			return 0;
		}
	}

	cout << "NO";
	return 0;
}