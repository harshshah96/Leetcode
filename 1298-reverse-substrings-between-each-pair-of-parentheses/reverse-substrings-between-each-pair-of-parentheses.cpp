static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();
        stack < char> st;

        for(int i = 0 ; i<n ; i++){
            if(s[i]==')'){
                // reverse all the letters upto the nearest '(' from top
                string rev = "";
                while(!st.empty() && st.top() != '('){
                    rev+=st.top();
                    st.pop();
                }
                st.pop(); // remove '('
                // reverse(rev.begin(), rev.end());

                for(char ch : rev){
                    st.push(ch);
                }

            }
            else st.push(s[i]);
        }

        string ans = "";

        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};