#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


/*
Задачата се решава с обхождане в дълбочина на въведеното дърво
като за всеки възел пазим неговите координати и имаме един масив, 
в който за всяка вертикала пазим сумата на всички върхове, които 
лежат на нея. Нека масивът е ans[0...М]. Тъй като има координати с 
отрицателни стойности решаваме, кои ще са минималнанат и максималната 
стойнос за х на една вертикала, които можем да имаме. Спрямо 
ограниченията минималната стойност е х = -10^6 и максималната е 
х = 10^6. Затова заделяме масивът ans с 2*10^6 елемента и го използваме 
с offset. Тоест отговорът за х = 0 ще се намира на позиция x+offset
в масива ans. от знанията ни за минималната и максималната стойност
на х, следва offset да е равно на 10^6. При обхождането на всеки 
връх пазим неговите координати и добавяме стойността му в ans за 
неговата х координата.
*/ 

struct node {
    int val;
    node* left;
    node* right;
}nodes[1000000];

long long n, a[1000000], t, ans[2000002], l[1000000], r[1000000];
const int offset = 1000000;

void getSums(node* root, int x) {
    if(root == NULL) {
        return;
    }
    // Увеличаваме отговора за координатите X = x
    ans[offset+x] += root->val;
    // Обхождаме лявото поддърво
    getSums(root->left, x-1);
    // Обхождаме дясното поддърво
    getSums(root->right, x+1);
}

int main() {
    cin>>n;
    for(int i=0;i<n;++i) {
        cin>>a[i]>>l[i]>>r[i];
        nodes[i].val = a[i];
        if(l[i] != -1) 
            nodes[i].left = &nodes[l[i]];
        else 
            nodes[i].left = NULL;
        if(r[i] != -1) 
            nodes[i].right = &nodes[r[i]];
        else 
            nodes[i].right = NULL;
    }
    getSums(&nodes[0], 0);
    // Принтираме всички ненулеви суми на вертикали тъй като
    // Ако на някоя вертиката сме добавили стойност различна от 0
    // То там има връх
    for(int i=0;i<2000002;++i) {
        if(ans[i] != 0) {
            cout<<ans[i]<<" ";
        }
    }
    cout<<endl;
}
