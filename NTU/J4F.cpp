#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rd); }

ll seed = LLONG_MAX - 1;
// int seed = INT_MAX - 1;

// int rand(int l, int r){
// 	return rand() % (l - r + 1) + l;
// }

int main(){
	srand(time(NULL));
	cout << (rand(1, seed) < seed/rand(1, seed)? "you are the loser" : "you are the winner");
	return 0;
}