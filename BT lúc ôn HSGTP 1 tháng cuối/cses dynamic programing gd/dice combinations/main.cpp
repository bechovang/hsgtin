///BECHOVANG

// f là số cách tạo ra tổng n bằng xúc xắc gieo 1 hoặc nhiều lần
//f(0)=f(1)=1
//=> f(n) = f(n-1) + f(n-2) + ... + f(n-6) vì có 6 xúc xắc

//bài đệ quy đc nên lúc chọn các TH,
//nó sẽ tạo ra cấu trúc cây
//và mình sẽ đi tính tổng các mắt của cây đó
//mỗi mắt nó sẽ chia ra 6 má tới, vì có 6 xúc xắc (***f(0)=f(1)=1)
//nên sẽ có cái CT QHD:
//f(n) = f(n-1) + f(n-2) + ... + f(n-6)



#include <bits/stdc++.h>
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
ll mod=1e9+7;
ll dp[1000000];
using namespace std;

int main()
{
    faster;
//    freopen("INPUT.INP","r",stdin);
//    freopen("OUTPUT.OUT","w",stdout);
    ll n; cin>>n;

    //memeset
    for (ll i=0;i<=n;i++){
        dp[i]=0;
    }

    dp[0]=dp[1]=1;
    for (ll i=2;i<=n;i++){
        for (ll j=1;j<=6;j++){
            if (i-j>=0)
                dp[i]=(dp[i]%mod + dp[i-j]%mod)%mod;
        }
    }

//    //debug
//    for (int i=1;i<=n;i++){
//        cout<<dp[i]<<' ';
//    }
//    cout<<endl;

    cout<<dp[n];

    return 0;
}
