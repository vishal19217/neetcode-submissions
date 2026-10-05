class Solution {
public:
    int rob(vector<int>& nums) {
        int p1,p0,c1,c0;
        int n = nums.size(),ans = nums[0];
        vector<int> rob(n,0);
        vector<int> nrob(n,0);
        rob[0] = nums[0];
        for(int i=1;i<n;i++){
            nrob[i] = max(rob[i-1],nrob[i-1]);
            if(i == 1){
                rob[i] = nums[i];
            }
            else{
                rob[i] = nums[i] + nrob[i-1];
            }
            ans = max(rob[i],nrob[i]);
        }
        return ans;
    }
};
