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
    // nhập mảng a
    vector <int> a(n);
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    //tạo mảng asort
    vector <int> asort(a.begin(), a.end());
    sort(asort.begin(), asort.end());
    //kt nếu a==asort =>cout<<""yes""<<'\n'<<""1 1""; (THĐB)
    if (a==asort){
        cout<<"yes"<<'\n'<<"1 1";
        return 0;
    }
    // tìm đoạn [l,r] là đoạn khác nhau của a và asort.
    // (theo logic đề thì sẽ chỉ có 1 đoạn)
    int l,r;
    for (l=0;l<n;l++){
        if (a[l]!=asort[l])
            break;
    }
    for (r=n-1;r>=0;r--){
        if (a[r]!=asort[r])
            break;
    }
    //tạo mảng tmp: đảo ngược của a trong đoạn [l,r]
    vector <int> tmp(a.begin(), a.end());
    reverse(tmp.begin() + l, tmp.begin() + r + 1);
    //kt tmp==asort => in kq theo đề"
    if (tmp==asort){
        cout<<"yes"<<endl;
        cout<<l+1<<' '<<r+1;
    }
    else{
        cout<<"no";
    }

    return 0;
}
