#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

char s[100001];
int main()
{
    faster;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>s;
    cout<<s;
//    cout<<strlen(s);
//    reverse(s.begin(),  s.end());
    for (int i=strlen(s)-1;i>=0;i--){
        cout<<s[i];
    }
    return 0;
}
