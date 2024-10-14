#include <bits/stdc++.h>
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//#define int long long
using namespace std;

int n;
int a[2005]={0};
int pf_xuoi[2005]={0};
int pf_nguoc[2005]={0};
int kq=0;

int sum(int x, int y){
    return pf_xuoi[y] - pf_xuoi[x-1];
}

int best_cat(int x, int y){
    int minn=INT_MAX;
    int pos_minn=-1;
    for (int i=x;i<y;i++){
        int tg1=sum(x,i);
        int tg2=sum(i+1,y);
        if (minn>abs(tg1-tg2)){
            minn=abs(tg1-tg2);
            pos_minn=i;
        }
    }

    return pos_minn;
}

int solve(int x, int y){
    if (x==y) return 0;

    int k=best_cat(x,y);

    int tg1= sum(x,k);
    int tg2= sum(k+1,y);
    kq+= tg1 + tg2;

    solve(x,k);
    solve(k+1,y);

    return kq;
}

int main() {
    faster;
    freopen("BUS.INP", "r", stdin);
    freopen("BUS.OUT", "w", stdout);


    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> a[i];
    //prefix
    pf_xuoi[0]=0;
    for (int i = 1; i <= n; i++){
        pf_xuoi[i]=pf_xuoi[i-1] + a[i];
    }
    pf_nguoc[n]=0;
    for (int i = n; i >= 1; i--){
        pf_nguoc[i]=pf_nguoc[i+1] + a[i];
    }

    //debug
    for (int i = 0; i <= n+1; i++){
        cout<<pf_xuoi[i]<<' ';
    }
    cout<<endl;
    for (int i = 0; i <= n+1; i++){
        cout<<pf_nguoc[i]<<' ';
    }
    cout<<endl;

//    cout<<best_cat(2,3);
    cout<<solve(1,n);



    return 0;
}
