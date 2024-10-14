#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int kttrung(string s){ // kt xem s có trùng với 4^k ko
    int dem=0;
    bool kt=false;
    for (int i=0;i<s.size();i++){
        if (s[i]=='0') dem++;
    }
    if (dem==s.size()-1){
        if (s.size()-1 ==1 or s.size()-1 ==2 or (s.size()-1-2 )%2==0 )
            kt=true;
    }

    return kt;

}

int main()
{
    faster;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    string s; cin>>s;

    if (s=="0" or s=="1"){// TH đặc biệt
        cout<<0;
        return 0;
    }

    // * 4^k ở cơ số 2 là "1" và n số "0"
    //     với n=1 hoặc n=2 hoặc (n-2) mod 2=0

    // * ở cơ 2 số có 1 ở đầu và còn lại là 0 là số nhỏ nhất có n chữ số
    //     VD: 100 (cơ số 2) là số nhỏ nhất có 3 chữ số
    //         => 100(4) < 101(5) < 110(6) < 111(7)

    // * nên ta chỉ cần quan tâm số chữ số của s
    //   <=> s > "số 1 ở đầu và còn lại là 0".
    //  và quan tâm thêm s có trùng 4^k ko
    //   <=> s= "số 1 ở đầu và còn lại là 0"

//*Trong cơ số 2, các số có số 1 ở đầu còn lại là 0.
//  Thì ở cơ số 10 là các số 2^k.
//  VD: 10(2) 100(4) 1000(8) 10000(16) 100000(32) 1000000(64) ...
//=> số thứ 1,2 trùng với 4^k. => đ.án = 1 - trùng
//=> Các số trùng với 4^k tiếp theo cách nhau 1 đơn vị.
//VD: 10000(16) 1000000(64) ... => đ.án = (n-1-2 )/2 +2 - trùng


    if (s.size()-1 ==1) cout<<1-kttrung(s);
    else if (s.size()-1 ==2) cout<<2-kttrung(s);
    else cout<< ( s.size()-1-2 )/2 +2 - kttrung(s);
    return 0;
}
