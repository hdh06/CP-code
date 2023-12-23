#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n; 

	vector<int> ans;
	int dem = 0;

	while(n--){
		int temp;
		cin >> temp;
		if (temp % 2 == 0) dem++, ans.push_back(temp);
	}	

	cout << dem << endl;
	for (auto i: ans) cout << i << " ";
	return 0;
}