#include <bits/stdc++.h>
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
using namespace std;

signed main()
{
    faster;
    freopen("SPSEQ.INP","r",stdin);
    freopen("SPSEQ.OUT","w",stdout);
    int n; cin>>n;
    int a[n];
    for (int i=0;i<n;i++) cin>>a[i];

    //tang
    int dp_tang[n] = {0};
    vector<int> lis;
    int last=-1;
    for (int i=0;i<n;i++){
        if (last<a[i]){
            lis.push_back(a[i]);
            last=lis[lis.size()-1];
        }
        else{
            int k=lower_bound(lis.begin(), lis.end(), a[i]) -lis.begin();
            lis[k]=a[i];
            last=lis[lis.size()-1];
        }

        dp_tang[i]=lis.size();
    }


    //giam
    int dp_giam[n];
    vector<int> lds;
    last=-1;
    for (int i=n-1;i>=0;i--){
        if (last<a[i]){
            lds.push_back(a[i]);
            last=lds[lds.size()-1];
        }
        else{
            int k=lower_bound(lds.begin(), lds.end(), a[i]) -lds.begin();
            lds[k]=a[i];
            last=lds[lds.size()-1];
        }
        dp_giam[i]=lds.size();
    }

//    //debug
//    for (int i=0;i<n;i++){
//        cout<<dp_tang[i]<<' ';
//    }
//    cout<<endl;
//    for (int i=0;i<n;i++){
//        cout<<dp_giam[i]<<' ';
//    }
//    cout<<endl;

    int kq=1;
    for (int i=0;i<n;i++){
        int k=min(dp_giam[i],dp_tang[i]);
//        int chenhlech=abs(dp_giam[i]-dp_tang[i]);
        kq=max(kq,k*2-1);
    }

    cout<<kq;

    return 0;
}

//6
//8 6 3 4 2 1
//=> 3 (3 4 2)

//=>
//1 2 2 2 1 3
//1 4 3 2 1 1
//3
