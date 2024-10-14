#include <bits/stdc++.h>
#include <cmath>

using namespace std;
const double pi = 3.14159265358979323846;
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main()
{
    faster;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    double d,h,v,e;
    cin>>d>>h>>v>>e;

    double r=d/2;
    double thetich= pi * pow(r,2) * h;
    double nuoctang= pi * pow(r,2) * 1;
//    cout<<thetich<<endl;

    if (nuoctang>v) {
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    cout<<fixed<<setprecision(12)<< thetich/(v-nuoctang)<<endl;

    return 0;
}
