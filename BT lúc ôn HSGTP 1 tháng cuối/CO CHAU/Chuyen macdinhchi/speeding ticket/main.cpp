#include <bits/stdc++.h>
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main()
{
    faster;
    freopen("input.inp","r",stdin);
    freopen("output.out","w",stdout);
    int n,m; cin>>n>>m;
    int law_pos[n+1]={0};
    int law_val[m+1]={0};
    for (int i=1;i<=n;i++){
        int x,y; cin>>x>>y;
        law_pos[i]= law_pos[i-1] + x;
        law_val[i]= y;
    }
    int cow_pos[n+1]={0};
    int cow_val[m+1]={0};
    for (int i=1;i<=m;i++){
        int x,y; cin>>x>>y;
        cow_pos[i]= cow_pos[i-1] + x;
        cow_val[i]= y;
    }

    int law[105]={0};
    for (int i=1;i<=n;i++){
        int x=law_pos[i-1]+1;
        int y=law_pos[i];
        int val=law_val[i];
        for (int j=x;j<=y;j++){
            law[j]=val;
        }
    }
    int cow[105]={0};
    for (int i=1;i<=m;i++){
        int x=cow_pos[i-1]+1;
        int y=cow_pos[i];
        int val=cow_val[i];
        for (int j=x;j<=y;j++){
            cow[j]=val;
        }
    }

    int kq=-1;
    for (int i=1;i<=100;i++){
        kq=max(cow[i]-law[i],)
    }




    //debug;
    for (auto x: law_pos){
        cout<<x<<' ';
    }
    cout<<endl;
    for (auto x: law_val){
        cout<<x<<' ';
    }
    cout<<endl;
    for (auto x: cow_pos){
        cout<<x<<' ';
    }
    cout<<endl;
    for (auto x: cow_val){
        cout<<x<<' ';
    }
    cout<<endl;
    for (auto x: law){
        cout<<x<<' ';
    }
    cout<<endl;
    for (auto x: cow){
        cout<<x<<' ';
    }
    cout<<endl;




    return 0;
}
