#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, t;
	cin >> n;

	bool h[(int)1e6 + 2];
	while(n --){
		int t;
		cin >> t;
		h[t] += !h[t];
	}

	for (int i = 1; i <= 1e6 + 1; i++){
		if (h[i] == 0){
			cout << i;
			return 0;
		}
	}
	return 0;
}