#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vector<int> arr(n);
	ll fre[10001] = {}, fsum[10001] = {}, curr = 0;

	for (auto &x: arr){
		cin >> x;
		fre[x]++;
	}

	sort(arr.begin(), arr.end());

	for (int i = 1; i < 10001; i++) fsum[i] = fsum[i - 1] + fre[i];
	// for (auto x: arr) cout << x << " "; cout << endl;
	// for (int i = 1; i < 16; i++) cout << i << " \n"[i == 15];
	// for (int i = 1; i < 16; i++) cout << fre[i] << " \n"[i == 15];
	// for (int i = 1; i < 16; i++) cout << fsum[i] << " \n"[i == 15];	

	ll tu = 0, nhon = 0, vg = 0, curri = 0;

	for (int i = 0; i < n; i++){
		if (i == 0) curri = 1;
		else{
			if (arr[i] != arr[i - 1]) curri = 1;
			else curri++;
		}
		for (int j = i + 1; j < n; j++){
			int b = arr[i], c = arr[j];
			if (j == i + 1) curr = (arr[j] == arr[i]?curri + 1: 1);
			else{
				if (arr[j] != arr[j - 1]) curr = 1;
				else curr ++;
			}
			int a = sqrt(b*b + c*c);
			bool f = (a*a == b*b + c*c);
			if (f) vg += fre[a];

			tu += fsum[b + c - 1] - fsum[a];

			nhon += fsum[(f?a - 1:a)] - fsum[c] +(fre[c] - curr); 
		}
	}
	cout << nhon << " " << vg << " " << tu;
	return 0;
}