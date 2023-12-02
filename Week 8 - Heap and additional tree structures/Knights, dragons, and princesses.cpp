#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
 
int main() {
    int n;
    cin>>n;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> dragons;
    char x;
    int y;
    for(int i=0;i<n-2;++i) {
        cin>>x>>y;
        if(x == 'd') {
            dragons.push({y, i});
        } else {
            while(dragons.size() >= y) {
                dragons.pop();
                
            }
        }
    }
    cin>>x>>y;
    if(dragons.size() < y) {
        cout<<-1<<endl;
    } else {
        vector<int> v;
        int i = 0, sum = 0;
        while(!dragons.empty()) {
            pair<int, int> d = dragons.top();
            v.push_back(d.second);
            sum += d.first;
            dragons.pop();
        }
        sort(v.begin(), v.end());
        cout<<sum<<endl;
        cout<<v.size()<<endl;
        for(int i=0;i<v.size();++i) {
            cout<<v[i]+2<<" ";
        }
        cout<<endl;
    }
}
