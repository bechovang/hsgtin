///bechovang

#include <bits/stdc++.h>
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

struct ve{
    int mot;
    int hai;
    int ba;
};

int inf=1e7;
int main()
{
    faster;
    freopen("MUAVE.INP","r",stdin);
    freopen("MUAVE.OUT","w",stdout);
    int n;
    cin>>n;

    vector <ve> a;
    ve p;
    p.mot=0;
    p.hai=0;
    p.ba=0;
    a.push_back(p); //index1
    for (int i=1;i<=n;i++){
        int x,y,z;
        cin>>x>>y>>z;
        ve p;
        p.mot=x;
        p.hai=y;
        p.ba=z;
        a.push_back(p);
    }

    int dp[5005];
    //mêmset
    for (int i=0;i<=n;i++){
        dp[i]=inf;
    }

    dp[0]=0;
    for (int i=1;i<=n;i++){
        dp[i]=min(dp[i], dp[i-1]+a[i].mot);
        if (i-1>=1)
            dp[i]=min(dp[i], dp[i-2]+a[i-1].hai);
        if (i-2>=1)
            dp[i]=min(dp[i], dp[i-3]+a[i-2].ba);



    }

//     //debug
//    for (int i=1;i<=n;i++){
//        cout<<dp[i]<<' ';
//    }
//    cout<<endl;

    cout<<dp[n];

    return 0;
}
