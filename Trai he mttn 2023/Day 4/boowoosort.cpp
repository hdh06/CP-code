#include <bits/stdc++.h>

using namespace std;

int const N = 1e5 + 1;

//tat ca deu quay sang phai luc bat dau

int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		vector<int> a, b;
		for (int i = 1; i <= n; i++){
			int x; cin >> x;
			if (i & 1) a.push_back(x);
			else b.push_back(x);
		}
			
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		
		vector<int> c;
		for (int i = 0, j = 0;j < b.size();i++, j++){
			c.push_back(a[i]);
			c.push_back(b[j]);
		}
		if (n & 1) c.push_back(a.back());
	
		bool flag = 1;
		for (int i = 1; i < c.size(); i++) if (c[i - 1] > c[i]) flag = 0;
		cout << (flag? "YES\n": "NO\n");
	}
	return 0;
}