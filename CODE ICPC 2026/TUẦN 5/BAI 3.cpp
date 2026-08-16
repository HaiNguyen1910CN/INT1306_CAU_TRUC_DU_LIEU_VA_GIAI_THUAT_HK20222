#include <bits/stdc++.h>
using namespace std;

struct Point{
    int x, y;
};

int dist (Point p1, Point p2){
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

int main(){
    int n, d; 
    cin >> n >> d;
    vector <Point> a(n);
    for (int i = 0; i < n; i++) cin >> a[i].x >> a[i].y;
    //BFS
    vector <bool> check(n, false);
    queue <int> q;
    check[0] = true;
    q.push(0);
    while (!q.empty()){
        int u = q.front();
        q.pop();
        for (int v = 0; v < n; v++) {
            if (!check[v] && dist(a[u], a[v]) <= d * d) {
                check[v] = true;
                q.push(v); 
            }
        }
    }
    for(int i = 0; i < n; i++){
        if (!check[i]) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
}

