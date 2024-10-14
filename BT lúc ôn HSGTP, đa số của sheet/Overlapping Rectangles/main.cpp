#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

bool thuoc(int a, int x, int y){
    if (a>=x and a<=y) return true;
    else return false;
}

int main()
{
    faster;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t; cin >>t;
    while (t--){
        int Ax1,Ay1,Ax2,Ay2;
        int Bx1,By1,Bx2,By2;
        int Cx1=-1;
        int Cy1=-1;
        int Cx2=-1;
        int Cy2=-1; //kq
        cin>>Ax1>>Ay1>>Ax2>>Ay2;
        cin>>Bx1>>By1>>Bx2>>By2;

        if (thuoc(Ax1,Bx1,Bx2)==true and thuoc(Ax2,Bx1,Bx2)==true){
            Cx1=min(Ax1,Ax2);
            Cx2=max(Ax1,Ax2);
        }
        else if (thuoc(Bx1,Ax1,Ax2)==true and thuoc(Bx2,Ax1,Ax2)==true){
            Cx1=min(Bx1,Bx2);
            Cx2=max(Bx1,Bx2);
        }
        else if (thuoc(Bx1,Ax1,Ax2)==true and thuoc(Ax2,Bx1,Bx2)==true){
            Cx1=min(Bx1,Ax2);
            Cx2=max(Bx1,Ax2);
        }
        else if (thuoc(Ax1,Bx1,Bx2)==true and thuoc(Bx2,Ax1,Ax2)==true){
            Cx1=min(Ax1,Bx2);
            Cx2=max(Ax1,Bx2);
        }
//        cout<<Cx1<<' '<<Cx2;

        if (thuoc(Ay1,By1,By2)==true and thuoc(Ay2,By1,By2)==true){
            Cy1=min(Ay1,Ay2);
            Cy2=max(Ay1,Ay2);
        }
        else if (thuoc(By1,Ay1,Ay2)==true and thuoc(By2,Ay1,Ay2)==true){
            Cy1=min(By1,By2);
            Cy2=max(By1,By2);
        }
        else if (thuoc(By1,Ay1,Ay2)==true and thuoc(Ay2,By1,By2)==true){
            Cy1=min(By1,Ay2);
            Cy2=max(By1,Ay2);
        }
        else if (thuoc(Ay1,By1,By2)==true and thuoc(By2,Ay1,Ay2)==true){
            Cy1=min(Ay1,By2);
            Cy2=max(Ay1,By2);
        }

        if (Cx1==-1 or Cy1==-1 or Cx2==-1 or Cy2==-1) cout<< "No Overlap"<<endl;
        else if (Cx1==Cx2 or Cy1==Cy2) cout<< "No Overlap"<<endl;
        else cout<<Cx1<<' '<<Cy1<<' '<<Cx2<<' '<<Cy2<<endl;

        if (t!=0)
            cout<<endl;
    }
    return 0;
}
