#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;	
	cin >> n;

	vector<int> arr(n);

	for (auto &x: arr) cin >> x;

	sort(arr.begin(), arr.end());

	arr.push_back(0);

	int dem = 1;
	for (int i = 1; i <= n; i++){
		if (arr[i] != arr[i - 1]){
			if (dem & 1){
				cout << arr[i - 1];
				return 0;
			}
			dem = 1;
		}
		else dem++;
	}
	return 0;
}