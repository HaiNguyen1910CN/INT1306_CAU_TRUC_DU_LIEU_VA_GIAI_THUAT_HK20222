#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll pmod(ll a, ll b, ll MOD){
    ll res = 1;
    while (b){
        if (b % 2 == 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b /= 2;
    }
    return res;
}


ll f(ll a, ll x, ll m) {
    if (x == 0) return 0;
    if (x == 1) return 1 % m;
    if (x % 2 == 0) {
        ll half = f(a, x / 2, m), p = pmod(a, x / 2, m);
        return (half + half * p % m) % m;
    } else {
        ll prev = f(a, x - 1, m), p = pmod(a, x - 1, m);
        return (prev + p) % m;
    }
}

int main() {
    ll a, x, m; cin >> a >> x >> m;
    cout << f(a, x, m);
}
/* 
 * HƯỚNG GIẢI CHÍNH:
 * Bài toán yêu cầu tính S = A^0 + A^1 + ... + A^(X-1) modulo M.
 * Gọi f(X) là tổng của X phần tử đầu tiên của chuỗi.
 * 1. Nếu X chẵn (X = 2K): 
 *    Ta chia nửa dãy thành 2 phần bằng nhau: 
 *    (A^0 + ... + A^(K-1)) + (A^K + ... + A^(2K-1))
 *    Rút nhân tử chung A^K ở nửa sau, ta được:
 *    (A^0 + ... + A^(K-1)) + A^K * (A^0 + ... + A^(K-1))
 *    => Công thức: f(X) = f(K) + A^K * f(K)
 *
 * 2. Nếu X lẻ (X = 2K + 1): 
 *    Ta tách phần tử cuối cùng ra, phần còn lại là số lượng chẵn (X-1 phần tử):
 *    => Công thức: f(X) = f(X-1) + A^(X-1)
 */