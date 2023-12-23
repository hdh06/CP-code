		#include <bits/stdc++.h>
		
		#ifdef LOCAL
		#include <debug.h>
		#else 
		#define debug(...) 111
		#endif
		
		using namespace std;
		
		int const N = 111;
		
		typedef long double ldb;
		
		int n;
		int arr[N][2];
		
		ldb dis(int a[], int b[]){
			return sqrt((a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]));
		}
		
		int Link[N];
		void DSUreset(){
			for (int i = 0; i < N; i++) Link[i] = i;
		}
		int find(int a){
			return Link[a] = (a == Link[a]? a: find(Link[a]));
		}
		bool unite(int a, int b){
			a = find(a), b = find(b);
			// debug(a, b);
			if (a == b) return false;
			Link[a] = b;
			return true;
		}
		
		bool f(ldb r){
			DSUreset();
			for (int i = 1; i <= n; i++){
				for (int j = i + 1; j <= n; j++)
					if (dis(arr[i], arr[j]) / 2.0L < r)
						unite(i, j);
				
				int tmp[2] = {arr[i][0], 100};
				if (dis(arr[i], tmp) / 2.0L < r)
					unite(0, i);
				tmp[1] = -100;
				if (dis(arr[i], tmp) / 2.0L < r)
					unite(n + 1, i);
			}
		
			return find(0) != find(n + 1);
		}
		
		int main(){
			cin >> n;
			for (int i = 1; i <= n; i++)
				cin >> arr[i][0] >> arr[i][1];
		
			ldb ans = 0, cnt = 0;
			for (ldb l = 1, r = 100; cnt <= 55; cnt++){
				ldb mid = (l + r) / 2.0L;
				if (f(mid)){
					ans = mid;
					l = mid;
				}else r = mid;
			}
			
			cout << setprecision(4) << fixed << ans << "\n";
			return 0;
		}