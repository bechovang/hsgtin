#include <bits/stdc++.h>
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main()
{
    faster;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    string s; cin>>s;
    char k; cin>>k;


    vector <int> v;
    for (int i=0;i<s.size();i++){
        if (s[i] == k){
            v.push_back(i+1);//***
        }
    }

    if (v.size()==0){
        cout<<"Khong co";
        return 0;
    }

    cout<<v.size()<<endl;
    for (auto x: v){
        cout<<x<<' ';
    }



    return 0;
}


