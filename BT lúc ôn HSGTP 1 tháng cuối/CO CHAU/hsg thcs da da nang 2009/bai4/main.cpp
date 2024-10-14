#include <bits/stdc++.h>
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int fib[20]={1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765};
//cout<<fib[19]<<endl; //duoc may dem cho
int mark[20]={0};
int n;


int quaylui(int x){
    for (int i=0;i<=19;i++){

    }
}

int main()
{
    faster;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);




    // quay lui, chon cac so fib khac nhau
    cin>>n;
    int dem=0;
    int tg=0;

    while(tg<n){
        for (int i=0;i<=19;i++){
            if (tg+fib[i]<=n){
                dem++;
                tg=tg+fib[i];
            }
            else
                break;
        }
    }


    cout<<dem;



    return 0;
}





//int a,b,c,n;
//    a=2;
//    b=3;
//    while (a<10000){
//        cout<<a+b<<", ";
//        c=b;
//        b=a+b;
//        a=c;
//    }
//
//Backtracking(k) {
//	for([Mỗi phương án chọn i(thuộc tập D)]) {
//		if ([Chấp nhận i]) {
//			[Chọn i cho X[k]];
//			if ([Thành công]) {
//				[Đưa ra kết quả];
//			} else {
//				Backtracking(k+1);
//				[Bỏ chọn i cho X[k]];
//			}
//		}
//	}
//}

