#include <bits/stdc++.h>

using namespace std;

int main(){
	int  n , a, b, k;
	cin >> n >> a >> b >> k;
	int i = 1;
	while (k--){
		if (i + a <= n){
			i += a;
		}
		else {
			i -= b;
		}
	}
	return 0;
}