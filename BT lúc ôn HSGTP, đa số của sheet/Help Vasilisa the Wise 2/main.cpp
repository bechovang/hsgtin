#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main()
{
    faster;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int h1,h2,c1,c2,ch1,ch2;
    cin>>h1>>h2>>c1>>c2>>ch1>>ch2;
    for (int s1=1;s1<=9;s1++){
        for (int s2=1;s2<=9;s2++) if (s2!=s1) {
            for (int s3=1;s3<=9;s3++) if (s3!=s1 and s3!=s2){
                for (int s4=1;s4<=9;s4++) if (s4!=s3 and s4!=s2 and s4!=s1){
                    if (s1+s2==h1 and s3+s4==h2 and s1+s3==c1 and s2+s4==c2 and s1+s4==ch1 and s2+s3==ch2){
//                        bool valid=true;
//                        for (int i=0;i<=9;i++){
//                            int dem=0;
//                            if (s1==i) dem++;
//                            if (s2==i) dem++;
//                            if (s3==i) dem++;
//                            if (s4==i) dem++;
//                            if (dem>1) valid=false;
//                        }
//                        if (valid==false) break;
                        cout<<s1<<' '<<s2<<endl;
                        cout<<s3<<' '<<s4;
                        return 0;
                    }
                }
            }
        }
    }
    cout<<-1;
    return 0;
}
