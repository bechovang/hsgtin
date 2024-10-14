#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main()
{
    faster;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ll n;
    cin>>n;
    string s,hoa;
    cin>>s;
    for (ll i=0;i<n;i++){
        char k=toupper(s[i]);
        hoa=hoa+k;
    }
//    cout<<hoa<<endl;
    sort(hoa.begin(),hoa.end());
    s="";
    for (ll i=0;i<n;i++){
        if(hoa[i]!=hoa[i+1]){
            s=s+hoa[i];
        }
    }
//    cout<<s.size()<<endl;

    if (s.size()==26) cout<<"YES";
    else cout<<"NO";

    return 0;
}
