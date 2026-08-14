class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
        auto cmp = [](vector<int>& v1,vector<int>& v2){
            return v1[1]<v2[1];
        };
        
        sort(trips.begin(),trips.end(),cmp);
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        int n = trips.size();
        int idx = 0,cap = capacity,loc = 0;
        while(idx<n){
            while(!pq.empty() && trips[idx][1]>=pq.top()[0]){
                cap+=pq.top()[1];
                pq.pop();
            }
            if(cap>=trips[idx][0]){
                cap-=trips[idx][0];
                
                pq.push({trips[idx][2],trips[idx][0]});
                idx++;
            }
            else{
                return false;
            }
        }

        return true;
    }
};