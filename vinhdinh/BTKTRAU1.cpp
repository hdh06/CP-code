#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int const N = 33;

vector<ll> a, b;
map<ll, bool> A, B;

ll sum;

bool dequy(int i, ll s, map<ll, bool> &m, vector<ll> arr){
	if (s > sum) return false;
	if (i == arr.size()) return m[s] = true;
	return dequy(i + 1, s + arr[i], m, arr) | dequy(i + 1, s, m, arr);
}

int main(){
	int n;
	cin >> n >> sum;	

	for (int i = 1; i <= n; i++){
		int t; cin >> t;
		if (i & 1) a.push_back(t);
		else b.push_back(t);
 	}

 	dequy(0, 0ll, A, a);
 	dequy(0, 0ll, B, b);

 	for (auto x: A){
 		if (B[sum - x.first]){
 			cout << "YES";
 			return 0;
 		}
 	}

 	cout << "NO";
	return 0;
}