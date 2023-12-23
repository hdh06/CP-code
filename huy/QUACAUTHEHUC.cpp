#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n,t = 0;
    // biến c này để cho nó chạy luân phiên theo quy tắc mà t nói nãy á
    bool c = 1;
    cin >> n;
    vector<int> a(n),b;
    for(int i = 0;i<n;i++)cin >> a[i];
    for(;a.size()!=0;){
        // sắp xếp lại mảng để luôn đảm bảo phần tử lớn nhất và nhỏ nhất
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        //Nếu mảng chỉ còn 2 phần tử trở xuống thì cho nó vào bên kia thế giới
        if(a.size()<=2){
            t+=max(a[0],(a.size()==1?0:a[1]));
            break;
        }

        if(c){
            // Nè nha nếu mà mảng chỉ còn lại 3 phần tử thì sẽ còn đúng 1 lần cho chạy phẩn tử nữa đúng không nên
            // t cho cái phần tử thứ 2 nó thăng thiên sang bên kia thế giới luôn bởi nếu cho ở lại thì nó sẽ làm tăngnữa
            // thêm 1 lần phần tử nhỏ thứ 2
            // thêm nữa là t sẽ kick phần tử nhỏ nhất sang bên kia thế giới giữ lại p tử thứ 2=> giảm thời gian quay lại ở
            // lần chạy sau
            if(a.size()>3){
                // chỗ t nói đây
                t+=(a[1]*2);
                b.push_back(a[0]);
                a.erase(a.begin());
            }
            else{
                // cái này để giảm thời gian qua 1 xí
                t+=(a[0]+a[1]);
                b.push_back(a[1]);
                a.erase(a.begin()+1);
            }
            c = 0;
        }
        else{
            // ở phần này á là nó nằm ở lượt chạy chẵn tức là nó cho 2 phần tử lớn nhất thăng thiên và kéo thằng phần tử nhỏ nhất
            // vừa bị tiễn sang bên kia thế giơi ở lượt chạy trước
            // code này tưc là t đẩy từ a sang b và xóa phần từ vừa đẩy ở trong a
            t+=(a[a.size()-1]+b[0]);
            b.push_back(a[a.size()-1]);
            b.push_back(a[a.size()-2]);
            a.erase(a.end()-1);
            a.erase(a.end()-1);
            a.push_back(b[0]);
            b.erase(b.begin());
            c = 1;
        }
        /*for(int i = 0;i<a.size();i++){
            cout << a[i] << ' ';
        }
        cout << endl;
*/
    }
    cout << t;
    return 0;