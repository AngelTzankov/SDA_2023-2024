#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

/*
Идеята тук е следната:
Разглеждаме участниците отзад напред като ги вкарваме в стек. Когато намерим разгледаме нов 
участник от стека изкарваме всички други участници, които той ще победи, докато не срещнем
някой, който той няма да победи. Броят дни, които ще са му нужни да победи участниците е 
равен на 1 + максималният брой на всеки един от тях да победи своите опиненти . Пазим за всеки 
колко дни са му трябвали да елиминира опонентите си по този начин и отговорът в крайна 
сметка е максималният брой дни, които са трябвали на някого, за да победи опонентите си.
*/

int eliminations[1000000];

int main() 
{
    int  N;
    cin >> N;
    vector<int> players;
    
    for(int i = 0; i < N; i++) 
    {
        int number;
        cin>>number;
        players.push_back(number);
    }
    
    stack<int> s;
    int max = 0;   
    int counter = 0;  
    
    for(int i = N-1; i>=0; i--) 
    {      
        // Премахваме от стека всички опоненти, които нашият участник ще победи
        while(!s.empty() && players[i] < players[s.top()]) 
        {   
            // Ако новопобеденият учасник е трябвало да победи опонентите си за повече дни
            // то също толкова дни + 1 ще са нужни на текущият участник да победи тях и него
            eliminations[i] = std::max(eliminations[i]+1, eliminations[s.top()]);
            s.pop();
        }   

        
        s.push(i);     
        if (max <= eliminations[i]) 
        {
            max = eliminations[i];            
        }               
    }
    
    cout<<max<<endl;
}

