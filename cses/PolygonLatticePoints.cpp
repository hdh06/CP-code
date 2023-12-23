#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int n;
	cin >> n;

	vector<array<ll, 2> > arr(n + 2);

	for (int i = 1; i <= n; i++) cin >> arr[i][0] >> arr[i][1];

	arr[n + 1] = arr[1];
	
	ll bound = 0;
	ll area = 0;
	for (int i = 2; i <= n + 1; i++){
		bound += __gcd(abs(arr[i][0] - arr[i - 1][0]), abs(arr[i][1] - arr[i - 1][1]));
		// cout <<  gcd(abs(arr[i][0] - arr[i - 1][0]), abs(arr[i][1] - arr[i - 1][1])) << " " << arr[i][0] << "-"  << arr[i - 1][0] << " " << arr[i][1] << "-"  << arr[i - 1][1] << endl;
		area += arr[i - 1][0]*arr[i][1] - arr[i][0]*arr[i - 1][1];
	}

	area = abs(area);

	cout << (area - bound + 2)/2 << " " << bound;
	return 0;
}