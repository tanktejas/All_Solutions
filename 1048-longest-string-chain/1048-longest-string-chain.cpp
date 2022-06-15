bool cmpa(string &s,string &s2){
  return s.length()<s2.length();
}

class Solution {
public:
    vector<int>dp;
    bool check(string &s,string &t){
         
        if(t.size()-s.size()>1 or t.size()==s.size()) return false;
        int n=t.size();
        for(int i=0;i<t.size();i++){
            
            string temp=t.substr(0,i)+t.substr(i+1,n-i-1);
            
            if(temp==s) return true;
        }
        return false;
        
    }
    
    int find(int idx,int siz,vector<string>& w){
       
        if(dp[idx]!=-1) return dp[idx];
        
        int ans=1;
        
        for(int i=idx+1;i<w.size();i++){
          
        if(check(w[idx],w[i])){  
            
              ans=max(ans,1+find(i,siz,w));
        }  
            
        }  
        
           return dp[idx]=ans; 
    }
       
    int longestStrChain(vector<string>& w) {
        int n=w.size();
        
        sort(w.begin(),w.end(),cmpa);
 
        dp.resize(1001,-1);
        
        int ans=1;
        
        for(int i=0;i<n;i++){
            ans=max(ans,find(i,w.size(),w));
        }
        
        for(int i=0;i<n;i++) cout<<dp[i]<<" ";
        
        return ans;
    }
};