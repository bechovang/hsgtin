#include <bits/stdc++.h>
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

struct items{
    int weight;
    int cost;
};

bool compare(items a, items b){
    return a.weight/a.cost < b.weight/b.cost;
}

int main()
{
    freopen("FARMER.INP","r",stdin);
    freopen("FARMER.OUT","w",stdout);
    int t; cin>>t;
    while (t--){
        int k; cin>>k;


        int n_fields,n_strips;
        cin>>n_fields>>n_strips;


        vector <items> a;

        for (int i=0;i<n_fields;i++){
            int x; cin>>x;
            items p;
            p.weight=x;
            p.cost=x;
            a.push_back(p);
        }
        for (int i=0;i<n_strips;i++){
            int x; cin>>x;
            items p;
            p.weight=x;
            p.cost=x-1;
            a.push_back(p);
        }

//        //debug
//        for (auto x: a){
//            cout<<x.weight<<' '<<x.cost<<endl;
//        }
//        cout<<endl;


        sort(a.begin(), a.end(), compare);


//        //debug
//        for (auto x: a){
//            cout<<x.weight<<' '<<x.cost<<endl;
//        }
//        cout<<endl;


////    //memset cho dòng ko có đồ nào
////    for (int j=1;j<=k;j++ )
////        dp[0][j]=0;
////    for (int i=1;i<=n;i++ ) // do có dp[i-1][j-weight[i]]
////        dp[i][0]=0;
////
////
////    //mảng 2 chiều do giá trị phụ thuộc 2 yếu tố
////    for (int i=1;i<=n;i++ ){ // vật
////        for (int j=1;j<=k;j++ ){ // khoang
////            if (j-weight[i] >= 0){
////                dp[i][j] = max(dp[i][j], dp[i-1][j-weight[i]] + cost[i]); // bỏ vào đc
////                dp[i][j] = max(dp[i][j], dp[i-1][j]); //lấy ko bỏ vào lời hơn
////            }
////
////            else
////                dp[i][j] = dp[i-1][j]; // ko bỏ đc
////        }
////    }

        int dp[a.size()+1][k+1]={0};

        //memset
        for (int j=0;j<=k;j++){
            if (a[0].weight <= j)
                dp[0][j]= a[0].cost;
            else
                dp[0][j]=0;
        }
        for (int i=0;i<a.size();i++ )
            dp[i][0]=0;



        for (int i=1;i<a.size();i++){
            for (int j=1;j<=k;j++){
                if (j-a[i].weight >= 0){
                    dp[i][j]= max(dp[i][j], dp[i-1][j-a[i].weight] + a[i].cost);
                    dp[i][j]= max(dp[i][j], dp[i-1][j]);
                }
                else{
                    dp[i][j]= max(dp[i][j], dp[i-1][j]);
                }
            }
        }

//
//        //debug;
//        for (int i=0;i<a.size();i++){
//            for (int j=0;j<=k;j++){
//                cout<<dp[i][j]<<' ';
//            }
//            cout<<endl;
//        }
//        cout<<endl;

        cout<<dp[a.size()-1][k];



    }
    return 0;
}
