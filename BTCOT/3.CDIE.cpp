#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> arr(n,0);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr.begin(),arr.end(), greater<int>());
    int cur = 1, i = 0;
    while(i - 1 < n && m != 0){
        if (m <= cur){
            m = 0;
        }
        else{
            m -= cur - 1;
            cur = arr[i];
            i++;
        }
    }
    if (m != 0) cout << -1;
    else cout << i;
    return 0;
}
    