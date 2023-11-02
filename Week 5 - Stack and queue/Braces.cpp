#include <iostream>
#include <stack>

using namespace std;

bool isOpeningBracket(char bracket)
{
    return (bracket == '(' || bracket == '[' || bracket == '{');
}

bool areMatchingBrackets(char openingBracket, char closingBracket)
{
    if(openingBracket == '(' && closingBracket == ')')
    {
        return true;
    }
    if(openingBracket == '[' && closingBracket == ']')
    {
        return true;
    }
    if(openingBracket == '{' && closingBracket == '}')
    {
        return true;
    }
    return false;
}

int main()
{
    string bracketsSequence;
    stack<char> openedBrackets;
    cin>>bracketsSequence;
    for(int i=0;i<bracketsSequence.length();++i)
    {
        if(isOpeningBracket(bracketsSequence[i]))
        {
            openedBrackets.push(bracketsSequence[i]);
        }
        else
        {
            if(!openedBrackets.size())
            {
                cout<<"The sequence is incorrect!"<<endl;
            }
            if(areMatchingBrackets(openedBrackets.top(), bracketsSequence[i]))
            {
                openedBrackets.pop();
            }
            else
            {
                cout<<"The sequence is incorrect!"<<endl;
                return 0;
            }
        }
    }
    if(openedBrackets.size())
    {
        cout<<"The sequence is incorrect!"<<endl;
    }
    else
    {
        cout<<"The sequence is correct!"<<endl;
    }
}
