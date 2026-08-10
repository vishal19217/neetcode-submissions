class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
     int i = 0, j = 0,n = nums.size();
     unordered_map<int,int> mp;
    bool ans = false;
     while(j<n){
        if(abs(i-j)<=k){
            mp[nums[j]]++;
            if(mp[nums[j]]>1){ans = true;break;}
            j++;
        }
        else{
            mp[nums[i]]--;
            if(mp[nums[i]] == 0)mp.erase(nums[i]);
            i++;
        }
     }   
    
    return ans;
    }
};