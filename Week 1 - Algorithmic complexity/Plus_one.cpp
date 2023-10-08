#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carryOver = 1;
        for(int i=digits.size()-1;i>=0;--i) {
            if (carryOver == 1) {
                digits[i]++;
            }
            carryOver = 0;
            if (digits[i] == 10) {
                digits[i] = 0;
                carryOver = 1;
            }
        }
        if (carryOver == 1) {
            digits.insert(digits.begin(), 1, 1);
        }
        return digits;
    }
};

int main() {

}
