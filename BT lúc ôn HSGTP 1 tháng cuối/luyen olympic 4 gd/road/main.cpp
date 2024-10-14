#include <bits/stdc++.h>
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

bool compare(pair<long long,int> a, pair<long long,int>b){
    return a.first < b.first;
}

int main()
{
    faster;
    freopen("ROAD.INP","r",stdin);
    freopen("ROAD.OUT","w",stdout);
    int n; cin>>n;
    int k1,k2; cin>>k1>>k2;

    vector <pair<long long,int>> a;
    a.push_back({-1,-1}); //index1
    for (int i=0;i<n;i++){
        int x,y; cin>>x>>y;
        a.push_back({x,y});
    }

    sort(a.begin(), a.end(),compare);



    vector <int> pf1(n+1,0);
    if (a[1].second==1)
        pf1[1]++;
    for (int i=2;i<=n;i++){
        int x=0;
        if (a[i].second==1) x++;
        pf1[i]=pf1[i-1]+ x;
    }

    vector <int> pf2(n+1,0);
    if (a[1].second==2)
        pf2[1]++;
    for (int i=2;i<=n;i++){
        int x=0;
        if (a[i].second==2) x++;
        pf2[i]=pf2[i-1]+ x;
    }


    long long kq=INT_MAX;
    for (int i=1;i<=n;i++){
        for (int j=i+1;j<=n;j++){
            int sl1= pf1[j]-pf1[i-1];
            int sl2= pf2[j]-pf2[i-1];
            if (sl1==k1 and sl2==k2)
                kq=min(kq, a[j].first - a[i].first);
        }
    }



//    //debug
//    for (auto x: a){
//        cout<<x.first<<' '<<x.second<<endl;
//    }
//    cout<<endl;
//    for (auto x: pf1){
//        cout<<x<<' ';
//    }
//    cout<<endl;
//    for (auto x: pf2){
//        cout<<x<<' ';
//    }
//    cout<<endl;

    cout<<kq;

    return 0;
}
