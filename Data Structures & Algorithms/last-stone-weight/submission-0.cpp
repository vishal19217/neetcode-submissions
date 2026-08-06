class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(const int& i:stones)pq.push(i);
        while(pq.size()>=2){
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            
            if(x!=y)
            pq.push(abs(x-y));
        }
        return pq.empty() ? 0: pq.top();
    }
};
