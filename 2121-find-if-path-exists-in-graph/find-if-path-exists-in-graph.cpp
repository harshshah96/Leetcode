static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
    vector<int> parent;
    vector<int> size;
public:
    int find(int i){
        if(parent[i]==i) return i;
        return parent[i]=find(parent[i]);
    }
    void combine(int u, int v) {
        u = find(u);
        v = find(v);

        if (u==v)
            return;

        if (size[u]>size[v])
            swap(u, v);

        parent[u] = v;
        size[v] += size[u];
    }
    
    bool validPath(const int n, const vector<vector<int>>& edges, const int source, const int destination){
        parent = vector<int>(n);
        size = vector<int>(n, 1);

        for (int i=0; i<n; i++){
            parent[i] = i;
        }
            
        for (const auto& edge : edges){  
            combine(edge[0], edge[1]);
        }
            
        return find(source)==find(destination);
    }
};