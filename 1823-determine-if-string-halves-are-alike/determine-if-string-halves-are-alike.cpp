static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();
class Solution {
public:
    bool halvesAreAlike(string s) {
        int n=s.length();
        // length is always even
        
        int count1=0;
        int count2=0;

        unordered_set<char> st;
        st.insert('A');
        st.insert('E');
        st.insert('I');
        st.insert('O');
        st.insert('U');
        st.insert('a');
        st.insert('e');
        st.insert('i');
        st.insert('o');
        st.insert('u');

        for(int i=0; i<n/2; i++){
            if(st.count(s[i])) count1++;
            if(st.count(s[i+n/2])>0) count2++;


        }
    return count1==count2;
        
    }
};