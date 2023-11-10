#include<iostream>
using namespace std;

struct Node
{
    int value;
    Node *left, *right;

    Node(int value)
    {
        this->value = value;
        left = NULL;
        right = NULL;
    }
};

bool checkIfBST(Node* root, int minLimit = -INT_MAX, int maxLimit = INT_MAX)
{
    if(root == NULL)
        return true;
    if(root->value < minLimit || root->value > maxLimit)
        return false;
    return checkIfBST(root->left, minLimit, root->value)
        && checkIfBST(root->right, root->value, maxLimit);
}

int main()
{
    Node *a, *b, *c, *d, *e, *f;
    a = new Node(5);
    b = new Node(3);
    c = new Node(2);
    d = new Node(4);
    e = new Node(6);
    f = new Node(1);
    a->left = b;
    b->left = c;
    b->right = d;
    a->right = e;
    e->right = f;
    cout<<checkIfBST(a);
}
