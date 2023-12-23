#include <bits/stdc++.h>

using namespace std;

int const N = 1e6 + 1;

int main(){
	int n, q, arr[N];
	cin >> n >> q;

	for (int i = 1; i <= n; i++) cin >> arr[i];

	while(q --){
		int l , r;
		cin >> l >> r;

		int dem = 0;
		for (int i = l; i <= r; i++){
			for (int j = i - 1; j >= l; j--)
				if (arr[j] > arr[i]) dem++;
			// cout << dem << endl;
		}
		cout << dem << endl;
	}
	return 0;
}