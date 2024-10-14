#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main()
{
    faster;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    // nhập đề vô mảng a, 1 là đen, 0 là trắng
    vector < vector <int> > a(5, vector<int>(5));
    for (int i=0;i<4;i++){
        string s; cin>>s;
        for (int j=0;j<s.size();j++){
            if (s[j]=='#')
                a[i][j]=1;
            else
                a[i][j]=0;
        }
    }

    // kt xem tô được hình vuông 2x2 màu đen ko
    for (int i=0;i<3;i++){ // đi đến 3 thôi
        for (int j=0;j<3;j++){// vì hàng số 4 có 1 hàng ko tạo đc 2x2
            int dem=0;
            // kt ô a[i][j] và 3 ô xung quanh nó
            if (a[i][j]==1) dem++;
            if (a[i+1][j]==1) dem++;
            if (a[i][j+1]==1) dem++;
            if (a[i+1][j+1]==1) dem++;

            if (dem==3 or dem==4){//chỉ cần 3 ô màu đen là đủ, 4 càng tốt
                cout<<"YES";
                return 0;
            }
        }
    }

    // kt xem tô được hình vuông 2x2 màu đen ko
    // < y chang trên >
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            int dem=0;
            if (a[i][j]==0) dem++;
            if (a[i+1][j]==0) dem++;
            if (a[i][j+1]==0) dem++;
            if (a[i+1][j+1]==0) dem++;

            if (dem==3 or dem==4){
                cout<<"YES";
                return 0;
            }
        }
    }

    // nếu ko vẽ được hình vuông trắng hay đen nào
    cout<<"NO";
    return 0;
}
