#include <bits/stdc++.h>


using namespace std;
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main()
{
    faster;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int nx,ny,nz;
    int x[10000],y[10000],z[10000];

    //số lớn nhất => tử min, mẫu max
    int maxr1=INT_MIN;
    int minp2=INT_MAX;
    cin>>nx;
    for (int i=0;i<nx;i++){
        cin>>x[i];
        maxr1=max(x[i],maxr1);
    }
    cin>>ny;
    for (int i=0;i<ny;i++){
        cin>>y[i];
    }
    cin>>nz;
    for (int i=0;i<nz;i++){
        cin>>z[i];
        minp2=min(z[i],minp2);
    }

    int A,B;
    cin>>A>>B;

    int pi=atan(1)*4;
    double kq=-1;
    for (int j=0;j<ny;j++){
        int p1=y[j];
        //tính toán nhiều bước để tránh sai số
        double tu= maxr1 * sqrt(pi) * sqrt(p1) * sqrt(B) ;
        double mau= sqrt(minp2*A + p1*B);
        double tmp= maxr1 / mau ;
        tmp= tmp* sqrt(p1) ;
        tmp= tmp* sqrt(B) ;

        kq=max(kq,tmp);
    }

    cout<<fixed<<setprecision(15)<<kq;

    return 0;
}
