#include <bits/stdc++.h>

using namespace std;

template<class A, class B> bool maximize(A& x, B y) {if (x < y) return x = y, true; else return false;}
template<class A, class B> bool minimize(A& x, B y) {if (x > y) return x = y, true; else return false;}

#define     all(a)                a.begin(), a.end()
#define     pb                    push_back
#define     pf                    push_front
#define     fi                    first
#define     se                    second
// #define     int                   long long

typedef     long long             ll;
typedef     unsigned long long    ull;
typedef     double                db;
typedef     long double           ld;
typedef     pair<db, db>          pdb;
typedef     pair<ld, ld>          pld;
typedef     pair<int, int>        pii;
typedef     pair<ll, ll>          pll;
typedef     pair<ll, int>         plli;
typedef     pair<int, ll>         pill;

const int MAX_N = 2e5 + 5;

int n;
vector<int> adj[MAX_N];
string s;
int numNode;
stack<int> st;
int f[MAX_N], g[MAX_N];

void dfs(int u) {
    vector<int> tmp;
    for (int v : adj[u]) {
        dfs(v);
        tmp.pb(f[v]);
    }

    if (tmp.empty()) {
        f[u] = 1;
        return;
    }

    reverse(all(tmp));   
    for (int i = 0; i < (int) tmp.size(); i++) {
        maximize(f[u], tmp[i] + i);
    }
    for (int i = 1; i < (int) tmp.size(); i++) {
        int mx = 0;
        for (int j = i; j < (int) tmp.size(); j++) {
            maximize(mx, tmp[j] + j - i);
        }
        for (int j = i - 1; ~j; j--) {
            maximize(mx, tmp[j] + (int) tmp.size() - (i - j));
        }
        if (minimize(f[u], mx)) {
            g[u] = i;
        }
    }
}

void dfs2(int u) {
    vector<int> tmp;
    for (int v : adj[u]) {
        tmp.pb(v);
    }

    if (tmp.empty()) {
        cout << 'a';
        return;
    }

    reverse(all(tmp));
    for (int i = g[u]; i < (int) tmp.size(); i++) {
        dfs2(tmp[i]);
    }
    for (int i = 0; i < g[u]; i++) {
        dfs2(tmp[i]);
    }
    cout << tmp.size();
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("f.inp", "r", stdin);
    freopen("f.ans", "w", stdout);

    cin >> s;
    for (int i = 0; i < (int) s.size(); i++) {
        if (s[i] == 'a') {
            numNode++;
            st.push(numNode);
        }
        else {
            int x = s[i] - '0';
            numNode++;
            while (x) {
                x--;
                adj[numNode].pb(st.top());
                st.pop();
            }
            st.push(numNode);
        }
    }

    dfs(numNode);

    cout << f[numNode] << '\n';
    // dfs2(numNode);

    return 0;
}

/*


Wednesday, 08 November 2023
21:14:28
*/