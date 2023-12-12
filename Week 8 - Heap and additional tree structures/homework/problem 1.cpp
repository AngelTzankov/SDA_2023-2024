#include <iostream>
#include <vector>
#include <queue>
 
using namespace std;
 
/*
Идеята на задачата е следната: 
Искаме да изведем К-те точки, които са най-близо до подадената. За целта слагаме 
в приоритетна опашка наредена двойка от квадрата на разстоянието (алтернативно може и
само разстоянието с double) и координатите на точките. За да сметнем кои са точките, най-близки 
до дадената, в началото нормализираме (т.е. смятаме все едно координатите на подадената точка 
са (0,0) и накрая ги връщаме в първоначалния им вид). 
*/
 
int x, y;
 
void kClosest(vector<pair<long long, long long>>& points, long long k) {
    priority_queue<pair<long long,pair<long long, long long>>,
            vector<pair<long long,pair<long long, long long>>>,
            greater<>> pq;
    for(const auto& p : points)
        //смятаме квадрата на разстоянието и записваме него и координатите на точката
        pq.push({p.first*p.first + p.second*p.second,{p.first,p.second}});
 
 
    while(!pq.empty() && k--) {
        //връщаме координатите в първоначалния вид
        cout << pq.top().second.first + x << " " << pq.top().second.second + y << endl;
        pq.pop();
    }
}
 
int main() {
    long long n, k;
    cin >> x >> y >> n >> k;
    vector<pair<long long, long long>> points;
 
    for(long long i = 0; i < n; i++) {
        long long currX, currY;
        cin >> currX >> currY;
        //нормализираме
        points.emplace_back(currX - x, currY - y);
    }
 
    kClosest(points, k);
    return 0;
}
