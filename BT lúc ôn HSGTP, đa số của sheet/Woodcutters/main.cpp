#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0)
typedef long long ll;

ll a[100005];
ll h[100005];
// dùng no, trai, phai thay cho dp[i][0/1/2]
ll no[100005];
// left, right dính tên hàm của c++
ll trai[100005];
ll phai[100005];


int main()
{
    faster;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    ll n; cin>>n;

    for (int i=1;i<=n;i++){
        int x,y; cin>>x>>y;
        a[i]=x;
        h[i]=y;
    }



    ll inf=LLONG_MAX;
    a[0]=-inf;
    a[n+1]=inf;
    no[0]=0;
    trai[0]=0;
    phai[0]=0;

    for (int i=1;i<=n;i++){
        // no: không chặt cây
        no[i]= max({no[i-1], trai[i-1], phai[i-1]});

        // trai: chặt cây cho nó ngã về trái
        //được chặt cây này sang trái
        if (a[i]-h[i] > a[i-1]){
            trai[i]= max(no[i-1], trai[i-1]) ;
            // được chặt sang trái dù cây trước đã chặt sang phải
            if (a[i]-h[i] > a[i-1]+h[i-1]){
                trai[i]= max(trai[i], phai[i-1]);
            }

            //+1 do có chặt 1 cây
            trai[i]=trai[i]+1;
        }
        else{
            trai[i]=-inf; //ko chặt được cây này sang trái
        }


        // phai: chặt cây cho nó ngã về phải
        //được chặt cây này sang phải

        if (a[i]+h[i] < a[i+1]){
            phai[i]= max({no[i-1], phai[i-1], trai[i-1]}) ;
            // vì ngã về phải thì ko có cây nào phía trước ngã về trái. vì chưa chặt đến
            // => xét đc cả 3


            //+1 do có chặt 1 cây
            phai[i]=phai[i]+1;
        }
        else{
            phai[i]=-inf; //ko chặt được cây này sang phải
        }
    }


    cout<<max({no[n], trai[n], phai[n]});


    return 0;
}
