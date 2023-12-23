#include <bits/stdc++.h>

using namespace std;

#define file "MATHIEU"

int const N = 100100;

int main(){
	freopen(file".inp", "r", stdin); freopen(file".out", "w", stdout);
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	bool hash[N] = {};
	string s;
	cin >> s;
	s = '#' + s;
	int n;
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++){
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	int mid = s.length() / 2 + 1;

	int cur = arr[0], dem;
	hash[cur] = 1;
	for (int i = 1; i < n; i++){
		if (arr[i] != cur){
			hash[arr[i]] = (hash[arr[i]] + hash[cur] + 1) % 2;
			if (hash[cur] == 1){
				for (int x = cur; x < arr[i]; x++){
					swap(s[x], s[s.length() - 1 - x + 1]);
				}
			} 
			cur = arr[i];
		}
		else{
			hash[cur] = (hash[cur] + 1) % 2;
		}
	}
	if (hash[cur] == 1){
		for (int x = cur; x < mid; x++){
			swap(s[x], s[s.length() - 1 - x + 1]);
		}
	} 
	s.erase(0,1);
	cout << s;
	return 0;
}