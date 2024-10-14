#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main()
{
    faster;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t; cin>>t;
    while (t--){
        int n; cin>>n;
        int trap[1001]={}; // gia tri la time
//        int time[101];
        int tieuhao[1001]={};
        for (int i=0;i<n;i++){
            int x,y; cin>>x>>y;
            if (trap[x]==0) trap[x]=y;
            else trap[x]=min(trap[x],y);
        }

        int E=INT_MAX;
        int dem=0;
        bool f=false;
        for (int i=1;i<=1000;i++){
            if (trap[i]!=0){
                if (f==false){
                    E=(trap[i]/2);
                    if (trap[i]%2==1 and trap[i]!=1)
                        E++;
                    f=true;
                }
                else{
                    int tmp=trap[i];
                    E=(trap[i]/2);
                    if (trap[i]%2==1 and trap[i]!=1)
                        E++;
                    E=min(E,tmp);
                }

            }
            else{
                E--;
            }
            if (E==0)
                break;
            else
                dem++;
        }
        if (dem==0) dem=1;
        cout<<dem<<endl;


//        //debug
//        for (int i=1;i<=6;i++){
//            cout<<i<<' '<<trap[i]<<endl;
//        }
//        cout<<endl;

    }
    return 0;
}
