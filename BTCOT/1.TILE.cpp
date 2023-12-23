#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr.begin(),arr.end(), greater<int>());
    int T = arr[0];
    int i = 1;
    for (; i < n; i++){
        if (T == 0){
            cout << i;
            return 0;
        }
        T = min(T - 1, arr[i]);
    }
    cout << i;
    return 0;
}
    