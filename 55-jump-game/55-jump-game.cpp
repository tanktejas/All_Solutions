class Solution {
public:
    vector<int>dp;
    
    bool find(int idx,vector<int> &a){
        if(idx==a.size()-1) return 1;
        
        if(idx>=a.size()) return 0;
        
        if(dp[idx]!=-1) return dp[idx];
        
        
        bool jo=0; 
        
        for(int i=1;i<=a[idx];i++){
            jo|=find(idx+i,a);
        }
        
        return dp[idx]=jo;
    }
    
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        dp.resize(n,-1);
        
        int cm=nums[0];
        int dh=0;
        if(cm>=n-1) return 1;
        
        for(int i=1;i<n;i++){
            
            dh=max(dh,i+nums[i]);
            
            if((i)==cm){
                
                if(dh>=n-1) return 1;
                
                cm=dh;
                dh=0;
            }
            
            if(cm<=0 and i!=n-1) return 0;
             
        }
        
        return 0;
        
        return 1;
        
        // return find(0,nums);
    }
};