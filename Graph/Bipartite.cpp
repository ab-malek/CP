class Solution {
public:

    bool dfs(int v,vector<int> &color,vector<int> g[]){
        for(auto c : g[v]){
            if(color[c] == color[v]) return false;
            if(color[c] == -1){
                color[c] = 1 - color[v];
                if(!dfs(c,color,g)) return false;
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> g[n+1];
        for(int i=0;i<dislikes.size();i++){
            g[dislikes[i][0]].push_back(dislikes[i][1]);
            g[dislikes[i][1]].push_back(dislikes[i][0]);
        }

        vector<int> color(n+1,-1);

        for(int i=0;i<n;i++){
            if(color[i] == -1){
                color[i] = 1;
                if(!dfs(i,color,g)){
                    return false;
                }
            }
        }

        return true;
    }
};
