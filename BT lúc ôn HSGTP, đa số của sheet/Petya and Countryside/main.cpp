#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cin.tie(0);
int main()
{
    faster;
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    //n<=1000 => 2 for lồng
    int n; cin>>n;

    int a[1001];
    for (int i=0;i<n;i++){
        cin>>a[i];
    }

    int maxx=INT_MIN;
    for (int i=0;i<n;i++){
        int x,y;
        int dem=0;
        //lùi
        int thap=a[i];
        for (x=i-1;x>=0;x--){
            if (a[x]>thap) // nếu cao hơn thì break
                break;
            else{
                thap=a[x]; // thấp hơn thì cập nhật thap
                dem++; // dem++ để đếm số ô nước mưa chảy xuống
            }


        }
        //tiến
        thap=a[i];
        for (y=i+1;y<n;y++){
            if (a[y]>thap)
                break;
            else{
                thap=a[y];
                dem++;
            }
        }

        maxx=max(maxx,dem+1 ); // cộng 1 để bù vô chính ô đó, vì 2 cái for là i-1 và i+1

    }

    cout<<maxx;
    return 0;
}
