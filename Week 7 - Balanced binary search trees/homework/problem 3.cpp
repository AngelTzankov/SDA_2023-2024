#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <limits.h>
#include <algorithm>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    
    set<int> nums = { 0 };
    auto it = nums.begin();
    
    int curr;
    int ans = INT_MAX;
    while (N--) {
        cin >> curr;
        it = nums.insert(curr).first;
        ans = min(min(it != nums.begin() ? *prev(it) ^ curr : ans, next(it) != nums.end() ? *next(it) ^ curr : ans), ans);
        cout << ans << '\n';

    }

    return 0;
}
