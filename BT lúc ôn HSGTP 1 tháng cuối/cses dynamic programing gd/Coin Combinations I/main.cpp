///BECHOVANG

// giống bài đếm th của xúc xắc
// lần này ko phải 6 TH 6 mặt nx mà là n TH n số
// *** dùng nhiều mod bị TLE
// *** dùng mảng bth bị TLE => dùng vector


#include <bits/stdc++.h>
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;


using namespace std;

int main()
{
    faster;
//    freopen("INPUT.INP","r",stdin);
//    freopen("OUTPUT.OUT","w",stdout);


    int mod = 1e9+7;
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int&v : a) cin >> v;

    vector<int> dp(1000000+1,0);

    //memset
    for (int i=0;i<n;i++){
        if (a[i]<=k)
            dp[a[i]]=1;
    }

    for (int i=0;i<=k;i++){
        for (int j=0;j<n;j++){
            if (i-a[j] >= 0)
                (dp[i] += dp[i-a[j]]) %= mod;
        }
    }


//    //debug
//    for (int i=0;i<=k;i++){
//        cout<<dp[i]<<' ';
//    }
//    cout<<endl;

    cout<<dp[k];



    return 0;
}
