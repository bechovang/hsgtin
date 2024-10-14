//bechovang
#include <bits/stdc++.h>
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
struct deal{
    int s;
    int e;
    int c;
};

bool compare(deal s1, deal s2){
    if (s1.e < s2.e)
        return true;
    if (s1.e == s2.e){
        if (s1.s < s2.s)
            return true;
    }

    return false;
}

bool trunglich(deal a,deal b ){ // hơi dài dòng, dùng lợi thế từ sort => a[j].e <= a[i].s vẫn ok hơn
    if (a.s > b.s and a.s < b.e)
        return true;
    if (a.e > b.s and a.e < b.e)
        return true;
    if (b.s > a.s and b.s < a.e)
        return true;
    if (b.e > a.s and b.e < a.e)
        return true;
    // sửa cái test:
//        2
//    0 1 1
//    0 1 2
    if (a.s == b.s and a.e == b.e)
        return true;

    return false;
}

int main()
{
    faster;
    freopen("STADIUM.INP","r",stdin);
    freopen("STADIUM.OUT","w",stdout);
    // xếp theo tăng dần của thời gian start và end
    // rồi làm như bài tìm dãy tăng dần dài nhất

    int n; cin>>n;
    vector<deal> a;
    for (int i=0;i<n;i++){
        int x,y,z; cin>>x>>y>>z;
        deal e;
        e.s=x;
        e.e=y;
        e.c=z;
        a.push_back(e);
    }

    sort(a.begin(), a.end(), compare);


//     - thuật toán quy hoạch động thể hiện ở chỗ đó là mình dùng một
//    mảng, trong đó Memo[i] để lưu lại số tiến lớn nhất thu được
//    khi chỉ chọn các đơn hàng từ 1 đến i. Như vậy rõ ràng kết quả
//    cần tìm là Memo[N].
//
//    - Trường hợp cơ sở ở đây là Memo[i] = Price[i] - tức là
//    chỉ chọn 1 đơn hàng thứ i.
//
//    - Ta có công thức quy hoạch động là
//    Memo[i] = Max{ Memo[i], Memo[i - 1], Price[i] + Memo[k]}
//
//    - Trong đó: Memo[i - 1] ứng với trường hợp
//    không chọn đơn hàng thứ i; Price[i] + Memo[k]
//    ứng với trường hợp chọn đơn hàng thứ i, và k là
//    số lớn nhất thỏa mãn thời gian kết thúc tại k < thời
//    gian bắt đầu tại i - đảm bảo thời gian không bị chồng lên nhau.

    int dp[n];
    for (int i=0;i<n;i++){
        dp[i]=a[i].c;
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<i;j++){
            //if (a[j].e <= a[i].s){ // vi thoi gian da duoc sap xep, nên nó sẽ ra cái hình như VNOI => a[j].e <= a[i].s thì nó ko trùng
            if (trunglich(a[i],a[j])==false){
                dp[i]= max(dp[i], dp[j] + a[i].c);
            }
        }
    }



//    //debug
//    for (auto x: a){
//        cout<<x.s<<' '<<x.e<<' '<<x.c<<endl;
//    }
//    cout<<endl;
//    for (auto x: dp){
//        cout<<x<<' ';
//    }
//    cout<<endl;


    int kq=-1;
    for (auto x: dp){
        kq=max(kq,x);
    }

    cout<<kq;

    return 0;
}
