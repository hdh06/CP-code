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

int ask(int a, int b){
	cout << "? " << a << " " << b << endl;
	int x; cin >> x;
	return x;
}

int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		int a = 1, b = 2;
		for (int c = 3; c <= n; c++){
			int l = ask(a, c), r = ask(b, c);
			if (l > r)
				b = c;
			if (l < r) 
				a = c;
		}
		cout << "! " << a << " " << b << endl;
		int x; cin >> x;
		if (x == -1)
			return 0;
	}
	return 0;
}//it's coding time!