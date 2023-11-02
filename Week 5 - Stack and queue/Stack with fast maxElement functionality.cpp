#include <iostream>
using namespace std;

struct Stack
{
    int arr[1000];
    int maxElement;
    int size;
    Stack()
    {
        size = 0;
    }

    void push(int x)
    {
        if(x < maxElement)
        {
            arr[size++] = x;
        }
        else
        {
            arr[size++] = 2*x - maxElement;
            maxElement = x;
        }
    }

    void pop()
    {
        if(arr[size-1] < maxElement)
        {
            size--;
        }
        else
        {
            maxElement = 2*maxElement - arr[size-1];
            size--;
        }
    }

    int getMaxElement()
    {
        return maxElement;
    }

    void clear()
    {
        size = 0;
    }

    int top()
    {
        return arr[size-1];
    }
};

int main()
{
    Stack stack;
    int n, a;

    cin>>n;
    for(int i=0; i<n; ++i)
    {
        cin>>a;
        stack.push(a);
        cout<<stack.getMaxElement()<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;++i)
    {
        cout<<stack.getMaxElement()<<" ";
        stack.pop();
    }
    cout<<endl;
    stack.clear();
    cout<<stack.size<<endl;
}
