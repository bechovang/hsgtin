#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main()
{
    //- Nếu sử dụng một mảng có kích thước N × M
    //sẽ chắc chắn vượt quá giới hạn thời gian và bộ nhớ,
    //vì vậy chúng ta không thể mô phỏng nó một cách ngây thơ.
    //- Số lượng truy vấn T và số lượng ô rác(waste) K
    //không nhiều hơn 1,000, vì vậy đủ để trả lời mỗi truy vấn
    //trong thời gian O(K.T).
    // O(K.T)
    faster;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,m,k,t; cin>>n>>m>>k>>t;

    //nhập ô rác k vảo mảng
    vector <pair<int,int>>a;
    for (int i=1;i<=k;i++){
        int x,y; cin>>x>>y;
        a.push_back({x,y});
    }
    //- đọc truy vấn (a,b)
    while (t--){
        int x,y; cin>>x>>y;
        bool is_waste=false;
        int dem=0;
        for (int i=0;i<a.size();i++){ //+ chạy for qua mảng ô rác
            if (x>=a[i].first and y>a[i].second){ //* kt xem các ô rác đang xét có ở trước (a,b) ko:
                dem++;
            }
            else if (x>a[i].first){
                dem++;
            }
            if (x==a[i].first and y==a[i].second){ //* kt xem (a,b) có phải ô rác ko? phải thì in waste,
                cout<<"Waste"<<endl;
                is_waste=true;
                break;
            }
        }


        if (is_waste==false){ //+ tính toán ra loại cây ở ô a(a,b)
            int kq= (x-1)*m + y; // số lượng ô từ (1,1) --> (a,b)
            kq= kq - dem; // trừ đi ô rác
            kq= kq%3; // mod 3 để biết ra cây gì, vì nó theo thứ tự cà rốt - kiwi - nho
            switch (kq){
                case 0:
					cout << "Grapes" << endl;
					break;
				case 1:
					cout << "Carrots" << endl;
					break;
				case 2:
					cout << "Kiwis" << endl;
            }
        }
    }



    return 0;
}
