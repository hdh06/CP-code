#include <bits/stdc++.h>

#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 1000
#endif

using namespace std;

#define st first
#define nd second
#define all(x) x.begin(), x.end()
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define pc __builtin_popcount

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long ldb;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ii> vii;
typedef vector<pll> vll;
typedef vector<bool> vb;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l, ll r){return uniform_int_distribution<ll>(l, r)(rd);}

#define file "QPALIN"

int n, k;
string s;
ll t;

namespace sub1{
    void solve(){
    	cin >> t;
        for (int mask = 0; mask < (1 << n); mask++){
            int mask_k = -1;
            int a = 0, b = 0;
            for (int i = n - 1; i >= 0; i--){
                if (mask & (1 << i))
                    a++;
                else b++;
                if (a % 2 != 0 && b % 2 != 0) continue;
                if (i < n - 1) mask_k++;
            }
            if (a % 2 != 0 && b % 2 != 0) continue;
            if (mask_k >= k){            	
            	// for (int i = n - 1; i >= 0; i--)
                    // if( mask & (1 << i)) cerr << s[1];
                    // else cerr << s[0]; cerr << "\n";
            	t--;
            }
            if (t == 0){
                for (int i = n - 1; i >= 0; i--)
                    if( mask & (1 << i)) cout << s[1];
                    else cout << s[0];
                cout << "\n";
                return;
            }
        }
    }
}

namespace sub2{
    int const N = 11;
    ll dp[N][N][N][N][N][N];

    ll calc(int i, int c1, int c2, int c3, int c4, int c5){
        if (i == n){
            int cnt = (c1 & 1) + (c2 & 1) + (c3 & 1) + (c4 & 1) + (c5 & 1);
            return cnt <= 1;
        }

        ll &ans = dp[i][c1][c2][c3][c4][c5];
        if (ans != -1) return ans;
        ans = 0;
        ans += calc(i + 1, c1 + 1, c2, c3, c4, c5);
        if (s.size() < 2) return ans;
        ans += calc(i + 1, c1, c2 + 1, c3, c4, c5);
        if (s.size() < 3) return ans;
        ans += calc(i + 1, c1, c2, c3 + 1, c4, c5);
        if (s.size() < 4) return ans;
        ans += calc(i + 1, c1, c2, c3, c4 + 1, c5);
        if (s.size() < 5) return ans;
        ans += calc(i + 1, c1, c2, c3, c4, c5 + 1);
        return ans;
     }
    void solve(){
    	cin >> t;
        memset(dp, -1, sizeof dp);
        int c1, c2, c3, c4, c5;
        c1 = c2 = c3 = c4 = c5 = 0;
        string ans;
        for (int i = 0; i < n; i++){
            if (calc(i + 1, c1 + 1, c2, c3, c4, c5) >= t) {c1++, ans.pb(s[0]); continue;}
            t -= calc(i + 1, c1 + 1, c2, c3, c4, c5);
            if (s.size() < 2) continue;
            if (calc(i + 1, c1, c2 + 1, c3, c4, c5) >= t) {c2++, ans.pb(s[1]); continue;}
            t -= calc(i + 1, c1, c2 + 1, c3, c4, c5);
            if (s.size() < 3) continue;
            if (calc(i + 1, c1, c2, c3 + 1, c4, c5) >= t) {c3++, ans.pb(s[2]); continue;}
            t -= calc(i + 1, c1, c2, c3 + 1, c4, c5);
            if (s.size() < 4) continue;
            if (calc(i + 1, c1, c2, c3, c4 + 1, c5) >= t) {c4++, ans.pb(s[3]); continue;}
            t -= calc(i + 1, c1, c2, c3, c4 + 1, c5);
            if (s.size() < 5) continue;
            if (calc(i + 1, c1, c2, c3, c4, c5 + 1) >= t) {c5++, ans.pb(s[4]); continue;}
            t -= calc(i + 1, c1, c2, c3, c4, c5 + 1);
        }
        cout << ans << "\n";
    }
}

namespace sub3{
    int const N = 51;
    ll dp[N][N][N];

    ll calc(int i, int c1, int c2){
        if (i == n){
            int cnt = (c1 & 1) + (c2 & 1);
            return cnt <= 1;
        }

        ll &ans = dp[i][c1][c2];
        if (ans != -1) return ans;
        ans = 0;
        ans += calc(i + 1, c1 + 1, c2);
        if (s.size() < 2) return ans;
        ans += calc(i + 1, c1, c2 + 1);
        return ans;
     }
    void solve(){
    	cin >> t;
        memset(dp, -1, sizeof dp);
        int c1, c2;
        c1 = c2 = 0;
        string ans;
        for (int i = 0; i < n; i++){
            if (calc(i + 1, c1 + 1, c2) >= t) {c1++, ans.pb(s[0]); continue;}
            t -= calc(i + 1, c1 + 1, c2);
            if (s.size() < 2) continue;
            if (calc(i + 1, c1, c2 + 1) >= t) {c2++, ans.pb(s[1]); continue;}
            t -= calc(i + 1, c1, c2 + 1);
        }
        cout << ans << "\n";
    }
}



namespace sub4{
	string t;
	string cong(string a, string b){
		if (a.size() < b.size()) swap(a, b);
		b = string(a.size() - b.size(), '0') + b;
		
		string c;
		
		int du = 0;
		for (int i = a.size() - 1; i >= 0; i--){
			du += a[i] - '0' + b[i] - '0';
			c += (char)(du % 10 + '0');
			du /= 10;
		}
		if (du > 0) c += (char)(du + '0');
		reverse(all(c));
		return c;
	}
	
	string tru(string a, string b){
		b = string(a.size() - b.size(), '0') + b;
		
		string c;
		int du = 0;
		for (int i = a.size() - 1; i >= 0; i--){
			du = a[i] - '0' - du - (b[i] - '0');
			
			int d = du;
			if (du < 0) du = 1, d += 10; else du = 0;
			
			c += (char)(d + '0');
		}
		while (c.size() > 1 && c.back() == '0') c.erase(c.size() - 1, 1);
		reverse(all(c));
		return c;
	}
	
	bool cmp(string a, string b){
		if (a.size() < b.size()) a = string(b.size() - a.size(), '0');
		if (a.size() > b.size()) b = string(a.size() - b.size(), '0');
		
		return a >= b;
		
	}
	
    int const N = 51;
    bool vis[N][1 << 5];
    string dp[N][1 << 5];

    string calc(int i, int mask){
        if (i == n)
			return (pc(mask) <= 1? "1": "0");
    
        string &ans = dp[i][mask];
        if (vis[i][mask]) return ans;
        vis[i][mask] = 1;
        ans = "0";
		for (int j = 0; j < s.size(); j++)
			ans = cong(ans, calc(i + 1, mask ^ (1 << j)));
		
        return ans;
     }
    void solve(){
    	cin >> t;
		int mask = 0;
        string ans;
        for (int i = 0; i < n; i++){
         	for (int j = 0; j < s.size(); j++){
         		if (cmp(calc(i + 1, mask ^ (1 << j)), t)){
         			mask ^= 1 << j;
         			ans.pb(s[j]);
         			break;
         		}
         		t = tru(t, calc(i + 1, mask ^ (1 << j)));
         	}
        }
        cout << ans << "\n";
    }
}

namespace sub5{
	string t;
	string cong(string a, string b){
		if (a.size() < b.size()) swap(a, b);
		b = string(a.size() - b.size(), '0') + b;
		
		string c;
		
		int du = 0;
		for (int i = a.size() - 1; i >= 0; i--){
			du += a[i] - '0' + b[i] - '0';
			c += (char)(du % 10 + '0');
			du /= 10;
		}
		if (du > 0) c += (char)(du + '0');
		reverse(all(c));
		return c;
	}
	
	string tru(string a, string b){
		b = string(a.size() - b.size(), '0') + b;
		
		string c;
		int du = 0;
		for (int i = a.size() - 1; i >= 0; i--){
			du = a[i] - '0' - du - (b[i] - '0');
			
			int d = du;
			if (du < 0) du = 1, d += 10; else du = 0;
			
			c += (char)(d + '0');
		}
		while (c.size() > 1 && c.back() == '0') c.erase(c.size() - 1, 1);
		reverse(all(c));
		return c;
	}
	
	bool cmp(string a, string b){
		if (a.size() < b.size()) a = string(b.size() - a.size(), '0');
		if (a.size() > b.size()) b = string(a.size() - b.size(), '0');
		
		return a >= b;
		
	}
	
    int const N = 51;
    bool vis[N][N][1 << 5];
    string dp[N][N][1 << 5];
    

    string calc(int i, int ck, int mask){
        if (i == n){
        	// if (pc(mask) <= 1 && ck - 1 >= k) debug("1");
			return (pc(mask) <= 1 && ck - 1 - (pc(mask) <= 1) >= k? "1": "0");
		}
    
        string &ans = dp[i][ck][mask];
        if (vis[i][ck][mask]) return ans;
        vis[i][ck][mask] = 1;
        ans = "0";
		for (int j = 0; j < s.size(); j++)
			ans = cong(ans, calc(i + 1, ck + (pc(mask ^ (1 << j)) <= 1), mask ^ (1 << j)));
		
        return ans;
     }
    void solve(){
    	cin >> t;
		int mask = 0;
		int ck = 0;
        string ans;
        for (int i = 0; i < n; i++){
         	for (int j = 0; j < s.size(); j++){
         		if (cmp(calc(i + 1, ck + (pc(mask ^ (1 << j)) <= 1), mask ^ (1 << j)), t)){
         			mask ^= 1 << j;
         			ck += pc(mask) <= 1;
         			ans.pb(s[j]);
         			break;
         		}
         		t = tru(t, calc(i + 1, ck + (pc(mask ^ (1 << j)) <= 1) , mask ^ (1 << j)));
         		// debug( calc(i + 1, ck + (pc(mask ^ (1 << j)) <= 1) , mask ^ (1 << j)));
         	}
        }
        cout << ans << "\n";
    }
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen(file".inp", "r", stdin);
    // freopen(file".out", "w", stdout);

    cin >> n >> k >> s;
    sort(all(s));
    s.erase(unique(all(s)), s.end());
    if (n <= 10 && s.size() == 2)
        sub1::solve();
    else if (n <= 10 && k == 0)
        sub2::solve();
    else if (n <= 50 && k == 0 && s.size() == 2)
        sub3::solve();
    else if (n <= 50 && k == 0)
        sub4::solve();
    else
        sub5::solve();
    return 0;
}
