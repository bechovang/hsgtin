#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int lon;

    cin>>lon;
    int a[lon+1]={0};

    int x;
    int n,m;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>x;
        a[x]=1;
    }
    cin>>m;
    for (int i=0;i<m;i++){
        cin>>x;
        a[x]=1;
    }

    int dem=0;
    for (int i=1;i<=lon;i++){
        if (a[i]==1) dem++;
    }
//    cout<<dem<<endl;
    if (dem==lon) cout<<"I become the guy.";
    else cout<<"Oh, my keyboard!";

    return 0;
}
