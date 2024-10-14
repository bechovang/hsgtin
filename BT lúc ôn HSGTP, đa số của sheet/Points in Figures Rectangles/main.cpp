#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main()
{
    faster;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    string s;
    int n=0;
    vector < vector<double> > a(10,vector<double>(4));
    while (s!="*"){
        cin>>s;
        if (s=="*") break;
        n++;
        int i=n-1;
        cin>>a[i][0]>>a[i][1]>>a[i][2]>>a[i][3];
//        cout<<a[i][0]<<' '<<a[i][1]<<' '<<a[i][2]<<' '<<a[i][3]<<' '<<endl;
    }

    double x,y;
    int m=0;
    while (x!=9999.9 and y!=9999.9){
        cin>>x>>y;
        if (x==9999.9 and y==9999.9) break;
        m++;
        bool inside=false;
        for (int i=0;i<n;i++){
            double x1=a[i][0];
            double y1=a[i][1];
            double x2=a[i][2];
            double y2=a[i][3];
            if (x>x1 and x<x2 and y>y2 and y<y1){
                cout<<"Point "<<m<<" is contained in figure "<<i+1<<endl;
                inside=true;
            }

        }

        if (inside==false) cout<<"Point "<<m<<" is not contained in any figure"<<endl;
    }

    return 0;
}
