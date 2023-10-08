#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string s;

int main() {
    cin>>s;
    for(int i=0; i<(int)s.size(); ++i)
    {
        int br = 0, j = i;
        while(s[j] == s[i])
        {
            br++;
            j++;
        }
        cout<<br<<s[i];
        i = j-1;
    }
}
