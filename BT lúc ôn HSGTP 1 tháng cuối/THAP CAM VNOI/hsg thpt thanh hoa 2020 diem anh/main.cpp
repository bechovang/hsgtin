//*** vector nhanh hõn map

#include <bits/stdc++.h>
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int main()
{
    faster;
    freopen("CAU2.INP","r",stdin);
    freopen("CAU2.OUT","w",stdout);
    int n; cin>>n;
    vector <int> a(1000005,0);
    int kq=-1;
    for (int i=0;i<n;i++){
        int x; cin>>x;
        a[x]++;
        kq=max(kq,a[x]);
    }

    cout<<kq;
    return 0;
}
