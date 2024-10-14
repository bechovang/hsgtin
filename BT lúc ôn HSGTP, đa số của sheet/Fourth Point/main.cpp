#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main()
{
    faster;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    double Ax,Ay,Bx,By,Cx,Cy,Dx,Dy;
    while (cin>>Ax>>Ay>>Bx>>By>>Cx>>Cy>>Dx>>Dy){
        double Tx,Ty,D1x,D1y,D2x,D2y;
        if (Ax==Dx and Ay==Dy){
            Tx=Ax;
            Ty=Ay;
            D1x=Bx;
            D1y=By;
            D2x=Cx;
            D2y=Cy;
        }
        else if (Ax==Cx and Ay==Cy){
            Tx=Ax;
            Ty=Ay;
            D1x=Bx;
            D1y=By;
            D2x=Dx;
            D2y=Dy;
        }
        else if (Bx==Cx and By==Cy){
            Tx=Bx;
            Ty=By;
            D1x=Ax;
            D1y=Ay;
            D2x=Dx;
            D2y=Dy;
        }
        else if (Bx==Dx and By==Dy){
            Tx=Bx;
            Ty=By;
            D1x=Ax;
            D1y=Ay;
            D2x=Cx;
            D2y=Cy;
        }

        double v1x=D1x-Tx;
        double v1y=D1y-Ty;
        double v2x=D2x-Tx;
        double v2y=D2y-Ty;
////        cout<<Tx<<' '<<Ty<<' '<<D1x<<' '<<D1y<<' '<<D2x<<' '<<D2y<<endl;
////        cout<<"vector: "<<v1x<<' '<<v1y<<' '<<v2x<<' '<<v2y<<endl;
////        cout<<"kq cong: "<<v1x+v2x<<' '<<v1y+v2y<<endl;
////        cout<<"kq : "<<v1x+v2x+Tx<<' '<<v1y+v2y+Ty<<endl;

        cout<<fixed<<setprecision(3)<<v1x+v2x+Tx<<' '<<v1y+v2y+Ty<<endl;
    }



    return 0;
}
