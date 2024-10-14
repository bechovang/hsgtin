#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

/* Khi bạn có một std::set chứa các cặp (std::pair) trong C++,
các cặp này sẽ được tự động sắp xếp theo thứ tự tăng dần dựa
trên toán tử < (so sánh). Thường, thứ tự sắp xếp của các cặp sẽ
được xác định dựa trên phần tử đầu tiên của cặp (first), sau đó sẽ
dựa vào phần tử thứ hai của cặp (second) nếu các phần tử đầu tiên bằng nhau.*/

typedef long long ll;
int main()
{
    faster;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    ll n, l; cin>>n>>l;

    vector <pair<ll,ll>> a; // pair: giá chênh lệch khi KM và ko KM - khi không KM
    // hàng bán được khi KM là: min(2*hang,khach)
    // hàng bán được khi ko KM là: min(hang,khach)
    // ta cần chọn ngày có sự chênh lệch khi KM và khi ko KM cao nhất để tối ưu lợi nhuận
    // dùng vector pair vì để khi sắp xếp theo cái đầu thì cái 2 cx di chuyển theo
    for (int i=0;i<n;i++){
        ll hang, khach; cin>>hang>>khach;
        a.push_back({min(2*hang,khach)-min(hang,khach), min(hang,khach)});
    }
    // sắp xếp lại theo chênh lệch KM va ko KM để chọn ngày có lợi nhuận cao nhất
    sort(a.rbegin(), a.rend()); // sort theo giảm dần
    ll kq=0;
    for(ll i = 0; i < a.size(); i++) {
		if(i < l)
            kq = kq + (a[i].first + a[i].second);
		else
            kq = kq + a[i].second;
	}
    cout<<kq;
    return 0;
}
