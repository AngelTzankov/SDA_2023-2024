#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n, a[100000], ans;
int main() {
    cin>>n;
    for(int i=0;i<n;++i)
        cin>>a[i];
    int i=0, j=n-1;
    while(i != j)
    {
        if(min(a[i],a[j]) * (j-i) > ans)
            ans = min(a[i], a[j]) * (j-i);
        if(a[i] < a[j])
            ++i;
        else
            --j;
    }
    cout<<ans<<endl;
}
