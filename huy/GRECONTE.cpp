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
	int dem = 1;
	for (int i = 0; i < n; i++){
		//cout << arr[i] << " " << dem << endl;
		if (arr[i] >= dem){
			dem++;
		};
	}

	cout << dem - 1;
	return 0;
}