#include <bits/stdc++.h>

using namespace std;

int const N = 1e3 + 1;

int main(){
	int n;
	cin >> n;
	int arr[N][N];
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			cin >> arr[i][j];
			arr[i][j] += max(arr[i - 1][j], arr[i][j - 1]);
		}
	}
	cout << arr[n][n];
	return 0;
}