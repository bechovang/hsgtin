#include <iostream>

using namespace std;
typedef long long ll;
#define endl '\n'
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
int main()
{
    faster;
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    ll t=-1;
    while (t!=0){
        cin>>t;
        if (t==0) return 0;
        ll nhuan[]={0,31,29,31,30,31,30,31,31,30,31,30,31};
        ll konhuan[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
        ll D,M,Y,C;
        ll D1,M1,Y1,C1;
        ll preD=0;
        ll preM=0;
        ll preY=0;
        ll preC=0;
        ll dem=0;
        ll kq=0;
        for (ll o=0;o<t;o++){
//            cout<<preD<<' '<<preM<<' '<<preY<<' '<<preC<<endl;
            D1=preD; M1=preM; Y1=preY; C1=preC;
            cin>>D>>M>>Y>>C;
            preD=D; preM=M; preY=Y; preC=C;

//            cout<<D<<' '<<M<<' '<<Y<<' '<<C<<endl;

            D=D-1;
            if (D==0){
                M=M-1;
                if ((Y%4==0 and Y%100!=0) or (Y%100==0 and Y%400==0) )
                    D=nhuan[M];
                else
                    D=konhuan[M];
            }
            if (M==0){
                Y=Y-1;
                M=12;
                if ((Y%4==0 and Y%100!=0) or (Y%100==0 and Y%400==0) )
                    D=nhuan[M];
                else
                    D=konhuan[M];
            }

            if (D==D1 and M==M1 and Y==Y1){
                dem++;
                kq=kq+C-C1;
            }
//            cout<<"lui 1: "<<D<<' '<<M<<' '<<Y<<' '<<C<<endl;
//            cout<<endl;

        }
        cout<<dem<<' '<<kq<<endl;

    }





    return 0;
}
//5
//9 9 1979 440 (51)
//29 10 1979 458 có thể: 12
//30 10 1979 470 (1)
//1 11 1979 480 có thể: 3
//2 11 1979 483
//3
//5 5 2000 6780
//6 5 2001 7795
//7 5 2002 8201
//8
//28 2 1978 112
//1 3 1978 113
//28 2 1980 220
//1 3 1980 221
//5 11 1980 500
//14 11 2008 600
//15 11 2008 790
//16 12 2008 810
//0
//Ví dụ Đầu ra
//
//2 15
//0 0
//2 191
