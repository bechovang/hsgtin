#include <bits/stdc++.h>
#define endl '\n'
#define faster ios::sync_with_stdio(0)

using namespace std;

int main()
{
    faster;
    freopen("BAI2.INP","r",stdin);
    freopen("BAI2.OUT","w",stdout);
    string k1,k2,a,b;
    getline(cin,k1);
    getline(cin,k2);

    a=a+k1[0];
    for (int i=1;i<k1.size();i++){
        if (k1[i] != k1[i-1])
            a=a+k1[i];
    }

    b=b+k2[0];      // xử lí 20% cuối
    for (int i=1;i<k2.size();i++){
        if (k2[i] != k2[i-1])
            b=b+k2[i];
    }


    // để cho nso xử lí đc từ cuối
    a=a+' ';
    b=b+' ';

    int dem=0;

    while (a!=""){
        int i;
        int j;
        for (i=0;i<a.size();i++){
            if (a[i]==' ')
                break;
        }
        for (j=0;j<a.size();j++){
            if (b[j]==' ')
                break;
        }

        string s1,s2;
        s1=a.substr(0,i+1);
        s2=b.substr(0,j+1);

        a.erase(a.begin()+0, a.begin()+i+1);
        b.erase(b.begin()+0, b.begin()+j+1);

        if (s1==s2) dem++;
//        //debug
//        cout<<s1<<endl;
//        cout<<s2<<endl;
//        cout<<endl;
    }

//
//    //debug
//    cout<<k<<endl;
//    cout<<b<<endl<<endl;
//    cout<<a<<endl;


    cout<<dem;

    return 0;
}

//str.erase(str.begin() + start, str.begin() + end);

//          vị trí, số lượng
//     string substr2 = str.substr(1,6);
