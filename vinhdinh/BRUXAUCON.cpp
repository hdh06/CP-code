#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, m, k;
	cin >> n >> m >> k;
	string s;
	cin >> s;

	int dem = 0, dem_a = 0;
	for (int i = 0; i < s.size(); i++){
		dem_a = 0;
		for (int j = i; j > i - m + 1 && j >= 0; j--){
			if(s[j] == 'A') dem_a++;
			if(dem_a == k) dem++;
		}
	}	

	cout << dem;
	return 0;
}