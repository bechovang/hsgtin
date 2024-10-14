#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main()
{
    faster;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,k; cin>>n>>k;

    long long tg=0; // tg = số lượng phần tử của tất cả tập hợp
    for (int i=0;i<n;i++){
        int x,y; cin>>x>>y;
        tg=tg + (y-x+1);
    }

    if (tg % k == 0){ // thỏa đề luôn
        cout<<0;
    }
    else {
        long long kq;
        kq= k - (tg % k); // tìm được phần cần cộng thêm để chia hết cho k
        cout<<kq;
    }

    return 0;
}

