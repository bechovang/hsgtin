#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main()
{
    faster;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n; cin>>n;

    vector <double>a(n+1); //mảng lưu đề
    vector <int>le(n+1); // mảng lưu tính lẻ của các số trong đề

    int tg=0;
    for (int i=0;i<n;i++){
        cin>>a[i];
        if (a[i]/2 != floor(a[i]/2)) // kt xem a[i] có là số lẻ ko
            le[i]=1;

        a[i]=floor(a[i]/2); // cập nhật a[i]: làm tròn xuống của a[i]/2
        tg=tg+a[i]; //mảng tính tổng mảng mới cập nhật ( mảng a[i]/2)
    }


    // * đề yêu cầu tổng mảng mới phải = 0
    // * số lẻ được quyền làm tròn lên hoặc xuống

    // Vì mảng mới là a[i]/2 được làm tròn xuống
    // nên tg luôn < 0. vì làm tròn xuống thì luôn lấy số bé hơn
    // => nếu tg<0 và a[i] là số lẻ
    //      -> in ra a[i]+1 <=> làm tròn lên
    // => nếu ko phải thì in ra bth
    //      -> ( vì số chẵn / 2 thì ko có làm tròn)
    //      -> ( nếu tg đã đủ rồi thì thôi)

    for (int i=0;i<n;i++){
        if (tg<0 and le[i]==1){
            cout<<a[i]+1<<endl;
            tg++;
        }
        else
            cout<<a[i]<<endl;
    }


    return 0;
}
