static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    string simplifyPath(string path) {

        stack<string> st;
        int n=path.length();
        int i=0;
        while(i<n){
            int j=i+1;
            if(path[i]=='/') {
                i++;
                continue;

            }
            while(j<n && path[j]!='/') j++;
            string s=path.substr(i,j-i);
            if(s==".."){
                if(!st.empty()){
                    st.pop();
                    
                }
                i=j;
                continue;
            } else if(s=="."){
                i=j;
                continue;
            }
            st.push(s);
            i=j;
        }
        string ans="";
        stack<string>temp;

        if(st.empty()) return "/";

        while(!st.empty()){
            temp.push(st.top());
            st.pop();
        }
        while(!temp.empty()){
            string a="/";
            a+=temp.top();
            temp.pop();
            ans+=a;
        }

        return ans;

    

        
    }
};