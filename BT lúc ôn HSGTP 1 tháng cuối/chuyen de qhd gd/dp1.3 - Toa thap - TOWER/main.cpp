//bechovang

#include <bits/stdc++.h>
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;



int main()
{
    faster;
    freopen("TOWER.INP","r",stdin);
    freopen("TOWER.OUT","w",stdout);

    int n; cin>>n;

    vector<int> bk; // ban kinh
    vector<int> h; // chieu cao
    for (int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        bk.push_back(x);
        h.push_back(y);
    }


    vector<int> dp(505,0);

    for (int i=0;i<n;i++){
        for (int j=bk[i];j<=500;j++){
            dp[bk[i]]=max(dp[bk[i]], dp[j] + h[i]);
            // chiều cao MAX của bán kinh thứ i là tổng các bán kính lớn hơn i (i --> 500)
        }
    }

    int kq=-1;
    for (int i=0;i<=500;i++){
        kq= max(kq,dp[i]);
    }

    cout<<kq;
    return 0;
}

//4
//4 2
//2 5
//1 3
//3 1
