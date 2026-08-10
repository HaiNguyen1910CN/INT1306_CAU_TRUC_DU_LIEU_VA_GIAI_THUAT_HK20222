#include<bits/stdc++.h>
using namespace std;

int LCP (string a, string b){
    int i = 0;
    while (i < min(a.length(), b.length()) && a[i] == b[i]) i++;
    return i;
}

int main(){
    int n; cin >> n;
    vector<pair<string, int>> s(n); //Gia tri va chi so goc
    for (int i = 0; i < n; ++i) {
        cin >> s[i].first;
        s[i].second = i;
    }
    sort(s.begin(), s.end());
    vector<int> ans(n, 0);
    ans[s[0].second] = LCP(s[0].first, s[1].first);
    ans[s[n - 1].second] = LCP(s[n - 1].first, s[n - 2].first);
    for (int i = 1; i < n - 1; ++i) ans[s[i].second] = max(LCP(s[i].first, s[i - 1].first), LCP(s[i].first, s[i + 1].first));
    for (int i = 0; i < n; i++) cout << ans[i] << endl;
}