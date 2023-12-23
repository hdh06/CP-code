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

int const N = 2e6 + 1;
int n;
int arr[N];

void solve(){
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	
	deque<int> qmin, qmax;
	multiset<pair<int, int> > ms; 
	
	ms.insert({n + 1, 1});
	
	ll ans = 0;
	int curr = n;
	for (int i = 1; i <= n; i++){
		while (!qmin.empty() && arr[qmin.back()] > arr[i]){
			int x = qmin.back();
			
			auto it = ms.find({x, 0});
			auto tmp = it;
			it++;
			if (tmp == ms.begin()){
				if (it -> nd) curr -= it -> st - 1;	
			}else{
				tmp--;
				if (tmp -> nd) curr -= it -> st - x;
			}
			// debug("-", curr, x);
			
			
			ms.erase({x, 0});
			qmin.pob();
		}
		while (!qmax.empty() && arr[qmax.back()] < arr[i]){
			int x = qmax.back();
			
			auto it = ms.find({x, 1});
			auto tmp = it;
			it++;
			if (tmp == ms.begin()){
				if (!it -> nd) curr += it -> st - 1;	
			}else{
				tmp--;
				if (!tmp -> nd) curr += it -> st - x;
			}
			// debug("+", curr, x);
		
			
			ms.erase({x, 1});
			qmax.pob();
		}
		
		qmin.pb(i);
		qmax.pb(i);
		
		ms.insert({i, 0});	
		ms.insert({i, 1});
		{
			auto it = ms.find({i, 0});
			if (ms.size() > 3){
				it--;
				if (it -> nd) curr += n - i + 1;
			}
		}

		curr -= n - i + 1;		
		
		debug(curr, ms);
		ans += curr;
	}
	
	cout << ans << "\n";
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