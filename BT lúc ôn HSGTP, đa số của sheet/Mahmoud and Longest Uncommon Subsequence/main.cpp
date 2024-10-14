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
    string a,b,x,y;
    map <char,int> hm;
    map <char,int> hm2;
    cin>>x>>y;
    if (x!=y) cout<<max(x.size(),y.size());
    else cout<<-1;
    return 0;
}
