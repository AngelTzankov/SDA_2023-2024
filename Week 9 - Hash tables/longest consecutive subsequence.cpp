class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> found;
        unordered_map<int, int> longestSubsequence;
        for(int i=0;i<nums.size();++i) {
            found[nums[i]] = 1;
        }   
        int ans = 0;
        for(int i=0;i<nums.size();++i) {
            if(longestSubsequence[nums[i]] == 0) {
                int j = nums[i];
                int len = 0;
                while(found[j] && longestSubsequence[j] == 0) {
                    len++;
                    j--;
                }
                len += longestSubsequence[j];
                j = nums[i];
                ans = max(ans, len);
                while(found[j] && longestSubsequence[j] == 0) {
                    longestSubsequence[j] = len--;
                    j--;
                }
                
            }
        }
        return ans;
    }
};
