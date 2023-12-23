#include "bits/stdc++.h"
using namespace std;

#define ll long long int

struct Edges{
    ll v;
    ll fl;
    ll cap;
    ll rev;
};

class Maximum_Flow{
public:
    ll V;
    static vector<Edges> *adj;
    ll *level;
    vector<pair<ll,ll> > a, b;
    vector<bool> ck;
public:
    Maximum_Flow(ll V){
        adj = new vector<Edges>[V];
        ck = vector<bool> (V + 1, 0);
        this->V = V;
        level = new ll[V];
    }

    void addEdges(ll u,ll v,ll capa){
        Edges a{v, 0, capa, (ll)adj[v].size()};

        Edges b{u, 0, 0, (ll)adj[u].size()};

        adj[u].push_back(a);
        adj[v].push_back(b);
    }
    bool BFS(ll s, ll e);
    ll DFS(ll s, ll e, ll flow,ll save[]);
    ll DinicAl(ll s, ll e);
    void DFS2(ll s, ll e);
};

bool Maximum_Flow::BFS(ll s, ll e){
    for (ll i = 0 ; i < V ; i++)
		level[i] = -1;

    level[s] = 0;
    queue<ll> q;
    q.push(s);

    while(!q.empty()){
        ll u = q.front();
        q.pop();

        for(Edges v: adj[u]){
            if(level[v.v] < 0 && v.fl < v.cap){
                level[v.v] = level[u] + 1;

                q.push(v.v);
            }
        }
    }
    return level[e] < 0 ? 0 : 1;
}

ll Maximum_Flow::DFS(ll s, ll e, ll flow,ll save[]){

    if(s == e){
        return flow;
    }
    for(;save[s] < adj[s].size();save[s]++){
        Edges &v = adj[s][save[s]];
        if(level[v.v] == level[s] + 1 && v.fl < v.cap){
            ll tmp = DFS(v.v, e, min(flow, v.cap - v.fl), save);
            if(tmp > 0){
                v.fl += tmp;

                adj[v.v][v.rev].fl -= tmp;
                return tmp;
            }
        }
    }

    return 0;
}

ll Maximum_Flow::DinicAl(ll s, ll e){
    if(s == e)return -1;
    ll sum = 0;

    while(BFS(s, e)){
        ll *save = new ll[V + 1] {};
        while(ll tmp = DFS(s, e, LLONG_MAX,save)){

            sum += tmp;
        }
    }
    return sum;
}
void Maximum_Flow::DFS2(ll s, ll e){
     if(ck[s])return;
     ck[s] = true;
     if(s == e){
        return;
    }

    for(ll i = 0;i < adj[s].size();i++){
        if(adj[s][i].fl > 0){
            if(s < adj[s][i].v)
            cout << "[" << s << "] [" << i << "]" << adj[s][i].fl << ' ' << s << ' ' << adj[s][i].v << endl, b.push_back({s, adj[s][i].v});
        }
        else if(adj[s][i].fl == 0){
            if(s < adj[s][i].v)
            cout << adj[s][i].fl << ' ' << s << ' ' << adj[s][i].v << endl,a.push_back({s, adj[s][i].v});
        }
        DFS2(adj[s][i].v, e);
    }

    return;
}
int main(){
    ll n, m;
    cin >> n >> m;

    Maximum_Flow g(n + 1);
    for(ll i = 0;i < m;i++){
        ll a, b;
        cin >> a >> b;
        if(a != b){
            g.addEdges(a, b, 1);
            g.addEdges(b, a, 1);
        }
    }
    cout << g.DinicAl(1, n) << endl;
    g.DFS2(1, n);

    vector<pair<ll,ll> >  a = g.a, b = g.b;
    cout << endl;
    for(ll i = 0; i < a.size();i++){
            cout << a[i].first << ' ' << a[i].second << ' ' << 1 << endl;
        for(ll j = 0;j < b.size();j++){
if(a[i].second == b[j].first){
                cout << b[j].first << ' ' << b[j].second << endl;
            }
            if(a[i].first == b[j].second){
                cout << b[j].first << ' ' << b[j].second << endl;
            }
        }
    }
    return 0;
    static_cast<>
}
