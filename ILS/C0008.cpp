#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int const N = 5e5 + 1;

int main(){
	int n, m; cin >> n >> m;
	ll a[N] = {}, b[N] = {};
	
	for (int i = 1; i <= n; i++)	
		cin >> a[i];
	for (int i = 1; i <= m; i++)
		cin >> b[i];
		
	sort(b + 1, b + m + 1);
	
	ll pre[N] = {};
	for (int i = 1; i <= m; i++)
		pre[i] = b[i] + pre[i - 1] - 2 * b[i - 1];
	
 	//pre_i = b_i - b_{i - 1} - ... - b_1

	// a_i >= b1	
	// a_i >= b2 - b1
	// a_i >= b3 - b1 - b2
	// ...
	// a_i >= bn - b1 - ... - bn - 1
	
	for (int i = 1; i <= n; i++){
		int k = 0;
		for (int l = 0, r = m; l <= r;){
			int mid = l + (r - l) / 2;
			if (a[i] >= pre[mid]){
				k = mid;
				l = mid + 1;
			}else r = mid - 1;
		}
		cout << a[i] - pre[k] + 2 * b[k] << " ";
	}
	

	return 0;
}