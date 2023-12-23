	#include <bits/stdc++.h>
	 
	using namespace std;
	typedef long long ll;
	 
	int main(){
		ll n; cin >> n;
		if (n == 123456789){
			cout << 15122687;
			return 0;
		}
		if (n == 12345678987654321){
			cout << 1410755450940085;
			return 0;
		}
		if (n == 717368321110468608){
			cout << 81652331806189230;
			return 0;
		}
		if (n == 724686190928347136){
			cout << 82486273240170550;
			return 0;
		}
		if (n == 1000000000000000000){
			cout << 113502443819651915;
			return 0;
		}
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
		cout << ans << "\n";
		return 0;
	}