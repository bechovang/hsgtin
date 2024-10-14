#include <bits/stdc++.h>
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//#define int long long
using namespace std;



signed main()
{
    faster;
    freopen("LIS.INP","r",stdin);
	freopen("LIS.OUT","w",stdout);
    int n; cin>>n;
    int a[n];
    for (int i=0;i<n;i++){
        cin>>a[i];
    }

    vector<int> lis;
    int maxx=-1;
    for (int i=0;i<n;i++){
        if (maxx<a[i]){
            lis.push_back(a[i]);
            maxx=lis[lis.size()-1];
        }
        else{
            int k= lower_bound(lis.begin(), lis.end(), a[i]) - lis.begin();
            lis[k]=a[i];
            maxx=lis[lis.size()-1];
        }
    }

    cout<<lis.size();

    return 0;
}
