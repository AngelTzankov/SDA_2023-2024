#include <iostream>
#include <queue>
using namespace std;

const int MAX = 1000000;
const int INF = 1000000000;

struct Node{
    vector<int> neighbours;
    vector<int> weights;
}graphNodes[MAX];

bool inMST[MAX];
int minEdgeWeightToVertex[MAX];

int MST_Prim(int startVertex, int n, Node* nodes) {
    int result = 0;

    for(int i=0;i<n;i++) {
        inMST[i] = false;
        minEdgeWeightToVertex[i] = INF;
    }

    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({0, startVertex});

    while(!pq.empty()) {
        int edgeWeight = pq.top().first;
        int edgeTo = pq.top().second;
        pq.pop();

        if(inMST[edgeTo]) {
            continue;
        }
        inMST[edgeTo] = true;
        result += edgeWeight;

        for(int i=0;i<nodes[edgeTo].neighbours.size();i++) {
            int newEdgeTo = nodes[edgeTo].neighbours[i];
            int newEdgeWeight = nodes[edgeTo].weights[i];
            if(minEdgeWeightToVertex[newEdgeTo] > newEdgeWeight) {
                pq.push({newEdgeWeight, newEdgeTo});
                minEdgeWeightToVertex[newEdgeTo] = newEdgeWeight;
            }
        }
    }

    return result;
}

int main() {
    int n, m, from, to, weight;
    cin>>n>>m;
    for(int i=0;i<m;++i) {
        cin>>from>>to>>weight;
        graphNodes[from].neighbours.push_back(to);
        graphNodes[from].weights.push_back(weight);
        graphNodes[to].neighbours.push_back(from);
        graphNodes[to].weights.push_back(weight);
    }

    int startVertex;
    cin>>startVertex;

    cout<<MST_Prim(startVertex, n, graphNodes)<<endl;
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
 0

 */
