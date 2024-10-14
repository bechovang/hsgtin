/*
 * 1. Reading (đọc đề): Direct
 *
 * 2. Samples (đọc test):
 * 		4 3:	ta có 2 splitter. 2 và 3. thêm chúng vào. 2 + 3 và có một cái dùng để nói nên 2+3-1 => 4
 * 		5 5:	ta cần 5 luồng ra và trong 5 cái splitter từ 1-5 luồng => 1 ( chỉ cần 1 cái splitter 5 luồng là đủ)
 * 		8 4: 	ta có các splitters 2, 3, 4 luồng. thêm tất cả chúng: 2 + 3 + 4 -2 => 7 < 8. nên đáp án là -1
 *
 * 	  Missed(bị bỏ qua):
 * 	  	none
 *
 * 	  Especial(đặc biệt):
 * 	  	nếu n=1 => không cần splitter nào => 0
 * 	  	nếu n<=k => chỉ cần 1 cái splitter n luồng là đủ => 1
 *
 * 3 - Input Properties (Các đặc điểm của input)
 * 		none
 *
 * 4- Constraints (giới hạn)
 * 		quá lớn: các thuật toán fake / BinarySch / MatrixPow => may ra mới xử lí được
 *
 * 5 - Processing(xử lí)
 * 		với một input lớn, dữ liệu ở giai đoạn giữa và đầu ra phải xử lí hết sức cẩn thận	=> sử dụng long long khi cần thiết
 */
//---------------------------------------------------------------------------------------------------------------------------------
/*
 * Problem type (thể loại bài toán):
 * 		minimization (tìm TH bé nhất). xem qua "minimization algorithms"
 * 		đây có vẻ là observation problem(toán thực tế: bài toán cần sự sự quan sát)..chúng ta cần tìm ra những cái facts (thông tin quan trọng)
 *
 * Observations (ta có thể quan sát thấy các fact sau)
 * 		- Các splitter được cho dưới dạng dãy tăng dần: 2 3 4...k
 * 		- Mỗi lần chúng ta kết nối 2 splitter, một luông trong số chúng trở thành một, nên phải loại bỏ 1 luồng.
 * 		- Nói chung nếu chúng ta kết nối M luồng thì M-1 luồng sẽ được sử dụng để kết nối
 * 		- Vì vậy, số lượng splitter của (a, b, c, d, e) = a + b + c + d + e - 4
 * 		- Cho trước K splitter, số luồng lớn nhất có thể có là (2 + 3 + 4 + ... + k) - k-2
 *      - Sử dụng CT số luồng lớn nhất, ta có thể xử lí được những impossible case(TH ko thể xử lí)
 * 		- nếu không phải TH đó, ta có thể phủ n hoặc không phủ được (phủ n là tổng = n)
 *
 * 		- Hãy nghĩ cụ thể:
 * 			- nếu n = 37 và k = 11
 * 			- thì chúng ta có thể có (2 + 3 + 4 ... 11) - 9
 * 			- Điều gì sẽ xảy ra nếu chúng ta trừ 1 từ mỗi splitter để loại bỏ con số 9 này
 * 			- (1 + 2 + 3 ... 10)..đây là 1 số lớn hơn đáp án trên, ta cần với mỗi 2 splitter loại bỏ 1 không phải 2
 * 			- Vì thế dơn giản là giảm n đi 1
 * 			- cụ thể như sau: 	  (2 + 3 + 4 ... 11) - 9    = N
 * 			                    = (2 + 3 + 4 ... k) - k - 2 = N
 * 			                    = (2 + 3 + 4 ... k-1)       = N-2
 * 			                    = (2 + 3 + 4 ... k-1) + 1   = N-2 + 1
 *                              = (1 + 2 + 3 ... k-1)  		= N-1
 *                              = (1 + 2 + 3 ... 10)  		= N-1
 * 			- Hãy để K = K-1 và N = N-1
 * 			- vấn đề của chúng ta bây giờ, với số từ 1-k, chúng ta có thể tìm tập con có tổng = N
 * 				- Người chơi hệ DP biết rằng đây đầy là bài toán tổng tập con = N có thể được giải bằng DP
 * 				- Nhưng với giới hạn này thì không cho phép cách làm đó
 */
//---------------------------------------------------------------------------------------------------------------------------------
/*
 * Phân tích thêm:
 *
 * 	- Hãy nghĩ về vấn đề mới của chúng ta: Cho N, K: tìm tập con có số lượng phần tử ít nhất có tổng = N
 * 		- Nếu N = 36 và K = 10
 * 		- Vì vậy chúng ta có các splitter với luồng ra là 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
 * 		- Vì chúng ta cần tìm số lượng ít nhất, vì thế ta lấy 10 trước. Bây giờ ta cần 26
 * 		- sau đó lấy 9 => 17. Tiếp theo lấy 8 => 9. Sau đó lấy 7 => 2. Tiếp theo là 6, nhưng nó lớn hơn 2
 * 		- Thay vì ta có 6, thì ta phải lấy 3
 * 		- Bây giờ, rõ ràng có 3 điều:
 * 			- Nếu tổng lớn hơn hoặc bằng N, thì chúng ta sẽ thực hiện được cách giải này
 * 			- Ta bắt đầu từ phần tử cuối và lấy các số đến khi số kế tiếp > hiệu
 * 			- Lúc này, nếu bạn trừ K phần tử, câu trả lời là K+1 nếu hiệu > 0
 * 			- Tuy nhiên, K = 10^9, chúng ta cần cần 1 phương án có tốc độ nhanh.
 *
 */
 //---------------------------------------------------------------------------------------------------------------------------------
/*
 * Một trong những thuật toán phù hợp với giới hạn của chúng ta là Binary Search. Chúng ta có thể sử dụng nó không?
 *		Chúng ta cần xác định hàm và đảm bảo đường đi của nó có thể là: 0 0 0 0 1 1 1...1 HOẶC 1 1 1 1 1 0 0 0 0 ..... 0
 *
 *	Hàm của chúng ta là gì: Có thể sử dụng X phần tử cuối cùng và có thể sử dụng thêm một phần tử nữa đủ để che phủ N không?
 *		Ví dụ trong bài toán của chúng ta (N = 36 và K = 10) sử dụng 4 phần tử cuối cùng và 3 đã đủ để tổng là 36
 *
 *	Định nghĩa hàm là: F(p) = Tổng của X phần tử cuối cùng <= N
 *		Nếu vậy, chúng ta có thể sử dụng chúng
 *		vì chúng ta muốn số lượng phần tử tối thiểu, chúng ta cần p có tổng lớn nhất <= N
 */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define faster ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;

ll sum(ll x,ll k){
    ll tg=x;
    ll p=1;
    while (x >= pow(k,p)){ // <=> floor(x/pow(k,p) )!=0
        ll u=( x/ pow(k,p) );
        tg=tg+u;
        p++;
    }
    return tg;
}

int tknp_minV(ll n, ll k){
    ll l=1; ll r=n;
    while (l<=r){ // l mà trùng r là chưa vòng lặp. do r=mid+1, nếu r=mid thì while (l<r)
        ll mid = l + (r-l)/2;
        ll tg=sum(mid,k);
        if (tg==n){
            return mid;
        }
        if (tg>n){
            r=mid-1;
        }
        if (tg<n){
            l=mid+1;
        }
    }

    return l; // r là cận dưới, l là cận trên
}

int main()
{
    faster;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    ll n,k; cin>>n>>k;

    if (n==1) cout<<1;
    else{
        cout<<tknp_minV(n,k);
    }

    return 0;
}
