#include <bits/stdc++.h>

#ifdef LOCAL
#include <debug.h>
#else
#define debug(...) 1171
#endif
	
#define int long long
//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
/*   /\_/\
    (= ._.)
    / >?  \>$
*/
using namespace std;
const int MOD = 1e9 + 19972207;

int a[4][4] = {{1, 1, 1, 0},
               {1, 0, 0, 0},
               {1, 0, 0, 1},
               {1, 0, 0, 0}};

int c[4][4] = {{1, 1, 1, 0},
               {1, 0, 0, 0},
               {1, 0, 0, 1},
               {1, 0, 0, 0}};

void mul(int b[4][4]){
    int t[4][4] = {};

    for(int i = 0; i < 4; i++)
        for(int j = 0 ; j < 4; j++)
            for(int k = 0; k < 4; k++)
                (t[i][j] += a[i][k] * b[k][j] % MOD) %= MOD;

    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            a[i][j] = t[i][j];
}

void power(int n){	
    if (n < 2) return;
    power(n >> 1);
    mul(a);
    if(n & 1LL) mul(c);
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n; cin >> n;

    power(n);

    cout << a[0][0] % MOD;
}