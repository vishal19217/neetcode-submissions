class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<vector<int>> projects;
        int initial = w;
        for(int i=0;i<profits.size();i++){
            vector<int> v = {capital[i],profits[i]};
            projects.push_back(v);
        }
        sort(projects.begin(),projects.end());
        priority_queue<int> pq;
        int idx = 0, n = profits.size();
        while((idx<n && projects[idx][0]<=initial) || k>0){
            while(idx<n && projects[idx][0]<=initial){
                int netProfit = projects[idx][1];
                if(netProfit>0)
                    pq.push(netProfit);
                idx++;
            }
            if(k>0 && !pq.empty()){
                k--;
                int netProfit = pq.top();
                pq.pop();
                initial+=netProfit;
            }
            else{
                break;
            }

        }
        return initial;
    }
};