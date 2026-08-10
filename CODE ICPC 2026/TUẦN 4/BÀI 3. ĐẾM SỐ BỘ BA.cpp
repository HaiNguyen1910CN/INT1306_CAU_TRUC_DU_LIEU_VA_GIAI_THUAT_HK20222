#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ll n, cnt = 0; cin >> n;
    for (ll a = 1; a * a * a <= n; ++a) {
        for (long long b = a; a * b * b <= n; ++b) {
            long long max_c = n / (a * b);
            cnt += max_c - b + 1;
        }
    }
    cout << cnt;
}
/* 
 * Cách tối ưu (Dựa vào điều kiện A <= B <= C):
 * 1. Vì A <= B <= C, giá trị lớn nhất mà A có thể đạt được là khi A = B = C. 
 *    Tức là A * A * A <= N => A <= Căn bậc ba của N. (Tối đa A chạy đến 10^4).
 * 2. Tương tự, khi đã cố định A, giá trị lớn nhất mà B có thể đạt được là khi B = C.
 *    Tức là A * B * B <= N => B <= Căn bậc hai của (N / A).
 * 3. Khi đã cố định A và B, ta không cần dùng vòng lặp cho C nữa. 
 *    Ta biết C lớn nhất có thể là max_c = N / (A * B). 
 *    Và vì C >= B, số lượng giá trị hợp lệ của C sẽ trải dài từ B cho đến max_c.
 */