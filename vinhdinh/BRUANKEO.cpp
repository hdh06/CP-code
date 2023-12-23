#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;

	vector<int> fre(10000, 0);

	for (int i = 1; i <= n; i++){
		int temp; cin >> temp;
		fre[temp]++;
	}	

	int ans = 0;

	for (int i = 1; i <= n; i++){
		while (fre[i] > 1){
			for (int j = i + 1; true; j++){
				if (fre[j] == 0){
					fre[j]++;
					ans += j - i;
					break;
				}
			}
			fre[i]--;
		}
	}

	cout << ans;
	return 0;
}