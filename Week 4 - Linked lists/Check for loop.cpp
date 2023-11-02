#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

bool isCyclic(Node* node)
{
    Node *slowPointer, *fastPointer;
    if(node->next == NULL)
    {
        return 0;
    }
    if(node->next->next == NULL)
    {
        return 0;
    }
    slowPointer = node->next;
    fastPointer = node->next->next;
    while(slowPointer != fastPointer && fastPointer != NULL)
    {
        slowPointer = slowPointer->next;
        if(fastPointer->next != NULL)
            fastPointer = fastPointer->next->next;
        else
            fastPointer = NULL;
    }
    return fastPointer != NULL;
}

int main()
{

}
