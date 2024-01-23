class Solution {
public:
    void dfs(int source, vector<list<int>> &graph, unordered_set<int> &vis ){
        vis.insert(source);
        for(auto neighbour : graph[source]){
            if(!vis.count(neighbour)){
                dfs(neighbour, graph,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>&  matrix) {
        int n=matrix.size();

        vector<list<int>>graph(n);

        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(matrix[i][j]==1){
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                } 


            }
        }

        unordered_set<int> vis;
        int ans=0;

        for(int i=0; i<n; i++){
            if(!vis.count(i)){
                   // vis.insert(neighbour);
                    dfs(i, graph, vis);
                    ans++;
                }
        }
    return ans;
        
    }
};