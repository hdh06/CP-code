#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll fact[] = {1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600,6227020800,87178291200,1307674368000,20922789888000};

ll m, n, Sa = 0;
ll A[17], B[17];

int num(char c){return c - '0';};
char chr(int c){return c + '0';};

string cong(string a, string b){
	if (a.size() > b.size()) swap(a, b);
	while (a.size() < b.size()) a = '0' + a;

	string c;

	int du = 0;
	for (int i = a.size() - 1; i >= 0; i--){
		du += num(a[i]) + num(b[i]);
		c = chr(du % 10) + c;
		du /= 10;
	}
	if (du > 0) c = chr(du) + c;
	return c;
}

string nhan(string a, string b){
	string c = "0";
	for (int i = a.size() - 1; i >= 0; i--){
		string d;
		int du = 0;
		for (int j = b.size() - 1; j >= 0; j--){
			du += num(a[i])*num(b[j]);
			d = chr(du % 10) + d;
			du /= 10;
		}
		if (du > 0) d = chr(du) + d;
		for (int j = 1; j < a.size() - i; j++) d += '0';

		c = cong(c, d);
	}
	return c;
}

string tru(string a, string b){
	string c;
	while (b.size() < a.size()) b = '0' + b;

	int du = 0;
	for (int i = a.size() - 1; i >= 0; i--){
		if (a[i] < b[i] + du){
			c = chr(a[i] - b[i] - du + 10) + c;
			du = 1;
		}
		else{
			c = chr(a[i] - b[i] - du) + c;
			du = 0;
		}
	} 

	int i = 0;
	while (c[i] == '0') i++;
	return c.substr(i, c.size() - i + 1);
}

map<pair<ll, ll>, string> memo;

string C(ll k, ll n){
	if (k > n) return "0";
	if (memo.find({k, n}) != memo.end()) return memo[{k, n}];
	ll m = fact[k];
	string tich = "1";
	for (int i = k; i >= 1; i--){
		ll d = n - k + i;
		ll ucln = gcd(d, m);
		d /= ucln;
		m /= ucln;
		tich = nhan(tich, to_string(d));	
	}
	return memo[{k, n}] = tich;
}

int main(){
	// freopen("inp.inp", "r", stdin);
	// freopen("out.out", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	cin >> m >> n;
	for (int i = 1; i <= n; i++){
		cin >> A[i]; Sa += A[i];
	}

	for (int i = 1; i <= n; i++){
		cin >> B[i];
		B[i] -= A[i];
	}

	vector<string> temp;

	ll t = 0, dem = 0;
	string ans = C(n - 1, m - Sa + n - 1);
	for (int b = 1; b < (1 << n); b++){
		t = 0, dem = 0;
		for (int i = 0; i < n; i++) if (b & (1 << i)){
			t += B[i + 1] + 1;
			dem++;
		}

		string res = C(n - 1, m - Sa - t + n - 1);
		if (res == "0") continue;
		if (dem & 1) temp.push_back(res);
		else ans = cong(ans, res);
	}

	for (auto x: temp){
		ans = tru(ans, x);
		// cout << ans << "\n-" << x + "\n";
	}
	cout << ans;
	return 0;
}
