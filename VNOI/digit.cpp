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

bool const SINGLE_TEST = 1;

int n, k;

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

ll cnt = 0;

string nhan(string a, string b){
	string ans = "0";
	for (int i = a.size() - 1; i >= 0; i--){
		int du = 0;
		string c;
		for (int j = b.size() - 1; j >= 0; j--){
			du += (b[j] - '0') * (a[i] - '0');
			c.pb((char)(du % 10 + '0'));
			du /= 10;
			cnt++;
		}			
		if (du > 0)	c.pb((char)(du + '0'));
		
		reverse(all(c));
		for (int k = a.size() - i - 1; k; k--) c += '0';
		ans = cong(ans, c);
	}
	while (ans.size() > 1 && ans.front() == '0') ans.erase(ans.begin());	
	return ans;
}

typedef vector<vector<string> > matrix;

matrix operator*(matrix const &a, matrix const &b){
	int n = b.size(), m = a[0].size();
	matrix c(n, vector<string>(m, "0"));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			for (int k = 0; k < n; k++)
				c[i][j] = cong(c[i][j], nhan(b[i][k], a[k][j]));
	return c;
}

matrix idf(int n){
	matrix c(n, vector<string>(n, "0"));
	for (int i = 0; i < n; i++)
		c[i][i] = "1";
	return c;
}

matrix operator^(matrix x, int n){
	if (n == 0) return idf(x.size());
	matrix ans = x ^ (n / 2);
	if (n & 1) return ans * ans * x;
	return ans * ans;
}

void solve(){
	cin >> n >> k;
	string del = to_string(k - 1);
	
	matrix f = {{"1"}, {"1"}};
	matrix A = {{del, "1"}, {del, "0"}};

	f = f * (A ^ n);
	
	cout << (n == 1? f[0][0] : f[1][0]);
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