///bechovang

#include <bits/stdc++.h>
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

vector <char> s;
int main()
{
    faster;
    freopen("SOTRANG.INP","r",stdin);
    freopen("SOTRANG.OUT","w",stdout);

    s.push_back('_'); //index1

    int dem=4;
    for (int i=4;i<=1000000;i++){
        string a=to_string(i);
        for (int i=0;i<a.size();i++)
            s.push_back(a[i]);
        if (i==10) cout<<s.size()-1<<endl;
        if (i==11) cout<<s.size()-1<<endl;
        if (i==99) cout<<s.size()-1<<endl;

        if (i==100) cout<<s.size()-1<<endl;
        if (i==101) cout<<s.size()-1<<endl;
        if (i==999) cout<<s.size()-1<<endl;
//        if (i==999) cout<<s.size()-1<<endl;
//        cout<<endl;

        if (i==1000) cout<<s.size()-1<<endl;
        if (i==1001) cout<<s.size()-1<<endl;
        if (i==9999) cout<<s.size()-1<<endl;
//        if (i==9999) cout<<s.size()-1<<endl;
//        cout<<endl;

        if (i==10000) cout<<s.size()-1<<endl;
        if (i==10001) cout<<s.size()-1<<endl;
        if (i==99999) cout<<s.size()-1<<endl;
//        if (i==99999) cout<<s.size()-1<<endl;
//        cout<<endl;

        if (i==100000) cout<<s.size()-1<<endl;
        if (i==100001) cout<<s.size()-1<<endl;
        if (i==999999) cout<<s.size()-1<<endl;
//        if (i==999999) cout<<s.size()-1<<endl;
//        cout<<endl;

    }

//    for (auto x:s){
//        cout<<x;
//    }
//    cout<<endl;







    return 0;
}
