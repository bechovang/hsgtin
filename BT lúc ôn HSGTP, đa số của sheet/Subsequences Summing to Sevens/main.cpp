#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main()
{
    faster
    freopen("div7.in","r",stdin);
    freopen("div7.out","w",stdout);
    int n;
    cin>>n;

    long long x,a[50001];
    memset(a,0,50001);
    for (int i=1;i<=n;i++){
        cin>>x;
        a[i]=(a[i-1]+x)%7;
    }

//    for (int i=1;i<=n;i++){
//        cout<<a[i]<<' ';
//    }
//    cout<<endl;

    int vtdau[7];
    int vtcuoi[7];
    for (int i=0;i<=7;i++){
        vtdau[i]=-1;
        vtcuoi[i]=-1;
    }
    for (int i=1;i<=n;i++){
        if (vtdau[a[i]]==-1){
            vtdau[a[i]]=i;
        }
    }
    for (int i=n;i>=1;i--){
        if (vtcuoi[a[i]]==-1){
            vtcuoi[a[i]]=i;
        }
    }

    int lon=INT_MIN;
    for (int i=1;i<=6;i++){
        lon=max(lon,vtcuoi[i]-vtdau[i]);
    }

    cout<<lon;
    return 0;
}
// mod 7 mảng prefix sum, sau đó tìm khoảng lớn nhất có a[i] giống a[j]
// tạo mảng prefix sum a[i]=(a[i-1]+x)%7;
// tìm khoảng lớn nhất có a[i] giống a[j]:
//     + tìm vtdau[i] và vtcuoi[i] bằng cách duyệt xuôi và ngược 1 lần
//     + => chỉ tốn O(2n) để duyệt tìm khoảng lớn nhất
