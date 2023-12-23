//O(N log (log N))
#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	//sang nt
	int const N = 1001;
	int sang[N] = {1,1};
	for (int i = 2; i <= n; i++)if (sang[i] == 0){
		for (int j = i*i; j <= n; j+=i){
			sang[j] = 1;
		}
		while (n > 1 && n % i == 0){
			n /= i;
			sang[i]--;
		}
	}
	//---
	bool kt = false;
	for (int i = 0; i < N; i++){
		if (sang[i] < 0){
			cout << i << "^" << abs(sang[i]) << " ";
			kt = true;
		}
	} 
	if (kt == false) cout << -1;
	return 0;
}