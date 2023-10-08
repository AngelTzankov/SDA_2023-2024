#include <iostream>
using namespace std;

int a[1000000];
int rem[100];
int main()
{
    int n, k;
    cin>>n>>k;
    if(k == 1)
    {
        cout<<1<<endl;
        return 0;
    }
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        rem[a[i]%k]++;
    }
    int ans = 0;
    for(int i=1;i<k/2;++i)
    {
        ans+=max(rem[i], rem[k-i]);
    }
    if(k%2 == 0 && rem[k/2])
    {
        ans ++;
    }
    else
    {
        ans += max(rem[k/2], rem[k-k/2]);
    }
    cout<<ans+(bool)rem[0]<<endl;
}
