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

Node *getListLastNode(Node* head)
{
    while(head->next != NULL)
    {
        head = head->next;
    }
    return head;
}

int getListLength(Node *head)
{
    int listLength = 0;
    while(head != NULL)
    {
        head = head->next;
        ++listLength;
    }
    return listLength;
}

Node* getNthListNode(Node *head, int n)
{
    while(head != NULL && n>0)
    {
        head = head->next;
        --n;
    }
    return head;
}

Node* getMergeNode(Node* firstHead, Node* secondHead)
{
    int firstListLen = getListLength(firstHead);
    int secondListLen = getListLength(secondHead);
    Node *lastNodeOfFirstList = getListLastNode(firstHead);
    Node *lastNodeOfSecondList = getListLastNode(secondHead);

    if(lastNodeOfFirstList != lastNodeOfSecondList)
    {
        return NULL;
    }

    if(firstListLen > secondListLen)
    {
        firstHead = getNthListNode(firstHead, firstListLen - secondListLen);
    }
    else
    {
        secondHead = getNthListNode(secondHead, secondListLen - firstListLen);
    }

    while(firstHead != secondHead)
    {
        firstHead = firstHead->next;
        secondHead = secondHead->next;
    }
    return firstHead;
}

int main()
{

}
