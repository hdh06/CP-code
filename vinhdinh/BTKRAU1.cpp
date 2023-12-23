#include <bits/stdc++.h>

using namespace std;

int const N = 23;

int main(){
	int n; cin >> n;
	int arr[N] = {};
	for (int i = 0; i < n; i++)
		cin >> arr[i];
		
	int ans = 0;
	for (int mask = 0; mask < (1 << n); mask++){
		int A = 0, B = 0;
		for (int i = 0; i < n; i++)
			if (mask & (1 << i))
				A += arr[i];
			else B += arr[i];
		ans += A == B;
	}
	cout << ans;
	return 0;
}