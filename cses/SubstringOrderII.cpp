#include <bits/stdc++.h>

// #pragma GCC optimize ("Ofast")
// #pragma GCC target ("avx2")

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

#define all(x) x.begin(), x.end()
#define st first
#define nd second

vi sfac(string s){
	s += '$';
	int n = s.size();
	
	vi p(n), c(n), pn(n), cn(n), cnt(max(256, n));
	for (auto x: s) cnt[x]++;
	for (int i = 1; i < 256; i++)
		cnt[i] += cnt[i - 1];
	for (int i = 0; i < n; i++)
		p[--cnt[s[i]]] = i;
	c[p[0]] = 0;
	for (int i = 1; i < n; i++)
		c[p[i]] = c[p[i - 1]] + (s[p[i]] != s[p[i - 1]]);
	
	for (int k = 0; (1 << k) < n; k++){
		for (int i = 0; i < n; i++)
			pn[i] = (p[i] - (1 << k) + n) % n;
		fill(all(cnt), 0);
		for (int i = 0; i < n; i++)
			cnt[c[pn[i]]]++;
		for (int i = 1; i < n; i++)
			cnt[i] += cnt[i - 1];
		for (int i = n - 1; i >= 0; i--)
			p[--cnt[c[pn[i]]]] = pn[i];
		cn[p[0]] = 0;
		for (int i = 1; i < n; i++)
			cn[p[i]] = cn[p[i - 1]]
			+( ii(c[p[i]], c[(p[i] + (1 << k)) % n])
			!= ii(c[p[i - 1]], c[(p[i - 1] + (1 << k)) % n])
			);
		c.swap(cn);
	}
	return vi(1 + all(p));
}

int main(){
	ios_base::sync_with_stdio(0); // the
	cin.tie(nullptr);			  // magical
	cout.tie(nullptr);			  // lines
	string s; cin >> s;
	ll k; cin >> k;
	vi sfa = sfac(s);
	int n = s.size();
	
	vi rank(n);
	for (int i = 0; i < n; i++)
		rank[sfa[i]] = i;
	
	int z = 0;
	vi lcp(n);
	for (int i = 0; i < n; i++){
		if (rank[i] == n - 1) continue;
		int j = sfa[rank[i] + 1];
		while (i + z < n && j + z < n && s[i + z] == s[j + z])
			z++;
		lcp[rank[i]] = z;
		if (z) z--; 
	}
	
	
	stack<int> que;
	vector<vector<int> > v(n);
	int sum = 0;
	for (int i = 0, pre = 0; i < n; i++){
		if (pre < lcp[i]){
			for (int j = pre + 1; j <= lcp[i]; j++)
				que.push(i);
			// v[i].resize(lcp[i] - pre - 1);
			sum += max(0, lcp[i] - pre);
		}else if (pre > lcp[i]){
			for (int j = pre; j > lcp[i]; j--){
				v[que.top()].push_back(i - que.top() + 1);
				que.pop();
			}
		}
		pre = lcp[i];
	}
	
	for (int i = 0, pre = 0; i < n; i++){
		bool flag = 0;
		for (int j = pre + 1; j <= lcp[i]; j++){
			if (k >= v[i][j - pre - 1]){
				k -= v[i][j - pre - 1];
				if (k == 0){
					cout << s.substr(sfa[i], j);
					flag = 1;
					break;
				}
			}
			else{
				cout << s.substr(sfa[i], j);
				flag = 1;
				break;
			}
		}
		
		if (flag) break;
		if (k >= n - sfa[i] - max(lcp[i], pre))
			k -= n - sfa[i] - max(lcp[i], pre);
		else{
			cout << s.substr(sfa[i], max(lcp[i], pre) + k);
			break;
		}
		pre = lcp[i];
	}
	
	cerr << n << " " << sum;
	return 0;
}