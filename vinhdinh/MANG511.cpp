#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; 
	cin >> n; 

	vector<double> arr(n);
	for (int i = 0; i < n; i++){
		cin >> arr[i];
	}

	int dem = 0;
	if (arr[0] < arr[1]) dem++;
	if (arr[n - 1] < arr[n - 2]) dem++;

	for (int i = 1; i <= n - 2; i++){
		if (arr[i] < arr[i - 1] && arr[i] < arr[i + 1]) dem++;
	}

	cout << dem;

	return 0;
}