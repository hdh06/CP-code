#include <bits/stdc++.h>
#include <geodeb.h>

using namespace std;

typedef long long ll;

struct P{
	ll x, y;
};

ll cross(P A, P B){
	return A.x*B.y - A.y*B.x;
}

P vtc(P A, P B){
	return {B.x - A.x, B.y - A.y};
}

int tc(P A, P B, P C){
	P AB = vtc(A, B);
	P BC = vtc(B, C);
	ll crs = cross(AB, BC);
	if (crs == 0) return 0;
	if (crs < 0) return 1;
	if (crs > 0) return -1;
}

void draw(vector<P> a, int t){
	string atr;
	if (t == 1) atr = "blue bold";
	else atr = "blue bold";
	// GD_PAUSE();
	vector<P> st = a;
	GD_LAYER();
	// st.push_back(st[0]);
	for (int i = 1; i < st.size(); i++){
		// GD_PAUSE();
		GD_SEGMENT(st[i].x, st[i].y, st[i - 1].x, st[i - 1].y, atr);
	}
	GD_PAUSE();
}

int main(){
	freopen("inp.inp", "r", stdin); freopen("out.out", "w", stdout);
	GD_INIT("hull.html");
	int n;

	cin >> n;

	vector<P> arr(n);

	for (int i = 0; i < n; i++) cin >> arr[i].x >> arr[i].y;

	sort(arr.begin(), arr.end(), [](P A, P B){
		if (A.x == B.x) return A.y < B.y;
		return A.x < B.x;
	});

	for (int i = 0; i < n; i++){
		GD_POINT(arr[i].x, arr[i].y);
		if (i != 0) GD_SEGMENT(arr[i].x,arr[i].y, arr[0].x, arr[0].y , "rainbow");
	}
	// for (int i = 0; i < n; i++) cout << arr[i].x << " " << arr[i].y << endl;
	vector<P> st;	

	for (int t = 1; t <= 2; t++){
		int start = st.size();
		for (int i = 0; i < n; i++){
			draw(st, t);
			while (st.size() >= start + 2 && tc(st[st.size() - 2], st.back(), arr[i]) < 0){
				// GD_SEGMENT(st.back().x, st.back().y, st[st.size() - 2].x, st[st.size() - 2].y, "rainbow");
				st.pop_back();
				draw(st, t);
			}
			// if (st.size() > 0) GD_SEGMENT(st.back().x, st.back().y, arr[i].x, arr[i].y, "grey bold");
			st.push_back(arr[i]);

			draw(st, t);
		}
		st.pop_back();
		reverse(arr.begin(), arr.end());
	}
	cout << st.size() << endl;
	for (auto x: st) cout << x.x << " " << x.y << "\n";

		st.push_back(st[0]);
	for (int i = 1; i < st.size(); i++){
		// GD_PAUSE();
		GD_SEGMENT(st[i].x, st[i].y, st[i - 1].x, st[i - 1].y, "black bold");
	}
	GD_PAUSE();

GD_PAUSE();
GD_PAUSE();
GD_PAUSE();
GD_PAUSE();
GD_PAUSE();
GD_PAUSE();
GD_PAUSE();
GD_PAUSE();
GD_PAUSE();
GD_PAUSE();
	return 0;
}