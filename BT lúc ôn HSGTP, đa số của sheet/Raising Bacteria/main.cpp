#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;

int q;
vector <ll> vk(101);
int kq=0;

int timkq(int n){
    kq++;
    for (int i=0;i<101;i++){
        if (vk[i]<n and vk[i+1]>n ){
            return timkq(n-vk[i]);
        }
        if (vk[i]==n ){
            return kq;
        }
    }
}

int main()
{
    faster;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin>>q;

    // tạo mảng số lượng nhân đôi của 1 vi khuẩn: 1,2,4,16,32,...
    int k=1;
    int dem=0;
    while(dem<=100){
        vk[dem]=k;
        k=k*2;
        dem++;
    }

    //đệ quy:
    //VD: 10
    // * tìm tiệm cận dưới trong mảng vk
    // => tiệm cận dưới là 8
    // => nếu có 1 vi khuẩn sẽ có thể tạo 8 vk, cao hơn sẽ quá 10
    // => cần thêm 10-8=2 vk nữa
    // => đệ quy timkq(2) lập lại y z, 1 lần đệ quy là thêm 1 vk
    // đệ quy đến khi nào số vi khuẩn thiếu trùng với phần tử của mảng vk

    // 10 vk là ngày đầu để 1 con
    // đến ngày 3 có 4 con để thêm 1 con là tg=5
    // đến ngày 4 là 10
    cout<<timkq(q);
    return 0;
}
