#include <bits/stdc++.h>

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

int const N = 501;

int n, m;
ll k; 
int arr[N][N];

ll sum[N][N];

ll get(int a, int b, int c, int d){
	return sum[c][d] - sum[a - 1][d] - sum[c][b - 1] + sum[a - 1][b - 1];
}

namespace sub1{
	void sol(){
		ll ans = 0;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++){
				for (int g = i; g <= n; g++){
					for (int h = j; h <= m; h++){
						if (get(i, j, g, h) >= k * (g - i + 1) * (h - j + 1)){
							ans = max(ans, 1LL * (g - i + 1) * (h - j + 1));
						}
					}
				}
			}
		}
		cout << ans << "\n";
	}	
}

namespace sub2{
	void upd(int x, int k, vi &tree){
		for (int i = x; i < tree.size(); i += i & -i)
			tree[i] = min(tree[i], k);
	}
	int get(int x, vi &tree){
		int ans = INT_MAX;
		for (int i = x; i > 0; i -= i & -i)
			ans = min(ans, tree[i]);
		return ans;
	}
	
	void sol(){
		ll ans = 0;
		for (int i = 1; i <= n; i++){
			for (int j = i; j <= n; j++){
				vl a(m + 1);
				for (int z = 1; z <= m; z++)
					a[z] = a[z - 1] + ::get(i, z, j, z) - k * (j - i + 1);
				
				vl b = a;
				
				sort(all(b));
				b.erase(unique(all(b)), b.end());
				for (int z = 0; z <= m; z++)
					a[z] = lb(all(b), a[z]) - b.begin() + 1;
				
				vi tree(m + 5, INT_MAX);
				upd(a[0], 0, tree);
				
				for (int z = 1; z <= m; z++){
					ans = max(ans, 1LL * (z - get(a[z], tree)) * (j - i + 1));
					upd(a[z], z, tree);
				}
			}
		}
		cout << ans << "\n";
	}
}

namespace sub3{
	void sol(){
		ll ans = 0;
		for (int i = 1; i <= n; i++){
			for (int j = i; j <= n; j++){
				vl a(m + 1);
				for (int z = 1; z <= m; z++)
					a[z] = ::get(i, z, j, z) - k * (j - i + 1);
				debug(i, j, a);
				
				ll sum = 0;
				for (int l = 1, r = 0; r <= m;){
					if (sum < 0){
						sum -= a[l];
						l++;
					}else{
						ans = max(ans, 1LL * (r - l + 1) * (j - i + 1));
						r++;
						sum += a[r];
					}
				}
			}
		}
		cout << ans << "\n";
	}
}

void solve(){
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++){
			cin >> arr[i][j];
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + arr[i][j];
		}
	sub3::sol();
	// sub1::sol();
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