#include <iostream>

using namespace std;

int n, k;
int a[1000000];
int f(int l) {
    int sum = 0;
    for(int i=0;i<n;++i)
    {
        sum += a[i]/l;
    }
    return sum >= k;
}

int bin() {
    int l = 1  , r = 1000000000, ans = 0;
    while(l <= r) {
        int m = (l + r)/2;
        if(f(m) == true) {
            l = m+1;
            ans = m;
        }
        else
            r = m-1;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin>>n>>k;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    cout<<bin()<<endl;
}
