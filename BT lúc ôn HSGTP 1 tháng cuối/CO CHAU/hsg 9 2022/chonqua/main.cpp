#include <bits/stdc++.h>
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//#define int long long
using namespace std;

int be_ca[1005][1005]={0};
int n,m,k;

int vot_duoc(int x, int y){
    int a=x+1;
    int b=y+1;
    int A=x + (k-2);
    int B=y + (k-2);

    int tg=0;
    for (int i=a;i<=A;i++){
        for(int j=b;j<=B;j++){
            tg=tg+ be_ca[i][j];
        }
    }

    return tg;
}

signed main()
{
    faster;
    freopen("chonqua.inp","r",stdin);
    freopen("chonqua.out","w",stdout);
    cin>>n>>m;
    cin>>k;

    for (int i=1;i<1005;i++){
        for (int j=1;j<1005;j++){
            be_ca[i][j]=0;
        }
    }

    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            char s; cin>>s;
            if (s=='.')
                be_ca[i][j]=0;
            else
                be_ca[i][j]=1;
        }
    }

    int maxx=INT_MIN;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            maxx=max(maxx,vot_duoc(i,j));
        }
    }

    cout<<maxx;

    //debug
    cout<<endl;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cout<<be_ca[i][j]<<' ';
        }
        cout<<endl;
    }
    cout<<endl;

    return 0;
}
