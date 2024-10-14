#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main()
{
    faster;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    int kq=0;
    string s;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>s;
        if (s=="Tetrahedron") kq=kq+4;
        if (s=="Cube") kq=kq+6;
        if (s=="Octahedron") kq=kq+8;
        if (s=="Dodecahedron") kq=kq+12;
        if (s=="Icosahedron") kq=kq+20;
    }
    cout<<kq;
    return 0;
}
