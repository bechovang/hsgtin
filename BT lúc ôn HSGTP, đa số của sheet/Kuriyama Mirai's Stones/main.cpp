#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
int main()
{
    faster;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n; cin>>n;
    // nhập mảng a
    vector <int>a(n+1,0);
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    // tạo mảng asort
    vector <int>asort(a.begin(),a.end());
    sort(asort.begin(),asort.end() );
    // tạo mảng pfa và pfasort
    vector <ll>pfa(n+1,0);  // dùng ll cho mảng prefix sum
    vector <ll>pfasort(n+1,0); //vì số sẽ lớn hơn int
    for (int i=1;i<=n;i++){
        pfa[i]=a[i]+pfa[i-1];
        pfasort[i]=asort[i]+pfasort[i-1];
    }
    //nhập truy vấn và trả kq theo đề và
    //theo công thức của prefix sum 1D
    int t; cin>>t;
    while (t--){
        int type, x,y;
        cin>>type>>x>>y;
        if (type==1)
            cout<<pfa[y]-pfa[x-1]<<endl;
        else
            cout<<pfasort[y]-pfasort[x-1]<<endl;
    }

    return 0;
}
