#include <bits/stdc++.h>

using namespace std;

int m = 3;

int f(int n, vector<int> z){
	if (n == 0) return 0;
	int ans = 0;
	vector<int> c;
	if (z.size()){
		vector<int> v = z;
		v.back() ++ ;
		if (v.back() == m) v.pop_back();
		c.push_back(f(n - 1, v));
	}
	
	if (n >= 2){	
		vector<int> v = z;
		v.push_back(2);
		c.push_back(f(n - 2, v));
	}
	sort(c.begin(), c.end());
	for (auto x: c) if (x == ans) ans++;
	return ans;
}

int main(){
	
	for (int n = 1; n <= 20; n++)
		cerr << n << " " << (f(n, vector<int>(0))? 'A': 'B') << "\n";
	return 0;
}