///BECHOVANG

#include <bits/stdc++.h>
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
using namespace std;

int n,q;
vector <int> a(106);
vector <int> money_able;
void dequy(int index, int sum){
    if (index==n){
        money_able.push_back(sum);
        return;
    }

    dequy(index +1, sum);
    dequy(index +1, sum + a[index+1]);
    return;
}


signed main()
{
    faster;
    freopen("ATM.INP","r",stdin);
    freopen("ATM.OUT","w",stdout);
    cin>>n>>q;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }

    dequy(0,0);
    sort(money_able.begin(), money_able.end());
//    for (auto x: money_able){
//        cout<<x<<' ';
//    }

    int dem=0;
    while (q--){
        int x; cin>>x;
        if (binary_search(money_able.begin(), money_able.end(),x))
            dem++;
    }

    cout<<dem;



    return 0;
}

//loi giai: https://drive.google.com/file/d/1A91eR24KhivWsNInXksaL__Y_Ygvc1o0/view
//anh gif hinh dung de quy: https://i.imgur.com/vH7LfVj.gif
