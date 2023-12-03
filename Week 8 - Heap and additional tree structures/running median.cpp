#include <bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int>, greater<int>> minHeap;
priority_queue<int> maxHeap;

void addNum(int num)
{
    if(maxHeap.empty() || maxHeap.top() > num)
    {
        maxHeap.push(num);
    }
    else
    {
        minHeap.push(num);
    }
    if(maxHeap.size() > minHeap.size() + 1)
    {
        minHeap.push(maxHeap.top());
        maxHeap.pop();
    }
    else if(minHeap.size() > maxHeap.size() + 1)
    {
        maxHeap.push(minHeap.top());
        minHeap.pop();
    }
}

double findMedian()
{
    if(maxHeap.size() == minHeap.size())
    {
        if(maxHeap.empty())
        {
            return 0;
        }
        double average = (double) (maxHeap.top() + minHeap.top()) / 2.0;
        return average;
    }
    return maxHeap.size() > minHeap.size() ? maxHeap.top() : minHeap.top();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(1);
      
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        addNum(num);
        cout << findMedian() << "\n";
    }
    return 0;
}
