#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main()
{
    faster;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    string a,b; cin>>a>>b; // a là chữ trên cân, b là chữ ko trên cân
    string l,r;
    // tạo 2 string l và r thể hiện 2 bên cân
    bool kt=true;
    int left=0;
    int right=0;
    for (int i=0;i<a.size();i++){
        if (a[i]=='|'){
            kt=false;
            continue;
        }
        if (kt==true)
            l=l+a[i];
        if (kt==false)
            r=r+a[i];

    }

    // cho từng chữ của b lên đều 2 bên cân
    for (int i=0;i<b.size();i++){
        if (l.size() < r.size())
            l=l+b[i];
        else if (l.size() > r.size())
            r=r+b[i];
        else if (l.size() == r.size())
            l=l+b[i];
    }

    // in ra kq, nêu 2 bên cân ko bằng thì in Impossible
    if ( (l.size() != r.size()) )
        cout<<"Impossible";
    else {
        cout<<l<<'|'<<r;
    }
    return 0;
}
