#include <bits/stdc++.h>

using namespace std;
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
int main()
{
    faster;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n,k;
    cin>>n>>k;

    vector <int> dau(1000001,0);
    vector <int> cuoi(1000001,0);
    vector <int> a(1000001,0);

    for (int i=0;i<k;i++){
        int x,y;
        cin>>x>>y;
        dau[x]++;
        cuoi[y+1]++;
    }

//    for (int i=0;i<=n;i++){
//        cout<<dau[i]<<' ';
//    }
//    cout<<endl;
//
//    for (int i=0;i<=n;i++){
//        cout<<cuoi[i]<<' ';
//    }
//    cout<<endl;

    int dem=0;
    for (int i=0;i<=n;i++){
        dem=dem+dau[i];
        dem=dem-cuoi[i];
        a[i]=dem;
    }

//    for (int i=0;i<=n;i++){
//        cout<<a[i]<<' ';
//    }
//    cout<<endl;

    sort(a.begin(),a.begin()+n);
//    for (int i=0;i<=n;i++){
//        cout<<a[i]<<' ';
//    }
//    cout<<endl;

    cout<<a[n/2]<<endl;
    return 0;
}
