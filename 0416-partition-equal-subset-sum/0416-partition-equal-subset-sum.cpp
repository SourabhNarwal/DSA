class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        
        // If total sum is odd, we cannot partition it into two equal subsets
        if (totalSum % 2 != 0) {
            return false;
        }
        
        int target = totalSum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true; // Base case: zero sum is always possible with an empty subset
        
        for (int num : nums) {
            // Traverse the dp array from end to start to avoid reuse of the same element
            for (int j = target; j >= num; --j) {
                dp[j] = dp[j] || dp[j - num];
            }
        }
        
        return dp[target];
    }
};
