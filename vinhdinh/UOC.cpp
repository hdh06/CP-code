#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;

	cout << "Cac uoc so cua " << n << endl;

	vector<int> ans;

	for (int i = 1; i <= sqrt(n); i++){
		if (n % i == 0) ans.push_back(i), ans.push_back(n / i);
	}	

	sort(ans.begin(), ans.end());

	for (auto i: ans) cout << i << endl;
	return 0;
}