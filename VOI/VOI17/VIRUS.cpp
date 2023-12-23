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

#define file "VIRUS"

int n;
string s;
int k[11];

namespace sub1{
    void solve(){
        for (int i = 1; i <= n; i++){
            int ans = 0;
            for (int l = 0; l < s.size(); l++) for (int r = l; r + (r - l + 1) < s.size(); r++){
                int cnt = 0;
                for (int j = l; j <= r; j++){
                    if (s[j] != s[r + (j - l + 1)]) cnt++;
                    if (cnt > k[i]) break;
                }
                if (cnt <= k[i]) ans = max(ans, r - l + 1);
            }
            cout << ans << "\n";
        }
    }
}

namespace sub2{
    bool check(){
        for (int i = 1; i <= n; i++) if (k[i] != 0) return false;
        return true;
    }
    int const N = 3001;
    int const A = 1e9 + 7, B = 1e9 + 9, M = 1e9 + 17;

    pll h[N];
    int pA[N], pB[N];
    void init(){
        pA[0] = pB[0] = 1;
        for (int i = 1; i < N; i++){
            pA[i] = 1LL * pA[i - 1] * A % M;
            pB[i] = 1LL * pB[i - 1] * B % M;
        }
    }

    pll get(int l, int r){
        return mp(
                (h[r].st - h[l - 1].st * pA[r - l + 1] % M + M) % M,
                (h[r].nd - h[l - 1].nd * pB[r - l + 1] % M + M) % M
                  );
    }

    void solve(){
        init();
        h[0] = mp((int)s[0], (int)s[0]);
        for (int i = 1; i < s.size(); i++)
            h[i] = mp((h[i - 1].st * A % M + s[i]) % M, (h[i - 1].nd * B % M + s[i]) % M);

        int ans = 0;
        for (int l = 0; l < s.size(); l++) for (int r = l; r + (r - l + 1) < s.size(); r++)
            if (get(l, r) == get(r + 1, r + (r - l + 1)))
                ans = max(ans, r - l + 1);
        for (int i = 1; i <= n; i++)
            cout << ans << "\n";
    }
}

namespace sub3{
	int const N = 3001;
	int ans[11] = {};
	void solve(){
		int psum[N] = {};
		for (int d = 1; 2 * d <= s.size(); d++){
			// 0 -> d - 1
			psum[0] = 0;
			for (int i = 0; i < s.size(); i++){
				if (i) psum[i] = psum[i - 1];
				if (i + d < s.size() && s[i] != s[i + d])
					psum[i]++;
			}
			
			// debug(d, psum[d - 1]);
	
			for (int k = psum[d - 1]; k <= 10; k++) ans[k] = max(ans[k], d);
// 			
			for (int i = 1; d - 1 + i + d < s.size(); i++){
				// debug(i, psum[d - 1 + i] - psum[i - 1]);
				for (int k = psum[d - 1 + i] - psum[i - 1]; k <= 10; k++) ans[k] = max(ans[k], d);
			}
		}
// 		
		// debug(vi(ans + 1, ans + 11));
		
		for (int i = 1; i <= n; i++) cout << ans[k[i]] << "\n";
	}
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen(file".inp", "r", stdin);
    // freopen(file".out", "w", stdout);
    cin >> n >> s;
    for (int i = 1; i <= n; i++) cin >> k[i];

    // if (s.size() <= 300)
        // sub1::solve();
    // else if (sub2::check())
        // sub2::solve();
    // else 	
    	sub3::solve();
    return 0;
}
/*
2
zabaaxy
0
1

2
zcaabcaaaa
0
1
*/