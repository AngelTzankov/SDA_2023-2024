#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
 
using namespace std;
 
/*
Идеята на задачата е следната: 
Искаме на всяка спирка да поддържаме колко хора са слезли и колко искат да се
качат и да смятаме дали всички ще се поберат в маршрутката. За целта сортираме пътниците 
по това кой първи се е качил и един по един ги добавяме в приоритетна опашка, в която 
пък са подредени по това кой първи ще слезе. По този начин на всяка стъпка, когат идват 
нови пътници, можем да махнем всички пътници, които вече са слезли. 
(тяхното време на тръгване е по-малко от времето на пристигане на текущия гост).
 
Качваме всички желаещи и, ако сме прехвърлили капацитета, значи не можем да качим всички гости,
в противен случай можем.
 
*/
 
struct Trip {
    int cnt;
    int from;
    int to;
 
    Trip(int cnt, int from, int to) : from(from), to(to), cnt(cnt) {}
};
 
//така сортираме входа
bool comp(const Trip& lhs, const Trip& rhs)
{
    return (lhs.from < rhs.from || (lhs.from == rhs.from && lhs.to < rhs.to));
}
 
bool carPooling(vector<Trip>& trips, int capacity)
{
    int n = trips.size() ;
    //сортираме входа, за да симулираме качването на пътниците в хронологичен ред
    sort(trips.begin(),trips.end(),comp);
 
    int curr = 0 ;
 
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
 
    for(int i=0;i<n;i++) {
        //винаги на върха на приоритетната опашка са пътниците, който ще слязат първи
        //ако те трябва да слязат преди да се качат текущите, ги махаме от приоритетната опашка
        //и освобождаваме толкова капацитет, колкот е броят им
        //повтаряме операцията, докато няма повече пътници или следващите пътници не трябва да са слезли
        while(!pq.empty() && pq.top().first<=trips[i].from) {
            curr-=pq.top().second ;
            pq.pop() ;
        }
 
        pq.push({trips[i].to,trips[i].cnt}) ;
        curr+=trips[i].cnt;
 
        if(curr>capacity)
            return false ;
    }
 
    return true ;
}
 
int main() {
    int n, cap, q;
    cin >> q;
    for (int j = 0; j < q; ++j) {
        cin >> n >> cap;
        vector<Trip> trips;
        for (int i = 0; i < n; i++) {
            int cnt, from, to;
            cin >> cnt >> from >> to;
            trips.emplace_back(cnt, from, to);
        }
        cout << carPooling(trips, cap) << endl;
    }
 
}
