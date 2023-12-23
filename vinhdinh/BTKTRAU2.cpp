#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef array<int, 2> ii;

map<ll, vector<int> > A, B;
vector<ii> a, b;

ll S;

void dequy(int i, ll sum, map<ll, vector<int> > &m, vector<ii> arr, vector<int> p){
	if (sum > S) return;
	if (i == arr.size()){
		m[sum] = p;
		return;	
 	}

 	dequy(i + 1, sum, m , arr, p);
 	p.push_back(arr[i][1]);
 	dequy(i + 1, sum + arr[i][0], m, arr, p);
}

int main(){
	int n; cin >> n; cin >> S;
	for (int i = 1; i <= n; i++){
		int t; cin >> t;
		if (i & 1) a.push_back({t, i});
		else b.push_back({t, i});
	}

	dequy(0, 0, A, a, vector<int>());
	dequy(0, 0, B, b, vector<int>());

	for (auto x: A){
		if (B.find(S - x.first) != B.end()){
			auto y = B[S - x.first];
			cout << "YES\n";
			cout << x.second.size() + y.size() << endl;
			for (auto d: x.second) if (d != 0) cout << d << " ";
			for (auto d: y) if (d != 0) cout << d << " ";
			return 0;
		}
	}

	cout << "NO";

	return 0;
}