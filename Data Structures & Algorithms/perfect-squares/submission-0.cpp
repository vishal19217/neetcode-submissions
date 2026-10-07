class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,0);
        for(int i=1;i<=n;i++){
            dp[i] = INT_MAX;
            for(int j=1;j<=sqrt(i);j++){
                if(j*j == i)dp[i] = 1;
                else{
                    dp[i] = min(dp[i],dp[i-j*j]+1);
                }
            }
            cout<<dp[i]<<" ";
        }
        return dp[n];
    }
};