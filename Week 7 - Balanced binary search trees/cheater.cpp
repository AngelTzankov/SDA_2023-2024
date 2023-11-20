#include <set>
#include <iostream>
using namespace std;
 

int a, k, m, n;
 
int getMaxShipsInInterval(int left, int right)
{
    return (right - left)/(a+1);
}
 
int main()
{
    cin>>n>>k>>a;
    cin>>m;
    set<int> intervalPoints;
    intervalPoints.insert(0);
    intervalPoints.insert(n+1);
 
    int maxPossibleWarships = (n+1)/(a+1);
    for(int i=0;i<m;++i)
    {
        int curr_guess;
        cin>>curr_guess;
        auto it = intervalPoints.upper_bound(curr_guess);
        int right = *it;
        int left = *(--it);
        intervalPoints.insert(curr_guess);
        maxPossibleWarships = maxPossibleWarships - getMaxShipsInInterval(left, right)
            + getMaxShipsInInterval(left, curr_guess) + getMaxShipsInInterval(curr_guess, right);

        if(maxPossibleWarships < k)
        {
            cout<<i+1<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
}
