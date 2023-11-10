#include <iostream>
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

Node* getKthNumber(Node* root, int &smallerNodes, int k)
{

    if(root == NULL)
        return NULL;
    Node* left = getKthNumber(root->left, smallerNodes, k);
    if(left != NULL)
        return left;

    if(smallerNodes == k-1)
        return root;
    ++smallerNodes;

    return getKthNumber(root->right, smallerNodes, k);
}

int main()
{
    Node *a, *b, *c, *d, *e, *f;
    a = new Node(5);
    b = new Node(3);
    c = new Node(1);
    d = new Node(4);
    e = new Node(6);
    f = new Node(7);
    a->left = b;
    b->left = c;
    b->right = d;
    a->right = e;
    e->right = f;
    cout<<getKthNumber(a, *(new int(0)), 6)->value<<endl;;
}
