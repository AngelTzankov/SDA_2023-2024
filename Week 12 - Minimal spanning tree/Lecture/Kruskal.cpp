#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 1000000;
const int INF = 1000000000;

struct Edge{
    int from;
    int to;
    int weight;

    bool operator<(const Edge &other) const {
        return this->weight < other.weight;
    }
};

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

int Kruskal(int n, int m, vector<Edge> edges) {
    int result = 0;
    for(int i=0;i<n;++i) {
        parent[i] = i;
        depth[i] = 1;
    }
    sort(edges.begin(), edges.end());

    for(int i=0;i<m;++i) {
        int root1 = Find(edges[i].from);
        int root2 = Find(edges[i].to);
        if(root1 != root2) {
            Union(root1, root2);
            result += edges[i].weight;
        }
    }

    return result;
}

int main() {
    int n, m, from, to, weight;
    vector<Edge> edges;
    cin>>n>>m;
    for(int i=0;i<m;++i) {
        cin >> from >> to >> weight;
        edges.push_back({from, to, weight});
    }

    cout<<Kruskal(n, m, edges)<<endl;
}
/*
9 14
0 1 4
0 7 8
1 2 8
1 7 11
2 3 7
2 8 2
2 5 4
3 4 9
3 5 14
4 5 10
5 6 2
6 7 1
6 8 6
7 8 7

 */
