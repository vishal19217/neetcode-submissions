class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prod = nums[0],ans = nums[0],n = nums.size();
        for(int i=1;i<n;i++){
            prod*=nums[i];
            ans = max(ans,prod);
            if(prod == 0)prod = 1;
        }
        prod = nums[n-1];
        ans = max(prod,ans);
        for(int i=n-2;i>=0;i--){
            prod*=nums[i];
            ans = max(ans,prod);
            if(prod == 0)prod = 1;
        }
        return ans;
    }
};
