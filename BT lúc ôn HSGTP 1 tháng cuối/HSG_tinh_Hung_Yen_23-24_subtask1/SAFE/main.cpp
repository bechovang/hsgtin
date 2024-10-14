#include <bits/stdc++.h>
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

char in_hoa[27]={'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
char in_thuong[27]={'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
char chu_so[27]={'0', '1', '2', '3', '4', '5', '6', '7', '8', '9','0', '1', '2', '3', '4', '5', '6', '7', '8', '9','0', '1', '2', '3', '4', '5', '6'};

bool kt(string s){
    bool hoa=false;
    bool thuong=false;
    bool so=false;
    for (int i=0;i<s.size();i++){
        for (int j=0;j<27;j++){
            if (in_hoa[j] == s[i])
                hoa=true;
            if (in_thuong[j] == s[i])
                thuong=true;
            if (chu_so[j] == s[i])
                so=true;
        }

    }

    if (hoa==true and thuong==true and so==true)
        return true;
    else
        return false;
}


int main()
{
    faster;
    freopen("SAFE.INP","r",stdin);
    freopen("SAFE.OUT","w",stdout);
    string s; cin>>s;
    if (kt(s)==true)
        cout<<"YES";
    else
        cout<<"NO";

    return 0;
}
