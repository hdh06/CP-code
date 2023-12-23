#include <bits/stdc++.h>

using namespace std;

int const N = 2*1e5 + 5;


int main(){
	int n, m;
	cin >> n >> m;

	multiset<int> tick;
	for (int i = 1; i <= n; i++){
		int temp;
		cin >> temp;
		tick.insert(temp);
	}

	tick.insert(INT_MAX);

	while(m --){
		int t;
		cin >> t;
		auto pos = tick.upper_bound(t);
		if (pos == tick.begin()){
			cout << -1 << endl;
		}
		else{
			cout << *(--pos) << endl;
			tick.erase(pos);
		}
	}

	return 0;
}