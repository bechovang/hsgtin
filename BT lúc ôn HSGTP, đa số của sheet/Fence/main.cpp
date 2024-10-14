#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
int main()
{
    faster;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,k; cin>>n>>k;
    // vừa nhập vừa tạo mảng prefix sum
    vector <ll>pf(n,0);
    for (int i=1;i<=n;i++){
        int x; cin>>x;
        pf[i]=pf[i-1]+x;
    }
    // tìm vị trí đầu của đoạn có k số
    // liên tiếp nhỏ nhất
    ll minn=LLONG_MAX;
    int vt=-1;
    for (int i=1;i<=n-k+1;i++){
        if (pf[i+k-1]-pf[i-1] < minn){ // kt tổng của k số liên tiếp
            minn=pf[i+k-1]-pf[i-1];    // bắt đầu từ vị trí i
            vt=i;                // lấy min và lưu vị trí
        }
    }

    cout<<vt;
    return 0;
}
