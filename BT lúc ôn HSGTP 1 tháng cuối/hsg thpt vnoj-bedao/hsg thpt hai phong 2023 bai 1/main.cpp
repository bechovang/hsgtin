///bechovang

#include <bits/stdc++.h>
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;
int main()
{
    faster;
    freopen("INPUT.INP","r",stdin);
    freopen("OUTPUT.OUT","w",stdout);

    ll n; cin>>n;
    ll dem=0;
    for (ll i=1;i<=sqrt(n);i++){
        if (n%i==0)
            dem++;
    }

    if (floor(sqrt(n))*floor(sqrt(n)) == n)
        cout<<dem*2-1;
    else
        cout<<dem*2;


    return 0;
}
// ***CÓ CHUNG Ý TƯỞNG TỪ 1 BÀI ĐÃ LÀM RỒI

//Light, more light	UVA 10110

//link bài: https://vjudge.net/problem/UVA-10110
//- tìm số ước của n, nếu số ước chẵn thì yes,lẻ thì no => kt phải số chính phương không
//- số chính phương có số ước lẻ vì:
//khi tìm được ước số 1 chia hết cho n thì cũng sẽ tìm được ước số 2 = n/ ước số 1
//=> các ước luôn đi theo cặp => số ước chẵn
//nó chỉ lẻ khi ước số 1 = ước số 2 => ước số 1  * ước số 2 =n => n là số chính phương
