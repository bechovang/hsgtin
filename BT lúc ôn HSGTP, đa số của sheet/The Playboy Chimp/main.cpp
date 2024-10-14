#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

// sửa lại
// A[] thành vector<int> A
// int lo = 1, hi = sizeA;
// thành int lo = 0, hi = sizeA-1;
int tknp(vector<int> a, int l, int r, int x) {
    while (r>=l) {
        int mid = l + (r-l)/2 ;  //<=> (l+r)/2 ghi kiểu kia để tránh tràn số
        if (a[mid]==x)
            return mid;
        if (a[mid] > x) // nếu a[mid]>x thì đi check phần nhỏ hơn <=> l -> mid-1
            r = mid-1;
        if (a[mid] < x)
            l = mid+1; // nếu a[mid]<x thì đi check phần lớn hơn <=> mid+1 -> r
    }
    // không tìm thấy giá trị x trong mảng a
    // thì trả về r <=> cận dưới
    // * r là cận dưới, l là cận trên
    return r;
}

int main()
{
    faster;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n; cin>>n;

    vector <int> b(n+1);
    vector <int> a(n+1);

    // nhập đề vào mảng b, đề cho mảng đã được sắp xếp tăng dần
    for (int i=0;i<n;i++){
        cin>>b[i];
    }

    // tạo ra mảng a để xóa các phân tử trùng lặp
    int dem=0;
    for (int i=0;i<n;i++){
        if (b[i]!=b[i+1]){
            a[dem]=b[i];
            dem++;
        }
    }
    n=dem;

    //xử lí q truy vấn
    int q; cin>>q;
    for (int i=0;i<q;i++){
        int g; cin>>g; // xử lí từng truy vấn
        int k=tknp(a,0,n-1,g); // dùng tknp tim vị trí k của g trong mảng a

        if (a[k]==g){ // trả về x
            if (k==0)
                cout<<'X'<<' '; // k=0 => ko có cận dưới. vì ko có số nào dưới nó
            else
                cout<<a[k-1]<<' '; //k!=0 => có cận dưới là a[k-1]

            if (k==n-1)
                cout<<'X'<<endl;// k=n-1 => ko có cận trên. vì ko có số nào trên nó
            else
                cout<<a[k+1]<<endl;//k!=n-1 => có cận trên là a[k+1]
        }

        else { // trả về cận dưới
            cout<<a[k]<<' '; // xuất cận dưới

            if (k==n-1)
                cout<<'X'<<endl; // k=n-1 => ko có cận trên. vì ko có số nào trên nó
            else
                cout<<a[k+1]<<endl;//k!=n-1 => có cận trên là a[k+1]
        }
//
//        if (a[k]>g){ // trả về cận trên
//            if (k==0)
//                cout<<'X'<<' '; // k=0 => ko có cận dưới. vì ko có số nào dưới nó
//            else
//                cout<<a[k-1]<<' '; //k!=0 => có cận dưới là a[k-1]
//
//            cout<<a[k]<<endl; // xuất cận trên
//        }

    }

    return 0;
}
