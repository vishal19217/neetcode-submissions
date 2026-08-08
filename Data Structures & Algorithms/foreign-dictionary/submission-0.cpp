class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        vector<vector<int>> adj(26,vector<int>(26,0));
        vector<int> chrs(26,0);
        int l = words.size();
        for(int i = 0;i<l;i++){
            int r = l;
            for(int j=0;j<words[i].size();j++){
                int c = (int)(words[i][j]-'a');
                chrs[c]= 1;
                for(int k = i+1;k<r;k++){
                    if(words[k].size()<=j){r = k;return "";}
                    int c2 = (int) (words[k][j]-'a');
                    if(c != c2){
                        adj[c][c2] = 1;
                        r = k;
                        break;
                    }
                }
            }
        }
        int indegree[26]={0}, outdegree[26] ={0};
        for(int i=0;i<26;i++){
            for(int j = 0;j<26;j++){
                if(adj[i][j]>0){indegree[j]++;outdegree[i] = 1;}
            }
        }
        string ans = "";
        queue<int> q;
        for(int i=0;i<26;i++){
            if(indegree[i] == 0 && outdegree[i]>0)q.push(i);
        }
        while(!q.empty()){
            int i = q.front();
            char c = 'a' + i;
            chrs[c-'a'] = 0;
            ans+=c;
            q.pop();
            for(int j=0;j<26;j++){
                if(adj[i][j] == 1){
                   if(indegree[j] == 1){
                    q.push(j);
                   } 
                   indegree[j]--;
                } 
            }
        }
        for(int i=0;i<26;i++){
            if(indegree[i]>0)return "";
        }
        for(int i=0;i<26;i++){
            if(chrs[i]>0)ans+=('a'+i);
        }

        return ans;




    }
};
