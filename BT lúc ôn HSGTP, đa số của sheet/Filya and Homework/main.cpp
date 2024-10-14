// Source: https://u...content-available-to-author-only...o.guide/general/io

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main() {
    faster;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

	int n; cin>>n;
	int a[n+1];
	//set cả mảng mới =-1
	for (int i=0;i<n;i++){
		a[i]=-1;
	}
	//nhập vào mảng
	for (int i=0;i<n;i++){
		cin>>a[i];
	}


    //xóa số trùng
	sort(a,a+n);
	for (int i=0;i<n;i++){
		if (a[i]==a[i+1]){
			a[i]=-1; // ko de a[i+1] dc ?
		}
	}

	sort(a,a+n);

	int dem=0;
	for (int i=0;i<n;i++){
		if (a[i]!=-1){
			dem++;
		}
	}


	// sau khi lọc số trùng
	// nếu thỏa 3 số khác nhau có 2 khoảng cách đều nhau
	// hoặc 1 số, 2 số
	// thì yes ko thì no
    if (dem==3){
        int kcach1= abs( a[n-1] - a[n-2]);
        int kcach2= abs( a[n-2] - a[n-3]);
//        int kcach3= abs( a[n-1] - a[n-3]);
        int demkc=0;
        if (kcach1==kcach2) // vì đã sort nên 3 khoảng và chỉ có 2 khoảng có thể xảy ra
            cout<<"YES";
        else
            cout<<"NO";
    }
    else{
        if (dem<=2)
            cout<<"YES";
        else
            cout<<"NO";
    }
}
