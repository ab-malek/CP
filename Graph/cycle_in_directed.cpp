class Solution {
  public:
    
    bool dfs(int v,vector<int> &color,vector<vector<int>> &g){
        color[v] = 1;
        for(auto c : g[v]){
            if(color[c] == 0){
                if(dfs(c,color,g)) return true;
            }
            else if(color[c] == 1){
                return true;
            }
        }
        color[v] = 2;
    }
  
    bool isCyclic(int n, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> g(n+1);
        
        for(int i=0;i<edges.size();i++){
            g[edges[i][0]].push_back(edges[i][1]);
        }
        
        vector<int> color(n+1,0);
        
        
        for(int i=0;i<n;i++){
            if(color[i] == 0){
                if(dfs(i,color,g)){
                    return true;
                }
            }
        }
        return false;
    }
};
