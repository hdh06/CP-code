#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin >> n;
	int ans = 0;
	for (int i = pow(10, n - 1); i < pow(10, n); i++) if (i % 13 == 0){
		int d = i; bool flag = true;
		while (d > 0){
			if (d % 10 == 3 || d % 10 == 1) flag = false;
			d /= 10;
		}
		ans += flag;
	}	
	cout << ans;
	return 0;
}