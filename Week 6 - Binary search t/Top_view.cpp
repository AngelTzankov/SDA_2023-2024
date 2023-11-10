#include <cmath>
#include <climits>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    
    Node(int val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* insert(Node* root, int val) {
    if (root == NULL) {
        return new Node(val);
    }
    if (root -> val > val)
        root->left = insert(root->left, val);
    else 
        root->right = insert(root->right, val);
    return root;
}

int seen[1000000], d[1000000];
int offset = 500000, maxx = -INT_MAX, minx = INT_MAX;

void inorder(Node* root, int x, int depth) {
    if(root == NULL) {
        return;
    }
    
    if (!seen[x+offset] || (seen[x+offset] && d[x+offset] > depth)) {
        seen[x+offset] = root->val;
        d[x+offset] = depth;
        minx = min(minx, x);
        maxx = max(maxx, x);
    } 
    inorder(root->left, x-1, depth+1);
    inorder(root->right, x+1, depth+1);
}
int t, n, a;
 
int main() {
    cin>>t;
    for(int i=0;i<t;++i) {
        cin>>n;
        maxx = -INT_MAX;
        minx = INT_MAX;
        Node* root = NULL;
        for(int i=0;i<n;++i) {
            cin>>a;
            root = insert(root, a);
        }
        for(int i=0;i<n;++i) {
            seen[offset+i] = 0;
            seen[offset-i] = 0;
        }
        inorder(root, 0, 0);
        for(int i=minx;i<=maxx;++i) {
            cout<<seen[offset+i]<<" ";
        }
        cout<<endl;
    }
}
