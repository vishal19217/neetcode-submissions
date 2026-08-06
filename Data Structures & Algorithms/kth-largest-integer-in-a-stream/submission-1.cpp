class KthLargest {
public:
    
    int k = 0;
    static bool cmp(const int& a,const int& b){
        return b<a;
    };
    
    priority_queue<int,vector<int>,decltype(&cmp)> pq;
    KthLargest(int k, vector<int>& nums): k(k),pq(cmp) {
        
        int idx = 0,n = nums.size();
        
        while(idx<n){
            if(k>0){
                pq.push(nums[idx]);
                k--;
            }
            else{
                if(pq.top()<nums[idx]){
                    pq.pop();
                    pq.push(nums[idx]);
                }
            }

            idx++;
        }
        this->k = k;
    }
    
    int add(int val) {
        if(k == 0){
            if(pq.top()<val){pq.pop();
                pq.push(val);}
        }
        else{
            k--;
            pq.push(val);
        }
        return pq.top();
    }
};
