#include <bits/stdc++.h>

#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 1000
#endif

using namespace std;

typedef long long ll;

int main(){
	int p[101] = {};
	for (int i = 1; i <= 300; i++){
		int n = i;
		int ans = 0;
		while (n){
			int x = n;
			int maxx = 0;
			while (x){
				maxx = max(maxx, x % 10);
				x /= 10;
			}
			n -= maxx;
			ans++;
		}	
		p[i] = ans;
	}
	
	debug(p[99]);
	
	for (int i = 1; i <= 300; i++){
		debug(i, p[i] - p[i - 1]);
	}
	
	ll n; cin >> n;
	cout << (n / 100) * p[100] + p[n % 100];
	return 0;
}
