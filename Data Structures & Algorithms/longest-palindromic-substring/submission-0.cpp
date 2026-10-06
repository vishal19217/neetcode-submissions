class Solution {
public:
    string longestPalindrome(string s) {
        int res = 0,n = s.size(), l, r;
        vector<vector<bool>> dp(n,vector<bool> (n,false));
        for(int i = n-1;i>=0;i--){
            for(int j = i;j<n;j++){
                if(s[i] == s[j] && ((j-i)<2 || dp[i+1][j-1])){
                    dp[i][j] = true;
                    if(res<(j-i+1)){
                        res = j-i+1;
                        l = i;
                        r = j;
                    }
                }
            }
        }
        return s.substr(l,res);
    }
};
