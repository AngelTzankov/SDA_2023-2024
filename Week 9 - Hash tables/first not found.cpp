#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a[1000];
    unordered_map<int, bool> m;
    cin>>n;
    for(int i=0;i<n;++i) {
        cin>>a[i];
        m[a[i]] = true;
    }
    for(int i=1;i<=n+1;++i) {
        if(m[i] == false) {
            cout<<i<<endl;
            break;
        }
    }
}
