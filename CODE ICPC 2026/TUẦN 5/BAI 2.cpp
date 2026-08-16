#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX = 1000005; 
vector<int> primes;
bool is_prime[MAX];

void sieve() {
    fill(is_prime, is_prime + MAX, true);
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p < MAX; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i < MAX; i += p) is_prime[i] = false;
        }
    }
    for (int p = 2; p < MAX; p++) {
        if (is_prime[p]) primes.push_back(p);
    }
}

/*PTTSNT: X = (p1^a1) * (p2^a2) * ... * (pk^ak) --> Số ước của X là: (a1 + 1)(a2 + 1)...(ak + 1)
9 = 9.1 = 3.3
TH1: a1 = 8; a2 = a3 = ... = ak = 0 --> X = p^8
p^8 <= N => p <= N^(1/8) <= 10^(12/8) = 10^1.5 (khoảng 31.6)
TH2: a1 = a2 = 2; a3 = ... = ak = 0 --> X = (p1p2)^2
*/

void sol() {
    ll n, ans = 0; cin >> n;
    // Lấy tất cả các số nguyên tố thử xem mũ 8 có quá N chưa
    for (int p: primes) {
        ll p8 = 1;
        bool ok = true;
        for (int i = 0; i < 8; i++) {
            if (p8 > n / p) { //p8 * p > n? --> p8 > n/p?
                ok = false;
                break;
            }
            p8 *= p;
        }
        if (ok) ans++;
        else break; // 1 SNT mũ 8 > n thì các SNT sau cũng vậy
    }
    
    // Đếm các số có dạng (p1 * p2)^2 <= n, tương đương p1 * p2 <= sqrt(n)
    int m = sqrt(n), l = 0, r = primes.size() - 1;
    while (r > l && primes[r] > m) r--;
    while (l < r) {
        ll p1 = primes[l], p2 = primes[r];
        if (p1 * p2 <= m) {
            // Vì p1 * p2 <= m và mảng tăng dần, 
            // nên p1 nhân với bất kỳ số nào từ vị trí (left + 1) đến right đều sẽ <= m.
            // Số lượng các số p2 thỏa mãn chính là khoảng cách từ left đến right:
            ans += (r - l);
            // Xong p1 hiện tại, tăng left lên để xét số nguyên tố tiếp theo
            // p2 > p1 vì nếu p2 = p1 thì số có dạng p1 ^ 4 --> 5 ước
            l++;
        } else r--;
            // Nếu tích lớn hơn m, ta cần làm cho tích nhỏ đi bằng cách giảm p2 (lùi right)
    }
    cout << ans << "\n";
}

int main() {
    sieve();
    int t; cin >> t;
    while (t--) sol();
}