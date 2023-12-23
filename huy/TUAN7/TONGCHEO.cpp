#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> arr(2*n - 1);
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			int temp;
			cin >> temp;
			arr[i + j] += temp;
		}
	}

	cout << *max_element(arr.begin(),arr.end()) << endl;
	return 0;
}