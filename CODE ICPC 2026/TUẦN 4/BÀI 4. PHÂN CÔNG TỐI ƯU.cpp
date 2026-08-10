#include <bits/stdc++.h>
using namespace std;
using ll = long long;
/* 
 * HƯỚNG GIẢI CHÍNH: Quy hoạch động trạng thái (Bitmask DP)
 * Vì N <= 20, ta có thể dùng một số nguyên (mask) để biểu diễn tập hợp các công nhân đã được chọn.
 * - Bit thứ i bằng 1: Công nhân i ĐÃ được phân công.
 * - Bit thứ i bằng 0: Công nhân i CHƯA được phân công.
 * Trạng thái dp[mask] lưu tổng điểm lớn nhất đạt được khi tập hợp công nhân (trong mask) được phân công.
 * 
 * Nếu có K bit 1 trong mask, đồng nghĩa với việc có K công nhân đang được chọn 
 * để làm K nhiệm vụ đầu tiên (từ nhiệm vụ 0 đến K-1).
 */

struct Bonus {
    ll p, a;
};

int cmp(Bonus a, Bonus b){
    return a.p < b.p;
}

ll s[25][25];

int main() {
    int n, b; cin >> n >> b;
    // bonuses[k] lưu danh sách các phần thưởng khi hoàn thành xong k nhiệm vụ đầu
    vector<vector<Bonus>> bonuses(n + 1);
    for (int i = 0; i < b; ++i) {
        int k; ll p, a;
        cin >> k >> p >> a;
        bonuses[k].push_back({p, a});
    }
    for (int i = 1; i <= n; ++i) sort(bonuses[i].begin(), bonuses[i].end(), cmp);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) cin >> s[i][j];
    }
    vector<long long> dp(1 << n, -1);
    dp[0] = 0; // Trạng thái chưa phân công ai có 0 điểm
    // Duyệt qua tất cả các trạng thái phân công
    for (int mask = 1; mask < (1 << n); ++mask) {
        int k = __builtin_popcount(mask); // Số nhiệm vụ đã được phân công
        ll max_val = -1;
        for (int i = 0; i < n; ++i) {
            if ((mask >> i) & 1) { // Nếu công nhân i có trong tập mask
                int prev_mask = mask ^ (1 << i);
                if (dp[prev_mask] != -1) max_val = max(max_val, dp[prev_mask] + s[i][k - 1]);
            }
        }
        if (max_val != -1) {
            ll cur = max_val;
            for (auto bonus: bonuses[k]) {
                if (cur >= bonus.p) cur += bonus.a;
            }
            dp[mask] = cur;
        }
    }
    cout << dp[(1 << n) - 1];
}