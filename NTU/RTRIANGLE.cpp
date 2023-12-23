#include <bits/stdc++.h>

using namespace std;

int main(){
	long long n; cin >> n;
	
	long long s = sqrtl(n * 2);
	
	if (s * (s + 1) / 2 == n){
		cout << "YES\n";
	}else cout << "NO\n";
	return 0;
}