#include <bits/stdc++.h>
#define endl '\n'
#define faster ios::sync_with_stdio(0)

using namespace std;

int main()
{
    faster;
    freopen("BAI1.INP","r",stdin);
    freopen("BAI1.OUT","w",stdout);
    string s;
    getline(cin,s);
    string kq;
    for (int i=0;i<s.size();i++){
        for (char j='a';j<='z';j++){
            if (s[i]==j)
                cout<<s[i];
        }
        for (char j='A';j<='Z';j++){
            if (s[i]==j)
                cout<<s[i];
        }

    }





    return 0;
}
