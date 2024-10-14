#include <bits/stdc++.h>
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
using namespace std;


signed main()
{
    faster;
    freopen("viecnha.inp","r",stdin);
    freopen("viecnha.out","w",stdout);
    int k,n; cin>>k>>n;
    vector <int>a;
    for (int i=0;i<n;i++){
        int x; cin>>x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    int tg=0;
    int dem=0;
    for (int i=0;i<n;i++){
        tg=tg+a[i];
        dem++;
        if (tg>=k)
            break;
    }

    cout<<dem;


    return 0;
}
