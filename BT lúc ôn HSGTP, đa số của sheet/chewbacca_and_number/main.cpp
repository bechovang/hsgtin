#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main()
{
    faster;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    string s; cin>>s;

    // xử lí inp có 0 ở đầu : 011, 012, ..
    int k=0;
    for (k=0;k<s.size();k++){
        if (s[k]!='0')
            break;
        if (k==s.size()-1)
            cout<<0;
    }

    // xử lí từng số:
    // * s[i] <= 4 : in s[i].
    // * s[i] > 4 : in 9 - s[i]. vì >4 thì 9 - s[i] nhỏ hơn s[i]
    // TH đặc biệt:
    // * s[i]=9 và i=0 => số 9 ở đàu => phải in ra 9,ko đc in ra 0 ở đầu
    for (int i=k; i<s.size();i++){
        if ( (s[i] - '0') <= 4 )
            cout<<s[i];
        else
            if (s[i]=='9' and i==0)
                cout<<9;
            else
                cout<< 9 - (s[i]-'0');
    }
    return 0;
}
