#include <bits/stdc++.h>

using namespace std;

int const N = 21;

typedef long long ll;

int arr[N];



ll dequy(int n, ll t1, ll t2){
	if (n == 0){
		return abs(t1 - t2);
	}
	return min(dequy(n - 1, t1 + arr[n], t2), dequy(n - 1, t1, t2 + arr[n]));
}

int main(){
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) cin >> arr[i];

	cout << dequy(n, 0, 0);
	return 0;
}