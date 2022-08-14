class Solution {
public:
   
    
    string smallestNumber(string pat) {
         string ans="";
         string t="";
        
         stack<int>s;
        
        for(int i=0;i<pat.length();i++)
        {
        
            if(pat[i]=='I'){ 
                ans+=to_string(i+1); 
                while(!s.empty()){
                    ans+=to_string(s.top());
                    s.pop();
                } 
            }else{
                s.push(i+1);
            } 
        }
        
         ans+=(to_string(pat.length()+1));
        if(!s.empty()){     
         while(!s.empty()){
              ans+=to_string(s.top());
              s.pop();
        }
        }
        return ans;
    } 
};