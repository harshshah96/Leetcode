class Disjoint{
    // Disjoint Set Union
    
    vector<int> parent;
    vector<int> size;
    int n;

public:

    Disjoint(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        this->n=n;
        makeSet();
    }

    void makeSet(){
        for(int i=0; i<n; i++){
            parent[i]=i;      
        }
    }

    int find(int i){
        if(parent[i]==i) return i;
        return parent[i]=find(parent[i]);
    }

    void union_set(int a, int b){

        a = find(a);
        b = find(b);
        if(a!=b){
            if(size[a]<size[b]){

                cout<<a<<"->"<<b<<endl;
                parent[a]=b;
                size[b]+=size[a];
            } 
            else{
                cout<<b<<"->"<<a<<endl;
                parent[b]=a;
                size[a]+=size[b];
            }
        }
        return;
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        int maxRow=0;
        int maxCol=0;


        for(auto it : stones){
            maxRow=max(maxRow, it[0]);
            maxCol=max(maxCol, it[1]);
        }

        Disjoint ds(maxRow + maxCol + 2);
        unordered_set<int> stoneNodes;

        for( auto it: stones){
            int NodeRow= it[0];
            int NodeCol= it[1] + maxRow + 1;
            ds.union_set(NodeRow, NodeCol);
            stoneNodes.insert(NodeRow);
            stoneNodes.insert(NodeCol);
        }
        int count=0;
        for(auto it:stoneNodes){
            // int a=ds.find(it);
            // cout<<it<<"->"<<a<<endl;
            if(ds.find(it)==it){
                
                count++;
            }
        }
        return n-count;

    }
};