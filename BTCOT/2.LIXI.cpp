#include <bits/stdc++.h>

using namespace std;

bool comp(pair<int,int> p1, pair<int,int> p2){
    if (p1.second == p2.second){
        return p1.first > p2.first;
    }
    return p1.second > p2.second;
}

int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr.begin(),arr.end(), comp);
//    for (auto p: arr){
//        cout << p.first << " " << p.second << endl;
//    }
    int A = arr[0].first, B = arr[0].second;
    for (int i = 1; i < n; i++){
        if (B == 0){
            cout << A;
            return 0;
        }
        A += arr[i].first;
        B = B - 1 + arr[i].second;
    }
    cout << A;
    return 0;
}
    