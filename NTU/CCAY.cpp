#include <bits/stdc++.h>

using namespace std;

int const N = 2e4 + 1;

int link[N] = {};

int find(int x){
	while (link[x] != x) x = link[x];
	return x;
}

void join(int a, int b){
	int c = find(a);
	int d = find(b);

	if (c != d) link[b] = a;
}

void disjoin(int a){
	link[a] = a;	
}

bool same(int a, int b){
	return find(a) == find(b);
}

int main(){
	int t;
	cin >> t;
	for (int test = 1; test <= t; test++){
		int n, q;
		cin >> n >> q;

		for (int i = 1; i <= n; i++){
			int temp;
			cin >> temp;
			link[i] = temp;
			if (temp == 0) link[i] = i;
		}

		cout << "Case #" << test << ":" << endl;

		while(q--){
			char c;
			cin >> c;
			if (c == 'Q'){
				int a, b;
				cin >> a >> b;
				cout << (same(a, b)?"YES":"NO") << endl;
			}
			if (c == 'C'){
				int x;
				cin >> x;
				disjoin(x);
			}
		}
	}
	return 0;
	
}