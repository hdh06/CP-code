#include <bits/stdc++.h>

using namespace std;

int const N = 2e5 + 1;

//Fenwick init
int tree[N];
void upd(int x, int k){
	for (int i = x; i < N; i += i & -i) tree[i] += k;
}
int get(int x){
	int ans = 0;
	for (int i = x; i > 0; i -= i & -i) ans += tree[i];
	return ans;
}

int bs(int x, int l, int r){
	// cout << x << " " << l << " " << r << endl;
	if (l == r) return l;
	int mid = (l + r) >> 1;
	if (get(mid) >= x) return bs(x, l, mid);
	return bs(x, mid + 1, r);
}

int main(){
	int n; cin >> n; 	
	int arr[N];
	for (int i = 1; i <= n; i++){
		cin >> arr[i];
		upd(i, 1);
	}

	int q = n;

	while (q--){
		int x; cin >> x;
		int ans = bs(x, 1, n);
		cout << arr[ans] << " ";
		upd(ans, -1);
	}
	return 0;
}