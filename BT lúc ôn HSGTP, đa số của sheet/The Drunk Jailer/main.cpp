#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main()
{
    faster;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    // - Để một phòng được mở khóa, nó cần có số ước lẻ
    // => chỉ các bình phương mới có một số ước lẻ.
	// - kết quả của bình phương các số từ 1 đến N là
	//   các số chính phương có thứ tự từ 1 đến N
	// VD:
	//     STT: 1   2   3   4   5 ...
	//   số CP: 1   4   9   16  25 ..
	//=> nếu n là 5 thì của căn bậc 2 của 5 là 2.36...
    //   lấy cận dưới thì được 2
    //   => từ 1-5 có 2 số chính phương
    int t; cin>>t;
    while (t--){
        int n; cin>>n;
        double kq=floor(sqrt(n));
        cout<<kq<<endl;
    }


    return 0;
}

