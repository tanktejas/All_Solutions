class Solution {
public:
    int longestValidParentheses(string s) {
         stack<int>st;
         int ans=0;
        st.push(-1);
        int n=s.length();
         for(int i=0;i<n;i++){
           
             if(s[i]==')' and st.size()>1 and s[st.top()]=='('){
                 st.pop();
                 ans=max(ans,(i-st.top())); 
             }else{
                 st.push(i);
             }
             
         }
        
        return ans;
    }
};