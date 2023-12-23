#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int const N = 1e5 + 1;

template<typename T> T gcd(T a, T b) { return (b == 0? a : gcd(b, a % b)); }
template<typename T> T lcm(T a, T b) { return a / gcd(a, b) * b; }

int main(){
	int n; cin >> n;
	int arr[N];
	for (int i = 1; i <= n; i++){
		cin >> arr[i];
	}	

	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		int maxx = 0;
		for (int j = i - 1; j >= 1; j--){
			maxx = max(maxx, gcd(arr[i], arr[j]));
		}
		ans += maxx;	
	}
	cout << ans;
	return 0;
}