#include <bits/stdc++.h>
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//#define int long long
using namespace std;




signed main()
{
    faster;
    freopen("INPUT.INP","r",stdin);
    freopen("OUTPUT.OUT","w",stdout);
    int n; cin>>n;
    vector<int> v;
    map <int,int> hm;
    for (int i=0;i<n;i++){
        int x; cin>>x;
        if (hm[x]==0){
            v.push_back(x);
            hm[x]++;
        }
        else{
            hm[x]++;
        }

    }

    sort(v.begin(), v.end());

    for (int i=0;i<v.size();i++){
//        cout<<v[i]<<' '<<hm[v[i]]<<endl;
        if (hm[v[i]]==1){
            cout<<i+1;
            return 0;
        }
    }
    return 0;
}
