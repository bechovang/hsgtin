#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int d1,d2,d3,d4,d5,d6;

int main()
{
    faster;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n,m,x,y; cin>>n>>m>>x>>y;

    int cham_count[1005]={0};
    int thang_count[1005]={0};

    // dem so cham va thang tren cung 1 cot
    for (int i=0; i<n; i++){
        string s; cin>>s;
        for (int j=0;j<m;j++){
            if (s[j]=='.')
                cham_count[j+1]++;
            else
                thang_count[j+1]++;
        }
    }

    // tao prefix sum
    int pfcham[1005]={0};
    int pfthang[1005]={0};
    for (int i=1; i<=m; i++){
        pfcham[i]=pfcham[i-1] + cham_count[i];
        pfthang[i]=pfthang[i-1] + thang_count[i];
    }


	// QHD
	// có 2 lựa chọn cho mỗi cột
	// cham[i] là số pixel cần đổi ít nhất khi cột i là đổi các chấm (full thăng)
	// thang[i] là số pixel cần đổi ít nhất khi cột i là đổi các thăng (full chấm)

	// CT truy hồi:
	// thang[i] = min của cham[i-j] +tổng các pixel chấm từ i-j+1 đến i
	// cham[i] =  min của thang[i-j] +tổng các pixel thăng từ i-j+1 đến i
        // * với j đi từ x đến y
        // *tổng dùng prefix sum để tính

    //ý nghĩa của CT trên:
    // đi từ x cột liên tiếp rồi lùi qua trái đến y cột
    // cham[i-j] là lùi
    // +tổng các pixel chấm từ i-j+1 đến i : vì đang đổi chấm hết đoạn này nên cộng lại các chấm ở đoạn này


	//?  thang[i]=mincham và cham[i]=minthang Vì:
	//đang tìm số pixel ít nhất khi nó liên tiếp từ x đến y
	//nên các cột trước các cột liên tiếp này phải khác nó

	//? lưu ý để inf=1e7; Vì:
	// để LLONG_MAX bị lỗi khi tính toán



    int inf=1e7; //max 1000x1000
    int cham[1005]={0};
    int thang[1005]={0};

    for (int i=1; i<=m; i++){
        //chon min khi quet x den y tu i sang trai
        int mincham=inf;
        int minthang=inf;
        for (int j=x; j<=y;j++){
            if (i - j>=0){
                mincham=min(mincham, cham[i-j] + pfcham[i] - pfcham[i-j]);
                minthang=min(minthang, thang[i-j] + (pfthang[i] - pfthang[i-j]));
            }
        }

        thang[i]=mincham;
        cham[i]=minthang;

    }

    cout<<min(cham[m], thang[m]);

    return 0;
}

