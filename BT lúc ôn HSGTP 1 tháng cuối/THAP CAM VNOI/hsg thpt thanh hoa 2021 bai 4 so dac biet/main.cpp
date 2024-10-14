#include <bits/stdc++.h>
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

bool la_snt[1000005];
void sang_snt(int n){
    la_snt[0]=false;
    la_snt[1]=false;
    for (int i=2;i<=sqrt(n);i++){
        if (la_snt[i]==true)
            for (int j=i*i;j<=n;j=j+i){
                la_snt[j]=false;
            }
    }

    return;
}

int dem_uoc(int n){
    int kq=0;
    for (int i=1;i<=sqrt(n);i++){
        if (n%i==0)
            kq+= 2;
    }
    if (floor(sqrt(n))*floor(sqrt(n))==n)
        kq--;
    return kq;

}

bool mot_uoc_la_snt(int n){
    int dem=0;
    for (int i=1;i<=sqrt(n);i++){
        if (n%i==0){
            if (la_snt[i]==true)
                dem++;
            if (n/i != i)
                if (la_snt[n/i]==true)
                    dem++;
        }
    }
    if (dem==1)
        return true;
    else
        return false;

}

int main() {
    faster;

    freopen("BAI4.INP", "r", stdin);
    freopen("BAI4.OUT", "w", stdout);
    //memset la_snt
    for (int i=0;i<=1000004;i++){
        la_snt[i]=true;
    }
    sang_snt(1000000);
    int l,r; cin>>l>>r;
    int kq=0;
    for (int i=l;i<=r;i++){
        if (mot_uoc_la_snt(i)==true){
            kq++;
        }
    }
    cout<<kq;


}
