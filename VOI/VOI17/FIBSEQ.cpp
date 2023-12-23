#include <bits/stdc++.h>

using namespace std;

#define st first
#define nd second
#define all(x) x.begin(), x.end()
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
#define mp make_pair

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ii> vii;
typedef vector<pll> vll;
typedef vector<bool> vb;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l, ll r){return uniform_int_distribution<ll>(l, r)(rd);}

#define file "FIBSEQ"

int n;
ll i;
int k;

namespace sub1{
    void solve(){
        vi z;
        int a = 1 % k, b = 1 % k;
        if (1 >= i) z.pb(a);
        if (2 >= i) z.pb(b);
        for (int j = 3; j <= i + n - 1; j++){
            int c = (a + b) % k;
            if (j >= i) z.pb(c);
            a = b;
            b = c;
        }

        int ans = 0;
        for (int mask = 1; mask < (1 << n); mask++){
            int sum = 0;
            for (int j = 0; j < n; j++) if (mask & (1 << j)){
                (sum += z[j]) %= k;
            }
            if (sum == 0){
                ans = mask;
                break;
            }
        }

        cout << __builtin_popcount(ans) << " ";
        for (int j = 0; j < n; j++) if (ans & (1 << j)) cout << i + j << " "; cout << "\n";
    }
}

namespace sub2{
    int const N = 1e3 + 1;
    int dp[N][N];
    void solve(){
        vi z;
        int a = 1 % k, b = 1 % k;
        if (1 >= i) z.pb(a);
        if (2 >= i) z.pb(b);
        for (int j = 3; j <= i + n - 1; j++){
            int c = (a + b) % k;
            if (j >= i) z.pb(c);
            a = b;
            b = c;
        }

        dp[0][0] = 0;
        for (int j = 1; j < k; j++) dp[0][j] = -100000;
        for (int d = 1; d <= z.size(); d++)
            for (int j = 0; j < k; j++)
                dp[d][j] = max(dp[d - 1][j], dp[d - 1][(j - z[d - 1] + k) % k] + 1);

        if (dp[z.size()][0] <= 0){
            cout << 0 << "\n";
            return;
        }
        cout << dp[z.size()][0] << " ";

        int d = z.size(), j = 0;
        while (d){
            if (dp[d][j] != dp[d - 1][j] && dp[d][j] == dp[d - 1][(j - z[d - 1] + k) % k] + 1){
                cout << i + d - 1 << " ";
                j = (j - z[d - 1] + k) % k;
            }

            d--;
        }
        cout << "\n";
    }
}

namespace sub4{
    struct matrix{
        int n, m;
        ll f[3][3] = {};
        matrix(){}
        matrix(int n, int m):n(n), m(m){}
    };

    matrix idf(int n, int mod){
        matrix c(n, n);
        for (int i = 1; i <= n; i++)
            c.f[i][i] = 1 % mod;
        return c;
    }

    matrix mul(matrix a, matrix b, int mod){
        //a.n = b.m
        matrix c(b.n, a.m);
        for (int i = 1; i <= a.m; i++)
            for (int j = 1; j <= b.n; j++)
                for (int k = 1; k <= a.n; k++)
                    (c.f[j][i] += 1LL * a.f[k][i] * b.f[j][k] % mod) %= mod;
//        cerr << c.f[1][1] << " " << c.f[2][1] << "\n";
        return c;
    }

    matrix mpow(matrix &a, int n, int mod){
        if (n == 0) return idf(a.n, mod);
        matrix ans = mpow(a, n / 2, mod);
        if (n & 1) return mul(mul(ans, ans, mod), a, mod);
        return mul(ans, ans, mod);
    }

    void solve(){
        matrix f(2, 1), A(2, 2);
        f.f[2][1] = 1;
        A.f[1][2] = A.f[2][1] = A.f[2][2] = 1;
        f = mul(f, mpow(A, i - 1, k), k);
//        f = mul(f, A, k);
        vi z;
        z.pb(f.f[2][1]);
//        cerr << f.f[2][1] << "\n";
        for (int j = 1; j <= n - 1; j++){
            f = mul(f, A, k);
            z.pb(f.f[2][1]);
        }

        int ans = 0;
        for (int mask = 1; mask < (1 << n); mask++){
            int sum = 0;
            for (int j = 0; j < n; j++) if (mask & (1 << j)){
                (sum += z[j]) %= k;
            }
            if (sum == 0){
                ans = mask;
                break;
            }
        }

        cout << __builtin_popcount(ans) << " ";
        for (int j = 0; j < n; j++) if (ans & (1 << j)) cout << i + j << " "; cout << "\n";
    }
}

namespace sub5{
    int const N = 1e3 + 1;
    int dp[N][N];
    struct matrix{
        int n, m;
        int f[3][3] = {};
        matrix(){}
        matrix(int n, int m):n(n), m(m){}
    };

    matrix idf(int n, int mod){
        matrix c(n, n);
        for (int i = 1; i <= n; i++)
            c.f[i][i] = 1 % mod;
        return c;
    }

    matrix mul(matrix a, matrix b, int mod){
        //a.n = b.m
        matrix c(b.n, a.m);
        for (int i = 1; i <= a.m; i++)
            for (int j = 1; j <= b.n; j++)
                for (int k = 1; k <= a.n; k++)
                    (c.f[j][i] += 1LL * a.f[k][i] * b.f[j][k] % mod) %= mod;
//        cerr << c.f[1][1] << " " << c.f[2][1] << "\n";
        return c;
    }

    matrix mpow(matrix &a, int n, int mod){
        if (n == 0) return idf(a.n, mod);
        matrix ans = mpow(a, n / 2, mod);
        if (n & 1) return mul(mul(ans, ans, mod), a, mod);
        return mul(ans, ans, mod);
    }

    void solve(){
        matrix f(2, 1), A(2, 2);
        f.f[2][1] = 1;
        A.f[1][2] = A.f[2][1] = A.f[2][2] = 1;
        f = mul(f, mpow(A, i - 1, k), k);
//        f = mul(f, A, k);
        vi z;
        z.pb(f.f[2][1]);
//        cerr << f.f[2][1] << "\n";
        for (int j = 1; j <= n - 1; j++){
            f = mul(f, A, k);
            z.pb(f.f[2][1]);
        }

        dp[0][0] = 0;
        for (int j = 1; j < k; j++) dp[0][j] = -100000;
        for (int d = 1; d <= z.size(); d++)
            for (int j = 0; j < k; j++)
                dp[d][j] = max(dp[d - 1][j], dp[d - 1][(j - z[d - 1] + k) % k] + 1);

        if (dp[z.size()][0] <= 0){
            cout << 0 << "\n";
            return;
        }

        cout << dp[z.size()][0] << " ";

        int d = z.size(), j = 0;
        while (d){
            if (dp[d][j] != dp[d - 1][j] && dp[d][j] == dp[d - 1][(j - z[d - 1] + k) % k] + 1){
                cout << i + d - 1 << " ";
                j = (j - z[d - 1] + k) % k;
            }

            d--;
        }
        cout << "\n";
    }
}

namespace sub6{
    struct matrix{
        int n, m;
        int f[3][3] = {};
        matrix(){}
        matrix(int n, int m):n(n), m(m){}
    };

    matrix idf(int n, int mod){
        matrix c(n, n);
        for (int i = 1; i <= n; i++)
            c.f[i][i] = 1 % mod;
        return c;
    }

    matrix mul(matrix a, matrix b, int mod){
        //a.n = b.m
        matrix c(b.n, a.m);
        for (int i = 1; i <= a.m; i++)
            for (int j = 1; j <= b.n; j++)
                for (int k = 1; k <= a.n; k++)
                    (c.f[j][i] += 1LL * a.f[k][i] * b.f[j][k] % mod) %= mod;
//        cerr << c.f[1][1] << " " << c.f[2][1] << "\n";
        return c;
    }

    matrix mpow(matrix &a, ll n, int mod){
        if (n == 0) return idf(a.n, mod);
        matrix ans = mpow(a, n / 2, mod);
        if (n & 1) return mul(mul(ans, ans, mod), a, mod);
        return mul(ans, ans, mod);
    }

    int const N = 1e6 + 1;
	int psum[N] = {};
    int pos[N];

    void solve(){
        matrix f(2, 1), A(2, 2);
        f.f[2][1] = 1;
        A.f[1][2] = A.f[2][1] = A.f[2][2] = 1;
        f = mul(f, mpow(A, i - 1, k), k);
//        f = mul(f, A, k);
//        int cnt[N] = {};
//        cnt[f.f[2][1]]++;
//        cerr << f.f[2][1] << "\n";
	   	int a = f.f[1][1], b = f.f[2][1];
	  	psum[1] = b;
       	for (int j = 2; j <= n; j++){
			int c = a + b;
			if (c >= k) c -= k;
			psum[j] = psum[j - 1] + c;
			if (psum[j] >= k) psum[j] -= k;
 			a = b;
			b = c;
        }
    	memset(pos, -1, sizeof pos);
    	pos[0] = 0;
    	for (int j = 1; j <= n; j++){
    		if (pos[psum[j]] != -1){
    			cout << j - pos[psum[j]] << " ";
    			for (int d = pos[psum[j]] + 1; d <= j; d++) cout << i + d - 1 << " "; cout << "\n";
    			return;
    		}
    		pos[psum[j]] = j;
    	}  
        cout << 0 << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen(file".inp", "r", stdin);
    // freopen(file".out", "w", stdout);

    int t;
    cin >> t;
    while (t--){
        cin >> n >> i >> k;
        // if (n <= 20 && i <= 1000000)
            // sub1::solve();
        // else if (n <= 1000 && i <= 1000000)
            // sub2::solve();
        // else if (n <= 20)
            // sub4::solve();
        // else if (n <= 1000)
            // sub5::solve();
        // else
            sub6::solve();
    }
    return 0;
}
