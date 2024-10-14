#include <bits/stdc++.h>
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//#define int long long
using namespace std;

signed main()
{
    faster;
    freopen("PLAY.INP","r",stdin);
    freopen("PLAY.OUT","w",stdout);
    int n,k; cin>>n>>k;
    vector <pair<int,int>> a; //so - so lan lien tiep
    a.push_back({0,0}); //index1
    for (int i=0;i<n;i++){
        int pos_last=a.size()-1;
        int last=a[a.size()-1].first;
        int k_last=a[a.size()-1].second;

        int x; cin>>x;
        if (last!=x){
            a.push_back({x,1});
        }
        else{
            a[pos_last]={last,k_last+1};
        }
    }

    for (auto x:a){
        cout<<x.first<<' '<<x.second<<endl;
    }
    cout<<endl;

    return 0;
}
