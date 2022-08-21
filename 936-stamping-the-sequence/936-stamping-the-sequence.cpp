class Solution {
public:
    
    bool match(string s,string t){
        if(s.length() != t.length()) return 0;
        
        for(int i=0;i<s.length();i++)
        {
            if(s[i]!='?' and t[i]!=s[i]){
                return 0;
            }
        }
        return 1;
    }
     
    vector<int> movesToStamp(string st, string ta) {
        
        vector<int>ans;
        bool fnd=1;
        int n=st.length(),m=ta.length();
        
        while(fnd)
        {
            fnd=0;
            
            for(int i=0;i<m;i++)
            {
                string gg=ta.substr(i,n);
                bool v=1;
                
                for(int i=0;i<gg.length();i++){
                    if(gg[i]!='?') v=0;
                }
                
                if(v) continue;
                
                if(match(gg,st)){
                    ans.push_back(i);
                    for(int k=i;k<(i+n);k++)
                    { 
                        ta[k]='?';
                    }  
                    fnd=1; 
                }
                
            }
            
        }
        
        bool bo=1;
        
        for(int i=0;i<m;i++)
        {
            if(ta[i]!='?') bo=0;
        }
        
        if(!bo){
            ans.clear();
        }
        
        
        if(ans.size() > 10*m){
            // cout<<1;
           ans.clear();
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
        
    }
};