#include <bits/stdc++.h>

using namespace std;

int main(){
	// freopen("f.out", "w", stdout);
	int p[1000000] = {};
	for (int i = 1; i <= 2000; i++){
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
	for (int j = 1; j < 10; j++){
		for (int i = (j == 1? 1: 0); i < 100; i++){
			cout << 100 * (j - 1) + i << ": " << p[100 * (j - 1) + i] - p[100 * (j - 1) + i - 1] << " " << 100 * j + i << ": " << p[100 * j + i] - p[100 * j + i - 1] << "\n";
			assert(p[100 * (j - 1) + i] - p[100 * (j - 1) + i - 1] == p[100 * j + i] - p[100 * j + i - 1]);
		}
	}
	return 0;
}
