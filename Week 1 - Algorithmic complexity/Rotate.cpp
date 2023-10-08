#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> rotatedMatrix;
        for(int i=0;i<matrix.size();++i) {
             rotatedMatrix.push_back(vector<int>{});
        }
        for(int i=matrix.size()-1;i>=0;--i) {
            for(int j=0;j<matrix.size();++j) {
                rotatedMatrix[j].push_back(matrix[i][j]);
            }
        }
        for(int i=matrix.size()-1;i>=0;--i) {
            for(int j=0;j<matrix.size();++j) {
                matrix[i][j] = rotatedMatrix[i][j];
            }
        }
    }
};

int main() {

}
