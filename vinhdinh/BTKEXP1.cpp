#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; long long S; cin >> n >> S;
	int arr[23]; for (int i = 1; i <= n; i++) cin >> arr[i];
	long long tong = 0;

	vector<string> res;
	for (int b = 0; b <= (1 << (n - 1)) - 1; b++){
		tong = arr[1];
		for (int i = 2, dem = n - 2; i <= n; i++, dem--){
			if (b & (1 << dem)) tong += arr[i];
			else tong -= arr[i];
		}
		string ans;
		if (tong == S){
			// cout << b << " ";
			if (arr[1] < 0) ans.push_back('-');
			ans = ans + to_string(abs(arr[1]));
			for (int i = n - 2, j = 2; j <= n && i >= 0; i--, j++){
				if (b & (1 << i)) ans.push_back(arr[j] < 0?'-':'+');
				else ans.push_back(arr[j] < 0?'+':'-'); 
				ans = ans + to_string(abs(arr[j]));
			}
			res.push_back(ans);
		}
	}	

	sort(res.begin(), res.end());

	for (auto x: res) cout << x << "\n"; 
	return 0;
}