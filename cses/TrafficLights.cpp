#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int x, n; cin >> x >> n;

	multiset<array<int, 2> > segm;
	multiset<int> len;
	segm.insert({x, 0});	
	len.insert(x - 0);

	while (n--){
		int p; cin >> p;
		array<int, 2> sg = *segm.lower_bound({p, 0});
		segm.erase(sg);
		swap(sg[0], sg[1]);
		len.erase(len.find(sg[1] - sg[0]));

		segm.insert({p, sg[0]});
		segm.insert({sg[1], p});
		len.insert(p - sg[0]);
		len.insert(sg[1] - p);
		cout << *len.rbegin() << " ";
	}
	return 0;
}