#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main()
{
    faster;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n; cin>>n;
    int day=n; // cái bánh cần xếp ở đáy. là cái to nhất chưa được xếp (xuất hiện)
    int a[100001]={}; // đánh dấu bánh đã xuất hiện chưa
    for(int o=0;o<n;o++){
        int x; cin>>x;
        a[x]=1;  // đánh dấu bánh đã xuất hiện

        if (day==x){ // kt cái bánh mới nhận có phải cái bánh cần xếp ở đáy ko?
            for (ll k=day;k>=1;k--){ // phải thì bắt đầu xếp
                if (a[k]!=0){   // gặp bánh chưa xuất hiện ?
                    cout<<k<<' ';   // bắt đầu xếp các bánh đang có từ k về 1 (xếp hết lượng bánh đang có theo lớn đến nhỏ)
                    day--;          // vì đã xếp cái bánh đang ở đáy ra nên cập nhật bánh ở đáy mới
                }
                else
                    break;
            }
            cout<<endl; // kết thúc 1 tầng bánh
        }
        else{ // ko thì ko xếp
            cout<<endl; // xuống dòng (ko xếp được gì)
        }
    }

    return 0;
}
//
//5
//4 5 1 2 3
//5 5 3 3 3
//  4     2
//        1
//
//+ tim day
//- day=n
//- in ra thi --day
//
//+ in ra
//- in tu banh o day
//quay ve cai banh
//chua xuat hien
