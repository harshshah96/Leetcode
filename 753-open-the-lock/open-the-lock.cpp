class Solution {
public:
    void fillNeighbours(queue<string> &q, string &curr, unordered_set<string> &st){
        for(int i=0; i<4; i++){
            char ch=curr[i];

            char inc = ch== '9' ? '0': ch+1;
            char dec = ch== '0' ? '9': ch-1;

            curr[i]=dec;
            if(st.find(curr)==st.end()){
                q.push(curr);
                st.insert(curr);
            } 
            curr[i]=inc;
            if(st.find(curr)==st.end()){
                q.push(curr);
                st.insert(curr);
            } 

            curr[i]=ch;
        }

    }
    int openLock(vector<string>& deadends, string target) {
        string ans="0000";
        unordered_set<string> st(deadends.begin(), deadends.end());

        if(st.find("0000")!=st.end()) return -1;

        queue<string> q;
        q.push(ans);

        int level=0;
        while(!q.empty()){

            int n=q.size();

            while(n--){
                string curr=q.front();
                q.pop();
                if(curr==target) return level;

                fillNeighbours(q,curr,st);
            }

            level++;
        }

        return -1;
        
    }
};