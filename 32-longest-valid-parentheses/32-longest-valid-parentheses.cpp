class Solution {
public:
    int longestValidParentheses(string s) {
        
        int ans=0;
        int n=s.length();
        int lef=-1;
        int op=0,cl=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                 op++;
            }else{
                cl++;
            }
            
            if(op==cl){
                ans=max(ans,(i-lef));
            }
            
            if(cl>op){
                op=0;
                cl=0;
                lef=i;
            }
            
        } 
        
        op=0;
        cl=0;
        lef=n;
        
         for(int i=n-1;i>=0;i--){
            if(s[i]=='('){
                 op++; 
            }else{
                cl++;
            }
            
            if(op==cl){
                ans=max(ans,(lef-i));
            }
            
            if(cl<op){
                op=0;
                cl=0;
                lef=i;
            }
            
        } 
        
        return ans;
    }
};