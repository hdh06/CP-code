	#include <bits/stdc++.h>
	
	using namespace std;
	
	int const N = 22;
	
	int n;
	long long s;
	int arr[N];
	
	void emrua(int i, long long sum, string f){
		if (i == n){
			if (sum == s){
				cout << f << "\n";
				if (f[0] == '+') f.erase(0, 1);
			}
			return;
		}
		string tmp = f;
		tmp += '+', tmp += to_string(abs(arr[i]));
		emrua(i + 1, sum + (arr[i] < 0? -1 : 1) * arr[i], tmp);
		tmp = f;
		tmp += '-', tmp += to_string(abs(arr[i]));
		emrua(i + 1, sum + (arr[i] < 0? 1 : -1) * arr[i], tmp);
	}
	
	int main(){
		cin >> n >> s;
		for (int i = 0; i < n; i++)
			cin >> arr[i];
			
		string tmp = "";
		tmp += (arr[0] < 0? "-": "");
		tmp += to_string(abs(arr[0]));
			
		emrua(1, arr[0], tmp);	
		return 0;
	}