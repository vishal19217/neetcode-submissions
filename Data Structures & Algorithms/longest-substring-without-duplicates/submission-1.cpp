class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0, n = s.size(),ans = 0;
        int arr[95]={0};
        while(j<n){
            arr[s[j]-' ']++;

            while(arr[s[j]-' ']>1){
                arr[s[i++]-' ']--;
            }
            j++;
            ans = max(ans,j-i);
            
        }
        return ans;
    }
};
