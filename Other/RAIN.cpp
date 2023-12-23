#include<bits/stdc++.h>

using namespace std;

int main(){
	int n; 
	cin >> n; 

	vector<int> arr(n + 2, 0), L(n + 2, 0), R(n + 2, 0);

	for (int i = 1; i <= n; i++){
		cin >> arr[i];
		L[i] = R[i] = arr[i];
	}

	for (int i = 1; i <= n; i++) if (L[i - 1] >= L[i]) L[i] = L[i - 1];
	for (int i = n; i >= 1; i--) if (R[i + 1] >= R[i]) R[i] = R[i + 1];	

	// cout << "V:"; for (int i = 1; i <= n; i++) cout << arr[i] << " \n"[i == n];
 //    cout << "L:"; for (int i = 1; i <= n; i++) cout << L[i] << " \n"[i == n];
	// cout << "R:"; for (int i = 1; i <= n; i++) cout << R[i] << " \n"[i == n];
	// cout << "A:"; for (int i = 1; i <= n; i++) cout << min(L[i], R[i]) - arr[i] << " ";

	int tong = 0;
	for (int i = 1; i <= n; i++) tong += min(L[i], R[i]) - arr[i];

	cout << tong;
	return 0;
}