#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);


string cutpaste(string s, int cut1, int cut2, int paste1){
    string a;
    a=s.substr(cut1,cut2);
    s.erase(cut1,cut2-cut1+1);
    s.insert(paste1-1,a);
    return s;


}
int main()
{
    faster;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    string s; cin>>s;

    int dem=0;
    int i=0;
    int j=0;
    while (i!=s.size() and j!=s.size()){
        i++;
        if (s[i]=='1' and s[i-1]!='1'){
            for (j=i;j<s.size();j++){
                if (s[j+1]!='1'){ //j+1 de no dung ngay so 1
                    cout<<i<<' '<<j<<endl;
                    s=cutpaste(s,i,j,i);
                    cout<<s<<endl;

                    j++;
                    i=j;
                    break;
                }
            }
        }
    }

//
//    for (i=0; i<s.size();i++){
//        if ( (s[i]=='2' and s[i+1]=='0') or (s[i]=='0' and s[i+1]=='2') ){
//            sort(s,s.begin+i,s.begin+)
//        }
//    }

    sort(s.begin()+6, s.begin()+12);
    cout<<s<<endl;


//    cout<<s<<endl;
//    string a=s.substr(1,4);
//    cout<<a<<endl;
//    s.erase(1,4-1+1);
//    cout<<s<<endl;
//    s.insert(1-1, a);
//    cout<<s<<endl;




    return 0;
}
