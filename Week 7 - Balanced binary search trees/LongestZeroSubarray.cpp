#include <map>
#include <iostream>

using namespace std;

int a[1000], pref[1000];
map<int, int> firstPrefixOccurrence;

int main() {
    int n;
    cin>>n;
    for(int i=0;i<n;++i) {
        cin>>a[i];
    }
    pref[0] = a[0];
    firstPrefixOccurrence[a[0]] = 0;
    for(int i=1;i<n;++i) {
        pref[i] = pref[i-1] + a[i];
        if(firstPrefixOccurrence.count(pref[i]) == 0) {
            firstPrefixOccurrence[pref[i]] = i;
        }
    }
    int ans = 0;
    for(int i=0;i<n;++i) {
        int firstOccurrence = firstPrefixOccurrence[pref[i]];
        if(i - firstOccurrence > ans) { 
            ans = i - firstOccurrence;
        }
        if(pref[i] == 0) {
            ans = max(ans, i+1);
        }
    }
    cout<<ans<<endl;
    
    
}
