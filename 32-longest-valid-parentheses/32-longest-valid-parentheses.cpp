class Solution {
public:
    int longestValidParentheses(string s) {
    while(s.size() and s[0]==')') s=s.substr(1);
        
      stack<pair<char,int>>st;
        st.push({'(',-1});
      int mx=0;
      int n=s.length();
    
      for(int i=0;i<n;i++){
          
        if(s[i]=='('){
            st.push({'(',i});
        }else{   
            if(st.top().first=='(' and st.top().second!=-1){
                   st.pop();  
                   mx=max(mx,i-st.top().second); 
            }else{
                st.push({')',i});
            }
         }
          
      }   
        
       return mx;
    }
};

