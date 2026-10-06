class Solution {
public:
    int help(int idx,int robbed,vector<vector<int>>& dp,vector<int>& nums){
        int n = nums.size();
        if(idx >= n)return 0;
        else if(dp[idx][robbed]!=-1)return dp[idx][robbed];
        if(idx == n-1){
            if(robbed == 1)return dp[idx][robbed] = 0;
            else{
                return dp[idx][robbed] = nums[idx];
            }
        }
        else{
            return dp[idx][robbed] = max(nums[idx]+help(idx+2,robbed,dp,nums),help(idx+1,robbed,dp,nums));
        }

    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return max(help(1,0,dp,nums),nums[0] + help(2,1,dp,nums));
    }
};
