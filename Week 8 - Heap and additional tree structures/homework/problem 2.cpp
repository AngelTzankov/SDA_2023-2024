#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
 
/*
Идеята на задачата е следната: трябва да следим във всеки един момент кои столове
са свободни, за да може, когато дойде гостът T, да знаем на кой стол ще го настаним.
Затова си пазим гостите в приоритетна опашка, за да можем да следим кой кога идва и
кога си тръгва. Сортираме гостите по това кой първи е дошъл и един по един ги добавяме в
приоритетна опашка, в която пък са подредени по това кой първи ще си тръгне. По този начин
на всяка стъпка, когат идва нов гост, можем да махнем всички гости, които вече са си тръгнали
(тяхното време на тръгване е по-малко от времето на пристигане на текущия гост).
 
Всеки гост, който си тръгва, освобождава стола си, затова, когато дойде новия гост, знаем кои
столове са свободни. Тъй като искаме той да седне на стола с най-малък индекс, си пазим приоритетна
опашка от свободните столове - така винаги на върха й ще е стола с най-малък индекс.
 
Когато намерим госта с индекс Т, програмата приключва.
*/
 
 
struct Guest {
    int start;
    int end;
    int index;
    int chair;
   
    Guest(int start, int end, int index) : start(start), end(end), index(index) {}
    Guest() {}
};
 
//по този начин искаме да се сравняват в приоритетната опашка
bool operator<(const Guest& g1, const Guest& g2) {
    if (g1.end == g2.end) {
        return g1.start < g2.start;
    }
    return g1.end > g2.end;
}
 
//така сортираме входа
bool comp(const Guest& g1, const Guest& g2) {
    if (g1.start == g2.start) {
        return g1.end < g2.end;
    }
    return g1.start < g2.start;;
}
 
 
int main() {
    int n;
    cin >> n;
    vector<Guest> guests(n);
    for (int i = 0; i < n; ++i) {
        int start, end;
        cin >> start >> end;
        Guest guest(start, end, i);
        guests[i] = guest;
    }
 
    //сортираме входа, за да симулираме пристигането на гостите в хронологичен ред
    sort(guests.begin(), guests.end(), comp);
 
    int index;
    cin >> index;
   
    //ако е първия гост, директно приключваме
    if (guests[0].index == index) {
        cout << 0;
        return 0;
    }
   
    //слагаме всички столове в приоритетна опашка - в началото всички са свободни
    priority_queue<int, vector<int>, greater<int>> chairs;
    for (int i = 0; i < n; ++i) {
        chairs.push(i);
    }
    priority_queue<Guest> pqGuests;
   
    for(int i = 0; i < n; ++i) {
        Guest curr = guests[i];
       
        //винаги на върха на приоритетната опашка е гостът, който ще си тръгне първи
        //ако той трябва да си тръгне преди да е дошъл текущия, го махаме от приоритетната опашка
        //и освобождаваме стола му
        //повтаряме операцията, докато няма повече гости или следващия гост не трябва да си е тръгнал
        while(!pqGuests.empty() && pqGuests.top().end <= curr.start) {
            chairs.push(pqGuests.top().chair);
            pqGuests.pop();
        }
       
        //гостът заема първия свободен стол
        guests[i].chair = chairs.top();
        chairs.pop();
 
        //ако сме намерили госта Т, приключваме
        if (guests[i].index == index) {
            cout << guests[i].chair;
            return 0;
        }
       
        pqGuests.push(guests[i]);
 
    }
   
    return 0;
}
 
