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
    cin>>s;
    int i=0;
    int dem=0;
    while (i<s.size()){
        if (s[i]=='W' and s[i+1]=='U' and s[i+2]=='B'){
            if (dem!=0)
                cout<<' ';
            i=i+3;
        }
        else{
            cout<<s[i];
            i++;
            dem++;
        }
    }
    return 0;
}
