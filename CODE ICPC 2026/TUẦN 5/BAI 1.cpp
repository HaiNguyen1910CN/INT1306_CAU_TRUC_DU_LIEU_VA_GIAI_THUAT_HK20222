#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector <int> a(n), ans (n, 0);
    for (int i = 0; i < n; i++) cin >> a[i];
    bool p = true; //true: Cầm vàng
    for (int i = 0; i < n - 1; i++){
        if (p && a[i] > a[i + 1]){
            ans[i] = 1;
            p = false;
        } else if (!p && a[i] < a[i + 1]){
            ans[i] = 1;
            p = true;
        }
    }
    if (!p) ans[n - 1] = 1;
    for (int i = 0; i < n; i++) cout << ans[i] << " ";
}