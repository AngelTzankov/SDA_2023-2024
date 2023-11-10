#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
}nodes[1000000];

int n, l, r, a;

int numberOfNodes(Node* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + numberOfNodes(root->left) + numberOfNodes(root->right);
}

int main() {
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
    cout<<numberOfNodes(&nodes[0]);
}
/*
Example input:
7
1 1 2 
2 3 4
3 5 6 
4 -1 -1 
5 -1 -1 
6 -1 -1
7 -1 -1
Output: 
7
*/
