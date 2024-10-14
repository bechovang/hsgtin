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
   vector <int> a;
    for (int i=0;i<n;i++){
        int x; cin>>x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());

    int minn=INT_MAX;
    for (int i=0;i<n;i++){
        minn=min(minn, i+a[i]);
    }

    cout<<min(n,minn+1);



//    //debug
//    cout<<endl;
//    for (auto x: a){
//        cout<<x<<' ';
//    }
//    cout<<endl;

    return 0;
}
