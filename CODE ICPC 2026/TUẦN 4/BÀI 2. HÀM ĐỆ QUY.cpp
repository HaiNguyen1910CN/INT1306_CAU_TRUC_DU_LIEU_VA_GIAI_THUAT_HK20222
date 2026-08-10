#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Key: k, Value: F(k)
map<ll, ll> mem;

ll F(ll n) {
    if (n == 0) return 1;
    if (mem.count(n)) return mem[n];
    mem[n] = F(n / 2) + F(n / 3);
    return mem[n];
}

int main() {
    ll n; cin >> n;
    cout << F(n);
}