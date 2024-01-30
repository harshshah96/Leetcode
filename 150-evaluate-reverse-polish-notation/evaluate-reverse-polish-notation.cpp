static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    int f(int first, int second, string op){
        if(op=="*") return second*first;
        else if(op == "+") return second+first;
        else if(op == "-") return second - first;
        else if(op == "/") return second/first;

        return -1;
    }

    int evalRPN(vector<string>& tokens) {
        int n=tokens.size();
        stack<int>st;

        int i=0;
        while(i<n){
            if(tokens[i]=="*" || tokens[i]=="-" || tokens[i]=="/" || tokens[i]=="+"){
                int first=(st.top());
                st.pop();
                int second=(st.top());
                st.pop();

                int result = f(first,second,tokens[i]);
                st.push(result);
            }else{
                st.push(stoi(tokens[i]));
            }
            i++;

        }
        return st.top();
    }
};