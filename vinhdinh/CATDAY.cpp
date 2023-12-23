#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;

int n, k; 
int arr[N];
int res = 0;

int check(int m){
	int tong = 0;
	for (int i = 1; i <= n; i++){
		tong += arr[i]/m;
	}
	return tong;
}

void tknp(int l, int r){
	if (r < l) return; 
	int mid = (l + r)>>1;
	int ans = check(mid);

	if (ans >= k){
		res = mid;
		tknp(mid + 1, r);
	}
	else tknp(l, mid - 1);
}

int main(){
	cin >> n >> k;	
	for (int i = 1; i <= n; i++) cin >> arr[i];
	tknp(1, (int)1e9);
	cout << res;
	return 0;
}