#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;

typedef long long ll;

struct P{
	int p;
	int c;
	int pos;
	ll maxc;
};

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, k;
	cin >> n >> k;

	P arr[N];

	for (int i = 1; i <= n; i++) cin >> arr[i].p;
	for (int i = 1; i <= n; i++) cin >> arr[i].c;
	for (int i = 1; i <= n; i++) arr[i].pos = i, arr[i].maxc = arr[i].c;	
	
	sort(arr + 1, arr + n + 1, [](P a, P b){
		return a.p < b.p;
	});

	multiset<int> m;
	for (int i = 1; i <= n; i++){
		// cout << "[" << arr[i].p << "]: ";
		while (m.size() > k) m.erase(m.begin());
		for (auto x: m){
			arr[i].maxc += x;
			// cout << x << " ";
		}
		m.insert(arr[i].c);
		// cout << endl;
	}

	sort(arr + 1, arr + n + 1, [](P a, P b){
		return a.pos < b.pos;
	});

	for (int i = 1; i <= n; i++) cout << arr[i].maxc << " ";

	return 0;
}