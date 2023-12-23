#include <bits/stdc++.h>

#include "combo.h"

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

string z = "ABXY";

string guess_sequence(int n){
	string p;
	for (auto x: z) if (press(x) == 1){
		p.pb(x);
		break;
	}
	for (int i = 0; i < n; i++){
		string temp;
		for (auto x: z){
			temp.pb()
		}
	}
	return p;
}