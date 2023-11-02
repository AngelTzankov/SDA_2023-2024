#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int a[10000000], n;

int main() {
    cin>>n;
    for(int i=0;i<n;++i) {
        cin>>a[i];
    }
    stack<int> s;
    int ans = 1, ansIndex = n-1;
    for(int i=n-1;i>=0;--i) {
        while(!s.empty() && a[i] >= s.top()) {
            s.pop();
        }
        s.push(a[i]);
        if (ans <= (int)s.size()) {
            ans = (int)s.size();
            ansIndex = i;
        }
    }
    cout<<ansIndex<<endl;
}
