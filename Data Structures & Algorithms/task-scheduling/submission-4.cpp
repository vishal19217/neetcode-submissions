class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int freq[26] = {0};
        priority_queue<int> mfreqtasks;
        queue<pair<int,int>> cooldownqueue;
        int time = 0;
        for(char& c: tasks){
            freq[c-'A']++;
        }
        for(int &i:freq){
            if(i>0){
                mfreqtasks.push(i);
            }
        }
        while(!mfreqtasks.empty() || !cooldownqueue.empty()){
            if(!mfreqtasks.empty()){
                int count = mfreqtasks.top();
                mfreqtasks.pop();
                time++;
                
                count--;
                if(count>0){
                    cooldownqueue.push({time+n,count});
                }
            }
            else if(!cooldownqueue.empty()){
                time = cooldownqueue.front().first;

            }
            while(!cooldownqueue.empty() && time >=cooldownqueue.front().first){
                mfreqtasks.push(cooldownqueue.front().second);
                cooldownqueue.pop();
            }
        }
        return time;

    }
};
