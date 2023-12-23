#include <bits/stdc++.h>

using namespace std;

int const N = 1e5;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	int arr[N] = {};
	int n, m , k;
	cin >> n >> m >> k;

	for (int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			int temp;
			cin >> temp;
			arr[temp]++;
		}
	}
	vector<long long> sums;
	for (int i = 0; i < N; i++) if (arr[i] != 0)  {
		sums.push_back(arr[i]);
		//cout << arr[i] << "*" << i << " " << endl;
	}
	sort(sums.begin(), sums.end(), greater<long long>());

	int tong = 0, dem = 0;
	for (long long t: sums){
		if (dem == k) break;
		dem++;
		tong += t;
	}

	cout << tong;
	return 0;
}