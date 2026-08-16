#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/* Đặt số lần kích hoạt động cơ là k --> Tổng thời gian tiếp đất là: T(k) = k * B + A / sqrt(k + 1)
Đặt x = k + 1, ta có: T(x) = (x - 1) * B + A / sqrt(x) = x*B - B + A * x^(-0.5)
T'(x) = B - 0.5 * A * x^(-1.5) = 0 <=> B = A / (2 * x * sqrt(x)) <=> x * sqrt(x) = A / (2 * B)
<=> x^(1.5) = A / (2 * B) <=> x = (A / 2B)^(2/3)
Vậy k_opt = x - 1 = (A / 2B)^(2/3) - 1
*/
int main() {
    ll a, b;
    cin >> a >> b;
    ll k_opt = cbrtl(a / (2.0L * b)) * cbrtl(a / (2.0L * b)) - 1;
    long double ans = a;
    ll st = max(0LL, k_opt - 100), en = k_opt + 100;
    for (ll k = st; k <= en; k++) {
        long double cur = (long double)k * b + (long double)a / sqrtl(k + 1.0L);
        if (cur < ans) ans = cur;
    }
    cout << fixed << setprecision(6) << ans << "\n";
}

