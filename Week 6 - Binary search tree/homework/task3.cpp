#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
Задачата съм я разбил на две части за яснота, ноже да се съкрати кода в едно обхождане.
Идеята тук е, че първо можем да направим една прекалкулация, която после да ни улесни
смятането на отоговора. Прекалкулацията е за всеки връх да намерим най-дългия път, който
започва от него и стига до някъде в неговото поддърво. 

Ако знаем това за всеки връх, то след това за да намерим цялостния отговор на задачата 
ни е нужно да минем през всеки връх и да намерим най-дългия път, който вече не просто
започва от него, а най-дългия път, който минава през него. това става като намерим 
най-дългия път от лявото му дете и най-дългия му път от дясното му дете и ги обединим.

Бележка: най-дългия път от лявото или дясното му дето може да е отрицателен, така че
в тези случаи трябва да ги игнорираме.
*/

struct Node{
    int val;
    // Тук ще пазим дължината на най-дългия път, който започва от текущия връх
    int longestPathFromNode;
    Node* left;
    Node* right;
}nodes[4000000];

int n, l, r, ans = -1000000000, a;

//Тази функция изчислява прави прекалулацията за всеки връх
int longestPathFromNode(Node* root) {
    if (root == NULL) {
        return 0;
    }
    // тук ако и двата пътя от дясното и лявото дете са отрицателни, просо не ги взимаме
    // Затова е тук това max(0...)
    return root->longestPathFromNode = root->val + max(0, max(longestPathFromNode(root->left), longestPathFromNode(root->right)));
}

void calculateAns(Node* root) {
    if (root == NULL) {
        return ;
    }
    int longestPathFromLeftChild = root->left == NULL ? 0 : root->left->longestPathFromNode;
    int longestPathFromRightChild = root->right == NULL ? 0 : root->right->longestPathFromNode;
    
    // Ако най-дългия път от лявото дете е отрицателен го игнорираме
    if(longestPathFromLeftChild < 0) 
        longestPathFromLeftChild = 0;
    
    // Ако най-дългия път от дясното дете е отрицателен го игнорираме
    if(longestPathFromRightChild < 0) 
        longestPathFromRightChild = 0;
    
    int longestPathThroughNode = root-> val + longestPathFromLeftChild + longestPathFromRightChild;
    ans = max(ans, longestPathThroughNode);
    
    calculateAns(root->left);
    calculateAns(root->right);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=0;i<n;++i) {
        cin>>a>>l>>r;
        nodes[i].val = a;
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
    longestPathFromNode(&nodes[0]);
    calculateAns(&nodes[0]);
    cout<<ans<<endl;
}
