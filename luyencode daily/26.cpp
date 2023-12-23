#include <bits/stdc++.h>

using namespace std;

int calc(vector<int> arr){
	int n = arr.size();
	set<int> ms;

	int ans = 0;
	for (int i = 0, L = 0; i < n; i++){
		if (ms.find(arr[i]) == ms.end()){
			ms.insert(arr[i]);
			ans = max(ans, i - L + 1);
		}
		else{ 
			while(arr[L] != arr[i]) ms.erase(arr[L++]);
			L++;
		}
	}
	return ans;
}

int main(){
	cout << calc({5, 1, 3, 5, 2, 3, 4, 1});
	return 0;
}