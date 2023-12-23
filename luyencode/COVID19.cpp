#include <bits/stdc++.h>

using namespace std;

#define ll long long

long long const MOD = 2021;

ll mpow(ll x, ll n){
	if (n == 0) return 1;

	ll ans = mpow(x, n/2);
	ans = (ans*ans)%MOD;

	if (n % 2 == 1) ans = (ans*x)%MOD;

	return ans;
}
int modulo_inverse(int n, int m) {
  for (int i=1; i < m; i++) {
    if (((long long) n * i) % m == 1) {
      return i;
    }
  }
  return -1; // not exist
}

int main(){
    ll n, k;
    cin >> k >> n;
    
    if (k == 0 || n == 1){
        cout << 0;
        return 0;
    }
    
    if (n == 0){
        cout << 1;
        return 0;
    }
    
    if (k == 1){
    	cout << n;
    	return 0;
    }
   	cout << modulo_inverse(mpow(k, n - 1) - 1, k - 1);
	return 0;
}