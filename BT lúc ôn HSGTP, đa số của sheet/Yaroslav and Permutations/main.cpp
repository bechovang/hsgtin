#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main()
{
    faster;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n; cin>>n;
    if (n==1){
        cout<<"YES";
        return 0;
    }

    int hm[1001]={0};

    // đếm số lần xuất hiện của các số bằng hashmap
    for (int i=0;i<n;i++){
        int x; cin>>x;
        hm[x]++;
    }

    // sort số lần xuất hiện theo thứ tự giảm dần
    sort(hm,hm+1001,greater<int>());



    int hieu=hm[0];// số lần xuất hiện nhiều nhất

    // VD: số 3 xuất hiện 13 lần là số xuất hiện nhiều nhất
    // thì để mảng ko có 2 số 3 kề nhau phải có ít nhất 12 số khác 3 lấp vào giữa
    // => để thỏa đề:
    // lấy số lần xuất hiện của số xuất hiện nhiều nhất
    // trừ đi số lần xuất hiện của các số còn lại
    // nếu kq <=1 thì nhận.
    for (int i=1;i<=1000;i++){
        hieu=hieu-hm[i];
    }



    if (hieu <= 1) cout<<"YES";
    else cout<<"NO";

    return 0;
}
