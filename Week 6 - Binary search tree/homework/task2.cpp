#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
Тук ни трябва за всеки връх да знаем колко е бройката върхове,
които той има в своето поддърво и също да знаем тази бройка за 
лявото и дясното му дете. Ако знаме тези стойности то можем 
лесно за всеки връх да сметнем горната формула и да намерим 
при кой връх тя има максимална стойност. Ако сме в даден връх 
u то формулата можем да сметнем като: 

(брой върхове в лявото поддърво) * (брой върхове в дясното поддърво) * (N - (броя върхове в цялото поддърво на u)).

Бележка, ако някоя от трите стойности е 0, трябва да я заместим с 1,
за да може цялото произведение не е 0.
*/

struct Node{
    long long val;
    Node* left;
    Node* right;
}nodes[1000000];

long long n, l, r, a, ans;

// Имплементираме своя макс функция, за да избегнем компилационни 
// грешки породени от стандартната такава. Това е по желание.
long long max(long long a, long long b) {
    return a > b ? a : b; 
}

long long numberOfNodes(Node* root) {
    if (root == NULL) {
        return 0;
    }
    // Намираме брой върхове в поддървото на лявото дете
    long long leftSubtreeNodes = numberOfNodes(root->left);
    // Намираме брой върхове в поддървото на дясното дете
    long long rightSubtreeNodes = numberOfNodes(root->right);
    // Намираме брой върхове в поддървото на текущия връх
    long long fullSubtreeNodes = 1 + leftSubtreeNodes + rightSubtreeNodes;
    
    ans = max(ans, max(leftSubtreeNodes, 1) * max(rightSubtreeNodes, 1) * max(n - fullSubtreeNodes, 1));
    
    return fullSubtreeNodes;
    
}

int main() {
    cin>>n;
    for(int i=0;i<n;++i) {
        cin>>l>>r;
        if(l != -1) {
            nodes[i].left = &nodes[l];
        } else {
            nodes[i].left = NULL;
        }
        if(r != -1) {
            nodes[i].right = &nodes[r];
        } else {
            nodes[i].right = NULL;
        }
    } 
    numberOfNodes(&nodes[0]);
    cout<<ans<<endl;
}
