#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, m;
	cin >> n >> m;

	vector<int> a(n), b(m);

	for (auto &x: a) cin >> x; for (auto &x: b) cin >> x;

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());


	for (int i = 0; i < n; i++){
		if (a[i] <= b[i]){
			cout << "NO";
			return 0;
		}
	}	

	cout << "YES";
	return 0;
}