#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

bool compare(pair<int,int>a, pair<int,int>b ){
    if (a.second==0) return false; // ko chia đc cho 0
    if (b.second==0) return true;

    return (a.first / a.second ) > (b.first / b.second );
}

int main()
{
    faster;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int s, n;
    cin>>s>>n;

    vector <pair<int,int>> vp; //can nang - gia tri
    for (int i=0;i<n;i++){
        int x,y; cin>>x>>y;

        vp.push_back({x,y});
    }

  //  sort (vp.begin(),vp.end(),compare);

    int dp[n+1][s+1]; //vật - khoang

    //khoang 0 thì ko chọn đc gì
    for (int i=0;i<n;i++){
        dp[i][0]=0;
    }
    // chon mon dau index-0
    for (int j=0;j<=s;j++){ //di tung khoang
        int wt = vp[0].first;
        int val = vp[0].second;
        if (j>=wt) // chứa đc
            dp[0][j]=val;
        else
            dp[0][j]=0;
    }

    int kq=-1;

    for (int i=1;i<n;i++){
        for (int j=0;j<=s;j++){
            int wt = vp[i].first;
            int val = vp[i].second;
            if (j - wt >= 0){ // neu khoang hien tai chua duoc vat
                dp[i][j]= max(dp[i-1][j], dp[i-1][j-wt] + val); // có thể chọn => ko chọn / chọn
            }
            else{
                dp[i][j]=dp[i-1][j]; // ko thể chọn => ko chọn
            }

            kq=max(kq,dp[i][j]);
        }
    }




//    //debug

//    for (auto x: vp){
//        cout<<x.first<<' '<<x.second<<endl;
//    }


//    for (int i=0;i<n;i++){
//        cout<<vp[i].first<<' '<<vp[i].second<<": ";
//        for (int j=0;j<=s;j++){
//            cout<<dp[i][j]<<' ';
//        }
//        cout<<endl;
//    }

    cout<<kq;


    return 0;
}
