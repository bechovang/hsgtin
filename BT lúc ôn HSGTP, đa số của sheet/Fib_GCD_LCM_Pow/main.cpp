/*
 *
 *
 ******************************************** Giấy phép *******************************************
 * 																								*
 * Tệp này là một phần của Chuỗi Video Giải thuật tiếng Ả Rập											*
 *	Do kỹ sư Mostafa Saad thực hiện, Trợ giảng tại Đại học Cairo - FCI						*
 * 																								*
 *	Có sẵn trên Kênh YouTube của tôi: http://www.youtube.com/user/nobody123497?feature=mhee		*
 * 																								*
 * Bạn có thể sử dụng nó bất cứ lúc nào, cho bất kỳ lý do gì, bằng bất kỳ cách nào, mà không có bất kỳ nghĩa vụ nào.	*
 * 																								*
 * 																								*
 * Trong trường hợp phát hiện sai sót, vui lòng thông báo cho tôi qua email: mostafa.saad.fci@gmail.com		*
 * 																								*
 * Mostafa Saad Ibrahim © 2013																	*
 * 																								*
 ************************************************************************************************
 *
 *
 */


 /*
Nội dung
1- Chuỗi Fibonacci
2- Ước chung lớn nhất và Bội chung nhỏ nhất
3- Hoán vị và Tổ hợp
4- Số Stirling và Số Bell
5- Tính toán: a^p
6- Tính toán: a^1 + a^2 + .... a^p

Tải về Bảng phương trình (không nhớ nguồn): http://dl.dropbox.com/u/14991955/MathEquSheet.pdf

Vấn đề: UVA(10368, 369, 412, 11000, 11417, 10229, 10892, 11388, 10717)

Liên kết
http://community.topcoder.com/tc?module=Static&d1=tutorials&d2=combinatorics
http://en.wikipedia.org/wiki/Fibonacci_number
http://oeis.org/A000045
http://en.wikipedia.org/wiki/Greatest_common_divisor
http://en.wikipedia.org/wiki/Euclidean_algorithm
http://en.wikipedia.org/wiki/Least_common_multiple
*/

#include<set>
#include<map>
#include<list>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<complex>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
typedef long long ll;
#define aint(v)				((v).begin()), ((v).end())
#define sz(v)				((int)((v).size()))
#define clr(v, d)			memset(v, d, sizeof(v))
#define rep(i, v)		for(int i=0;i<sz(v);++i)
#define lp(i, n)		for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)	for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)	for(int i=(j);i>=(int)(n);--i)
#define repa(v)				lpi(i, 0, sz(v)) lpi(j, 0, sz(v[i]))
#define P(x)				cout<<#x<<" = { "<<x<<" }\n"
#define pb					push_back
#define MP					make_pair

#define all(v)			((v).begin()), ((v).end())
#define sz(v)			((int)((v).size()))
#define clr(v, d)		memset(v, d, sizeof(v))
#define rep(i, v)		for(int i=0;i<sz(v);++i)
#define lp(i, n)		for(int i=0;i<(int)(n);++i)
#define lpi(i, j, n)	for(int i=(j);i<(int)(n);++i)
#define lpd(i, j, n)	for(int i=(j);i>=(int)(n);--i)
typedef long long ll;

/*------------------------------------------------------------------------------------------------------------*/

// Số Fibonacci: F(n) = F(n-1) + F(n-2) với F(0) = 0 và F(1) = 1

int fib(int n)
{
	if(n <= 1)
		return n;

	return fib(n-1) + fib(n-2);
}

void iterativeFib() // khử đệ quy
{
	int a = 0, b = 1;
	for (int i = 2; i < 10; ++i) {
		int c = a+b;
		a = b;
		b = c;
	}
}

long long Fib[]={0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987,
	1597, 2584, 4181, 6765,  10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811,
	514229, 832040, 1346269, 2178309, 3524578,  5702887, 9227465, 14930352, 24157817,
	39088169, 63245986, 102334155, 165580141, 267914296, 433494437, 701408733,
	1134903170, 1836311903};

// Fibonacci: Tăng trưởng mũ.
// Có nhiều điều thú vị trên web "The On-Line Encyclopedia of Integer Sequences" : http://oeis.org/A000045

/*------------------------------------------------------------------------------------------------------------*/

// Ước chung lớn nhất: GCD
// gcd(45, 10) = 5	thì 45%5 = 10%5 = 0		và không thể tìm n > 5 sao cho  45%n = 10%n = 0
//
// Chỉ vậy thôi à? Có thêm thông tin gì nữa không? KHÔNG
// nếu a%n = 0 & b%n = 0	THÌ (a+b)%n = 0	và (a-b)%n = 0		vì (a+b)%n = (a%n+b%n)%n = (0+0)%n = 0
// DO ĐÓ
// gcd(45, 10) = gcd(35, 10) = gcd(25, 10) = gcd(15, 10) = gcd(5, 10) = 5
// gcd(10, 5) = gcd(5, 5) = gcd(5, 0) = 5
//
// Rồi chúng ta đã tìm ra một thuật toán!
//		function gcd(a, b)
//			if a = 0
//			   return b
//			while b ? 0
//				if a > b
//				   a := a - b
//				else
//				   b := b - a
//			return a
//
// WAIT: Chúng ta chỉ cần luôn giữ số nhỏ hơn từ số lớn hơn, số lớn sẽ trở thành số nhỏ hơn, và sau đó thực hiện ngược lại
// Làm thế nào để thực hiện việc chuyển này nhanh chóng? gcd(45, 10) = gcd(45%10, 10)	-> đơn giản là loại bỏ các chu kỳ nhỏ trong 1 bước
// Sau đó, mã nguồn dễ dàng trở thành

int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

// Còn về BCNN: Bội số chung nhỏ nhất
// Đó là bội số đầu tiên của 2 số.
// Hãy thử một số biểu diễn theo thừa số nguyên tố cho các số a, b
// a = 2^3 * 7^6
// b = 2^5 * 7^2
//
// để có được UCLN, chúng ta cần ít nhất của các lũy thừa của 2 và ít nhất của các lũy thừa của 7
// ucln = 2^min(3, 5) * 7^min(6, 2)
//
// còn về BCNN? chúng ta cần nhiều nhất
// BCNN = 2^max(3, 5) * 7^max(6, 2)
//
// cho a, b, và ucln(a, b) thì làm sao để tính BCNN(a, b)
//
// còn về a*b = 2^(3+5) * 7^(6+2)
// và chúng ta biết rằng ucln = 2^min(3, 5) * 7^min(6, 2)
//
// Do đó BCNN = a*b / ucln.

/*------------------------------------------------------------------------------------------------------------*/

// Hoán vị: của một tập hợp các đối tượng: là một sắp xếp của những đối tượng đó vào một thứ tự cụ thể.
// thứ tự có ý nghĩa (có xét đến)
// Ví dụ với tập hợp{1,2,3}, gọi là (1,2,3), (1,3,2), (2,1,3), (2,3,1), (3,1,2), và (3,2,1) -> 3! -> n!
//
// Làm thế nào? Quy tắc nhân
// Bước đầu tiên chúng ta có n lựa chọn, trong bước thứ 2, chúng ta chỉ được phép n-1, bước thứ ba n-2
// Sau đó chúng ta có n * n-1 * n-2 ... 1 cách = p(n) = n! (CT tổ hợp)
//
// còn nếu chúng ta cần sắp xếp r phần tử. Cùng cách: n x (n-1) x (n-2) x .....x (n- r + 1)
// P(n, r) = n! / (n-r)! (CT chỉnh hợp)
//
// Hoặc nghĩ theo một cách khác: đó là có bao nhiêu cách chọn r phần tử, và cho mỗi phần tử thực hiện r! hoán vị
// Đó là P(n, r) = C(n, r) * r! (P là chỉnh hợp, A là tổ hợp)
//
// còn về hoán vị cho phép lặp lại? Khi đó luôn có thể chọn điều bạn muốn pr(n) = n^n
// hoán vị cho phép lặp lại (tập hợp{1,2,3} có thể có: (1,1,3), (1,1,1), ...)

// Tổ hợp: Số cách chọn ra r phần tử không có thứ tự từ n phần tử
// thứ tự không quan trọng (ko xét đến)
//
// Làm thế nào để tính toán?
// P(n, r) = C(n, r) * r!
// n! / (n-r)! = C(n, r) * r!
// C(n, r) = n! / ( (n-r)! * r!)
//
// Cũng dễ dàng viết một đệ quy

// Hãy thử một số tính toán
// C(1000, 2) = 499500
// C(1000, 999) = C(1000, 1) = 1000
// C(66, 33) = 7219428434016265740
// C(68, 34) = Tràn số tại long long
// lưu ý, dựa trên việc hủy các giai thừa, chúng ta có thể có giá trị nhỏ hoặc lớn.

/*------------------------------------------------------------------------------------------------------------*/

// Nhiều hàm quan trọng và thú vị để biết

// Số Stirling lần thứ nhất: số hoán vị của n phần tử với k chu trình hoán vị

// Số Stirling lần thứ hai: số cách chia một tập hợp n phần tử thành k nhóm.
// Ví dụ tập hợp{1, 2, 3, 4, 5} có thể được chia thành {1, 3, 5} {2, 4}

// Số Bell: số cách chia tập hợp có kích thước n
// Ví dụ tập hợp{1, 2, 3, 4} có thể được chia {{1}, {3,2, 4}} hoặc {{2, 4} {1, 3}}
// LƯU Ý: các phân vùng {{1, 2},{3, 4}} và {{3, 4}, {2, 1}} được tính một lần. KHÔNG CÓ VẤN ĐỀ VỀ THỨ TỰ

/*------------------------------------------------------------------------------------------------------------*/

// Làm thế nào để tính 5^3? Đơn giản, lặp 3 lần, nhân 1 lần 5		O(power)


// Chia để trị
// 10^16 = (10^8)^2
// 10^17 = (10^8)^2 * 10
int pow(int b, int p) { // O(log(p) cơ số 2)
	if (p == 0) return 1;
	int sq = pow(b, p / 2);
	sq = sq * sq;

	if (p % 2 == 1)
		sq = sq * b;

	return sq;
}

long long powll(long long b, long long p) { // O(log(p) cơ số 2)
	if (p == 0) return 1;
	long long sq = powll(b, p / 2);
	sq = sq * sq;

	if (p % 2 == 1)
		sq = sq * b;

	return sq;
}

// Còn về tính toán: (a^1+a^2+a^3+a^4+a^5+a^n) ???

// Hãy thử với số mũ chẵn
// (a^1+a^2+a^3+a^4+a^5+a^6) 	   = (a^1+a^2+a^3)+(a^1*a^3+a^2*a^3+a^3*a^3)
// (a^1+a^2+a^3)+a^3*(a^1+a^2+a^3) = (a^1+a^2+a^3)*(1+a^3)
// (a^1+a^2+a^3)+a^3*(a^1+a^2+a^3) = (a^1+a^2+a^3)*(1+ a^1+a^2+a^3 - (a^1+a^2))
//

// còn về n lẻ thì sao
// (a^1+a^2+a^3+a^4+a^5+a^6+a^7)   = a + a*(a^1+a^2+a^3+a^4+a^5+a^6)
//								   = a(1+(a^1+a^2+a^3+a^4+a^5+a^6))


ll sumPows(ll a, int k) { // Trả về a^1+a^1+a^2+.....a^k	trong O(k)
	if (k == 0)
		return 0;

	if (k % 2 == 1)
		return a * (1 + sumPows(a, k - 1));

	ll half = sumPows(a, k / 2);
	return half * (1 + half - sumPows(a, k / 2 - 1));
}

/*------------------------------------------------------------------------------------------------------------*/

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    cout<<powll(7,5);


//    cout << "Hello world!" << endl;
    return 0;
}
