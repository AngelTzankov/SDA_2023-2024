class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(int i=0;i<nums.size();++i) {
            m[nums[i]]++;
        }
        int ans = 0;
        for(int i=0;i<nums.size();++i) {
            if(k == 0) {
                 if(m[nums[i]-k] > 1) {
                     ans++;
                 }
            } else if(m[nums[i]-k]) {
                ans++;
            }
            m[nums[i]-k] = 0;
        }
        return ans;
    }
};
