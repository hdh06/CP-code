#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cout.tie(NULL); cin.tie(NULL);
    int n, l = 0, r;
    cin >> n;
    r = n;
    deque<ll> a; ll sum = 0;
    for(int i = 0;i < n;i++){
        ll c;
        cin >> c;
        a.push_back(c);
    }

    while(!a.empty()){
        ll mx;
        if(a.size() % 2 != 0){
            mx = *min_element(a.begin(), a.end());
            for(int i = 0;i < a.size();i++){
                if(a[i] == mx){
                    cout << (i - 0) << endl;
                    a.erase(a.begin() + i);
                    break;
                }
            }
        }
        else{
            mx = *max_element(a.begin(), a.end());
            for(int i = a.size() - 1;i >= 0;i--){
                if(a[i] == mx){
                    cout << (a.size() - i - 1) << endl;

                    a.erase(a.begin() + i);
                    break;
                }
            }
        }
    }

    return 0;
}