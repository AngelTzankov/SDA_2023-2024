// Example program
#include <iostream>
#include <string>
using namespace std;

bool check(long long n, long long f, long long cnt) {
    return f * cnt + cnt * (cnt-1) / 2 >= n;
}

long long ans(long long n, long long f) {
    long long l = 0, r = 2000000000;
    long long ans = -1;
    while(l <= r) {
        long long mid = (l+r)/2;
        if(check(n, f, mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return ans;
}

int main()
{
    long long n, f;
    cin>>n>>f;
    cout<<ans(n, f)<<endl;
}
