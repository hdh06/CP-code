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
int main(){
	ios_base::sync_with_stdio(0);//      the
	cin.tie(0);cout.tie(0);// 	    magical lines	
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);
	
	system("g++ -std=c++17 gen.cpp -o g");
	system("g++ -std=c++17 DISNUMBER.cpp -o s");
	system("g++ -std=c++17 testtt.cpp -o b");
	
	for (int i = 1; i <= 100; i++){
		cerr << "test " << i << ": ";
		system("./g");
		system("./s");
		system("./b");
		
		if (system("diff -w 2.out 2.ans")){
			cerr << "WA\n";
			return 0;
		}else cerr << "AC\n";
	}
	return 0;
}//it's coding time!