#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n, m, t, x, y, ans;
queue<pair<int, int>> q;
bool visited[1000][1000];

bool valid(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < m;
}

void check(int x, int y) {
    if(!visited[x][y] && valid(x, y)) {
        q.push({x, y});
        visited[x][y] = 1;
    }
}

int main() {
    cin>>n>>m>>t;
    while(cin>>x>>y) {
        q.push({x-1, y-1});
        visited[x-1][y-1] = 1;
    }
    for(int i=0;i<t+1;++i) {
        int curDayRottenApples = q.size();
        for(int j=0;j<curDayRottenApples;++j) {
            pair<int, int> p = q.front();
            q.pop();
            ans++;
            x = p.first;
            y = p.second;
            check(x+1, y);
            check(x-1, y);
            check(x, y+1);
            check(x, y-1);
        }
    }
    cout<<n*m - ans<<endl;
}
