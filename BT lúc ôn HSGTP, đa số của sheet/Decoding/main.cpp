#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main()
{
    faster;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
//    n<=2000 => dùng mảng char
    int n; cin>>n;
    char s[2002]; cin>>s;
    char a[2002];
//    - nếu số lượng chữ lẻ
//    + thì chữ ở vị trí chẵn thêm bên phải
//    + chữ ở vị trí lẻ thêm bên trái
//
//    - nếu số lượng chữ chẵn thì
//    + chữ ở vị trí chẵn thêm bên trái
//    + chữ ở vị trí lẻ thêm bên phải
    if (n%2==1){
        int l=1001;
        int r=1001;
        int dem=1;
        a[1001]=s[0];
        while (dem!=n){
            if (dem%2==0){   // nếu số lượng chữ chẵn
                r++;         // thêm chữ bên phải
                a[r]=s[dem];
            }
            else{
                l--;         // thêm chữ bên trái
                a[l]=s[dem];
            }
            dem++;
        }
        for (int i=l;i<=r;i++){ // in ra
            cout<<a[i];
        }
    }
    else{
        int l=1001;
        int r=1001;
        int dem=1;
        a[1001]=s[0];
        while (dem!=n){
            if (dem%2==0){
                l--;         // thêm chữ bên trái
                a[l]=s[dem];
            }
            else{
                r++;         // thêm chữ bên phải
                a[r]=s[dem];
            }
            dem++;
        }
        for (int i=l;i<=r;i++){
            cout<<a[i];
        }
    }

    return 0;
}
