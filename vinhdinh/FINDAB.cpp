#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 2;

typedef long long ll;

int n;
ll a[N], b[N];

bool tknp(ll x){
	int l = 1, r = n;

	while (l <= r){
		int mid = (l + r)/2;

		if (b[mid] == x) return true;
		if (b[mid] > x) r = mid - 1;
		if (b[mid] < x) l = mid + 1;
	}
	return false;
}

int main(){
	cin >> n;

	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];

	sort(b + 1, b + n + 1);
	
	int dem = 0;
	for (int i = 1; i <= n; i++){
		dem += tknp(a[i]);
	}

	cout << dem;
	return 0;
}