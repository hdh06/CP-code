#include <bits/stdc++.h>

using namespace std;

#define all(x) x.begin(),x.end()
#define inc(i,n) if (i != n - 1) i++;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(all(a), greater<int>());
    int k = 0, tong = 0;
    for(int i = 0; i < n; i++){
        tong += max(0,a[i] - k);
        k++;
    }
    cout << tong;
    return 0;
}
    