#include <bits/stdc++.h>

using namespace std;

int const F = 31;

typedef long long ll;

int main(){
	string s; cin >> s;
	if (s[1] == '.'){
		double n = stod(s);
		for (int i = 1; i < F; i++){
			if (n == (double)1/(double)pow(3, i)){
				cout << -i;
				return 0;
			}
			cout << (double)1/(double)pow(3, i) << "\n";
		}
		cout << "NO";
	}
	else{
		ll n = stoll(s);
		int k = 0;
		while (n % 3 == 0){
			k++;
			n /= 3;
		}
		if (n > 1) cout << "NO";
		else cout << k;
	}
	return 0;
}