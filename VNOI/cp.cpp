#include <bits/stdc++.h>

#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 1001
#endif

using namespace std;
#define all(x) x.begin(), x.end()
#define st first
#define nd second
#define lb lower_bound
#define ub upper_bound
#define sz(x) (int)x.size()
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define file "TEMPLATE"

typedef long long ll;
typedef pair<int, int> ii;
typedef array<int, 3> iii;
typedef vector<int> vi;
typedef vector<ll> vl;

bool const SINGLE_TEST = 0;

string cong(string a, string b){
	reverse(all(a)); reverse(all(b));
	if (a.size() > b.size()) swap(a, b);
	while (a.size() < b.size()) a = a + '0';
	int du = 0;
	string c;
	for (int i = 0; i < a.size(); i++){
		du += (a[i] - '0') + (b[i] - '0');
		c.pb((char)(du % 10 + '0'));
		du /= 10;
	}
	if (du > 0) c.pb((char)(du + '0'));
	return string(c.rbegin(), c.rend());
}

string div2(string s){
	string ans;
	int du = 0;
	for (auto x: s){
		du = du * 10 + (x - '0');
		if (du / 2 != 0 || ans.size() != 0) ans.pb((char)du / 2 + '0');
		du %= 2;
	}
	return ans;
}

string nhan(string a, string b){
	string ans = "0";
	for (int i = a.size() - 1; i >= 0; i--){
		int du = 0;
		string c;
		for (int j = b.size() - 1; j >= 0; j--){
			du += (b[j] - '0') * (a[i] - '0');
			c.pb((char)(du % 10 + '0'));
			du /= 10;
		}			
		if (du > 0)	c.pb((char)(du + '0'));
		
		reverse(all(c));
		for (int k = a.size() - i - 1; k; k--) c += '0';
		ans = cong(ans, c);
	}
	while (ans.size() > 1 && ans.front() == '0') ans.erase(ans.begin());	
	return ans;
}
string tru1(string s){
	int pos = s.size() - 1;
	while (s[pos] == '0') pos--;
	s[pos]--;
	for (int i = pos + 1; i < s.size(); i++) s[i] = '9';
	return s;
}

bool cmp(string a, string b){
	if (a.size() != b.size()) return a.size() < b.size();
	for (int i = 0; i < a.size(); i++)
		if (a[i] != b[i]) return a[i] < b[i];
	
	return 1;
}

map<string, bool> memo;

bool cpcheck(string x){
	if (memo.find(x) != memo.end()) return memo[x];
	string l = "1", r = string(100, '9');
	while (cmp(l, r)){
		string mid = div2(cong(l, r));
		string p2 = nhan(mid, mid);
		if (p2 == x) return memo[x] = 1;
		if (!cmp(p2, x)){
			r = tru1(mid);
		}else l = cong(mid, "1");
	}
	return memo[x] = 0;
}

void solve(){
	string s; cin >> s;
	int n = s.size();
	s = ' ' + s;
	vl dp(s.size());
	dp[0] = 1;
	for (int i = 1; i <= n; i++){
		if (s[i] == '2' || s[i] == '3' || s[i] == '7' || s[i] == '8') continue;
		for (int j = i; j >= 1; j--){
			if (s[j] == '0') continue;
			if (!cpcheck(s.substr(j, i - j + 1))) continue;
			dp[i] += dp[j - 1];
		}
	}
	cout << dp[n] << "\n";
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);
	int t;
	if (SINGLE_TEST) t = 1;
	else cin >> t;
	while (t--) solve();
	return 0;
}//it's coding time!