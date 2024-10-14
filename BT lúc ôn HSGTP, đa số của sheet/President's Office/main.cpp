#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main()
{
    faster;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n,m;
    char c;
    cin>>n>>m>>c;
    //nhập mảng và cập nhật các chữ vào hashmap
    char a[105][105];
    map <char,int> hm;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cin>>a[i][j];
            hm[a[i][j]]=0;
        }
    }
    // dùng 2 for chạy hết mảng
    // nếu ứng với c thì
    // đánh dấu các chữ chung cạnh (4 hướng) với vào hashmap
    // lưu ý: dùng min(i+1,n-1)  và max(0,i-1) để ko bị out mảng
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (a[i][j]==c){
                hm[a[min(i+1,n-1)][j]]=1;
                hm[a[max(0,i-1)][j]]=1;
                hm[a[i][min(j+1,m-1)]]=1;
                hm[a[i][max(0,j-1)]]=1;
            }
        }
    }

    // đếm các chữ đã đánh dấu
    // (bỏ '.' và c ra)
    int dem=0;
    for (pair<char,int> x: hm){
        if (x.second ==1){
            if (x.first != c and x.first != '.')
                dem++;
        }

    }

    cout<<dem;
    return 0;
}

//    //cách duyệt map
//    for (pair<ll,ll> x:hm) {// dùng for each và pair
//            cout <<x.first <<' '<<x.second <<endl;
//    }
//    // x.first là data1 của pair là key của map,
//    // x.second là data2 của pair là value của map
