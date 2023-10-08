#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int N = nums.size();
        vector<pair<int, int>> newArr;
        for(int i=0;i<N;++i) {
            newArr.push_back({nums[i], i});
        }
        sort(newArr.begin(), newArr.end());
        for (int i = 0, j = N - 1; i < j; i++) {
            while (i < j && newArr[i].first + newArr[j].first > target)
                j--;
            if (i < j && newArr[i].first + newArr[j].first == target)
                return vector<int>{newArr[i].second, newArr[j].second};     //initializes new vector to return
        }
        // It is guaranteed that there will be an answer for every test, so
        // this return is just for the compiler to not emit errors.
        return nums;
    }
};

int main() {

}
