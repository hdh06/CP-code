#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; 
	cin >> n;

	vector<int> arr(n + 2, 0), L(n + 2, 0), R(n + 2, 0);

	for (int i = 1; i <= n; i++){
		cin >> arr[i];
		L[i] = R[i] = 1;
	}

	for (int i = 1; i <= n; i++) if (arr[i - 1] < arr[i]) L[i] = L[i - 1] + 1;
	for (int j = n ; j >= 1; j--) if (arr[j + 1] < arr[j]) R[j] = R[j + 1] + 1;

	for (int i = 1; i <= n; i++) cout << max(L[i], R[i]) << " ";
	return 0;
}