///BECHOVANG

// tưởng tượng theo đệ quy rồi QHD nó như bài 1


#include <bits/stdc++.h>
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;

int dp[1000005]; //so lan - khoang
int inf=1e7;
using namespace std;

int main()
{
    faster;
//    freopen("INPUT.INP","r",stdin);
//    freopen("OUTPUT.OUT","w",stdout);


    int n,k; cin>>n>>k;

    int a[n];
    for (int i=0;i<n;i++){
        cin>>a[i];
    }

    //memset
    for (int i=1;i<=k;i++){
        dp[i]=inf;
    }

    for (int i=0;i<=k;i++){
        for (int j=0;j<n;j++){
            if (i-a[j] >= 0)
                dp[i]= min(dp[i], dp[i-a[j]] +1);
        }
    }


//    //debug
//    for (int i=0;i<=k;i++){
//        cout<<dp[i]<<' ';
//    }
//    cout<<endl;

    if (dp[k]==1e7)
        cout<<-1;
    else
        cout<<dp[k];



    return 0;
}
