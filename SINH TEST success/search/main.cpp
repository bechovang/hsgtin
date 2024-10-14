#include <bits/stdc++.h>
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//#define int long long
using namespace std;

signed main()
{
    faster;
    freopen("search.inp","r",stdin);
    freopen("search.out","w",stdout);
    int a,b; cin>>a>>b;
    if (a==b){
        cout<<0;
        return 0;
    }
    //memset
    int dp[500005];
    dp[a]=0;
    int dem=0;
    for (int i=a+1;i<=b*2;i++){
        dem++;
        dp[i]=dem;
    }
    dem=0;
    for (int i=a-1;i>=0;i--){
        dem++;
        dp[i]=dem;
    }
//    //debug
//    for (int i=0;i<=b;i++){
//        cout<<i<<' '<<dp[i]<<endl;
//    }
//    cout<<endl;

//
//    for (int i=a;i>=0;i--){
//        if (i%2==0 )
//            dp[i]=min({dp[i], dp[i+1]+1, dp[i*2]+1});
//        else
//            dp[i]=min(dp[i], dp[i+1]+1);
//    }

    for (int i=a+1;i<=b*2;i++){
        if (i-1>=0){
            if (i%2==0 ){
                dp[i]=min({dp[i], dp[i-1]+1, dp[i/2]+1});
            }
            else
                dp[i]=min(dp[i], dp[i-1]+1);
        }
    }

    dem=0;
    int kq=INT_MAX;
    for (int i=b;i<=b*2;i++){
        kq=min(kq, dem+dp[i]);
        dem++;
    }


//    //debug
//    for (int i=0;i<=b*2;i++){
//        cout<<i<<' '<<dp[i]<<endl;
//    }
//    cout<<endl;

    cout<<kq;
    return 0;
}
