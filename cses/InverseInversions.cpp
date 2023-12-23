#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ll n, k; cin >> n >> k;	
	
	ll maxK = n * (n - 1) / 2;
	
	for (int i = 1; i <= n; i++){
		if (maxK - k >= n - i){
			maxK -= n - i;
			cout << i << " ";
		}else{
			int x = n - (maxK - k);
			cout << x << " ";
			for (int j = n; j >= i; j--) if (j != x)
				cout << j << " ";
			return 0;
		}
	}
	return 0;
}