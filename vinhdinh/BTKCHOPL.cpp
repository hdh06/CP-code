#include <bits/stdc++.h>

using namespace std;

int const N = 9;

int n, k;
int arr[N];
int p[N];

void dequy(int i, int t){
	if (t == k){
		for (int x = 0; x < t; x++) cout << p[x] << " ";
		cout << endl;
		return;
	}

	if (i == n) return;

	for (int x = 0; x < n; x++){
		p[t] = arr[x];
		dequy(i + 1, t + 1);
		// dequy(i + 1, t);
	}
}

int main(){
	cin >> k >> n;

	for (int i = 0; i < n; i++) cin >> arr[i];
	
	sort(arr, arr + n);

	cout << pow(n , k) << endl;
	dequy(0, 0);

	return 0;
}