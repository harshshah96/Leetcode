class Solution {
public:
    bool dfs(unordered_map<int,vector<int>> &mp, int S, int D, vector<bool> &visited){
        if(S==D) return true;

        if(visited[S]==true) return false;

        visited[S]=true;

        for(auto &node: mp[S]){
            if(dfs(mp, node, D, visited)) return true;
        }

        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> mp;

        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            mp[u].push_back(v);
            mp[v].push_back(u);
        }

        vector<bool> visited(n,false);

        return dfs(mp,source , destination, visited);

        
    }
};