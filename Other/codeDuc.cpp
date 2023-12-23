#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n,tmp;
        cin >> n;
        ll a[n],mx = 0;
        unordered_map<ll,ll> c;
        vector<pair<int,int>> p;
        tmp = 1;
        for(int i = 0;i<n;i++){
            cin >> a[i];
            if(c.count(a[i]==0)){
                c.insert({a[i],0});
            }
            else{
                c[a[i]]++;
                if(c[a[i]]==2){
                    p.push_back({tmp,i+1});
                    tmp = i+2;
                    c.clear();
                }
            }
        }
        if(p.size()==0){
            cout << -1 << endl;
        }
        else{
            if(p[p.size()-1].second!=n){
                p[p.size()-1].second=n;
            }
            for(int i = 0;i<p.size();i++){
                cout << p[i].first << ' ' << p[i].second << endl;
            }
        }

    }
    return 0;
}