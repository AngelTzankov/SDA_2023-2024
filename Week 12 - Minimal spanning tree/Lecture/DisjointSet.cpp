#include <iostream>
using namespace std;

const int MAX = 1000000;

int parent[MAX], depth[MAX];

int Find(int x) {
    if(parent[x] == x) {
        return x;
    }
    return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
    int root1 = Find(x);
    int root2 = Find(y);
    if(root1 == root2) {
        return;
    }
    if(depth[root1] > depth[root2])
        swap(root1, root2);
    if(depth[root1] == depth[root2]) {
        depth[root2]++;
    }
    parent[root1] = root2;
}

int main() {
    int puzzlePieces, moves, a, b;
    cin>>puzzlePieces>>moves;
    for(int i=0;i<puzzlePieces;i++) {
        parent[i] = i;
    }
    int remainingParts = puzzlePieces;
    for(int i=0;i<moves;++i) {
        cin>>a>>b;
        int root1 = Find(a);
        int root2 = Find(b);
        if(root1 != root2) {
            Union(a, b);
            remainingParts--;

        }
    }
    cout<<remainingParts<<endl;
}
/*
10 6
1 2
2 3
3 1
5 2
9 8
7 6

*/
