class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt = 0,sum = 0;
        unordered_map<int,int> sumCount;
        // 0, 2,1,0,2
        sumCount[0] = 1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sumCount.count(sum-k)>0){
                cnt+=sumCount[sum-k];
                cout<<i<<" \n";
            }
            sumCount[sum]+=1;
            
            cout<<i<<" "<<sum<<" "<<sumCount[sum]<<"\n";
        }
        return cnt;
    }
};