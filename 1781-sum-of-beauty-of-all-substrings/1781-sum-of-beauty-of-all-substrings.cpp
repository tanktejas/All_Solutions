class Solution {
public:
    int beautySum(string &s) {
        int n=s.length(); 
        int ans=0;
        
        
         vector<int>pre(26,0); 
        
        for(int i=0;i<n;i++)
        {
            pre.clear(); 
            pre.resize(26,0);
            for(int j=i;j<n;j++)
            {
                
                 int mini=INT_MAX,maxi=INT_MIN;
                  pre[s[j]-'a']++;
                
                 for(int k=0;k<26;k++)
                 {     
                     if(pre[k]==0) continue;
                      mini=min(mini,pre[k]);   
                      maxi=max(maxi,pre[k]);  
                 }   
                
               ans+=(maxi-mini);    
           }     
        }     
         
        return ans;
    }
};