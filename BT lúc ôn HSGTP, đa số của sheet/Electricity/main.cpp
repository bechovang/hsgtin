#include <iostream>

using namespace std;
typedef long long ll;
#define endl '\n'
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
int main()
{
    faster;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    while (1){
        int nhuan[]={0,31,29,31,30,31,30,31,31,30,31,30,31};
        int konhuan[]={0,31,28,31,30,31,30,31,31,30,31,30,31};

        int D,M,Y,C;
        int D1,M1,Y1,C1;
        int Dx,Mx,Yx,Cx;
        int prelD,prelM,prelY,prelC;
        int preD=-1;
        int preM=-1;
        int preY=-1;
        int preC=-1;

        int dem=0;
        int kq=0;

        int n; cin>>n;
        if (n==0) return 0;  // nếu n==0 thì thoát

        while (n--){


            cin>>D>>M>>Y>>C;

            Dx=D; Mx=M; Yx=Y; Cx=C; // Dx là D chưa lùi




            D=D-1; // lùi 1 ngày
            if (D==0){ // ngày = 0
                M=M-1; // lùi 1 tháng
                if ((Y%4==0 and Y%100!=0) or (Y%100==0 and Y%400==0) ) // cập nhật ngày thành ngày cuối cùng của tháng mới lùi
                    D=nhuan[M];
                else
                    D=konhuan[M];
            }
            if (M==0){ // tháng = 0
                Y=Y-1; // lùi 1 năm
                M=12; // cặp nhật tháng thành tháng cuối cùng của năm mới lùi
                 if ((Y%4==0 and Y%100!=0) or (Y%100==0 and Y%400==0) ) // cập nhật ngày thành ngày cuối cùng của tháng 12 của năm mới lùi
                     D=nhuan[M];
                 else
                     D=konhuan[M];
            }

             if (D==preD and M==preM and Y==preY){
                dem++;
                kq=kq+C-preC;
            }

            preD=Dx; preM=Mx; preY=Yx; preC=Cx; // preD là D trước chưa lùi

        }

        cout<<dem<<' '<<kq<<endl;
    }



    return 0;
}
