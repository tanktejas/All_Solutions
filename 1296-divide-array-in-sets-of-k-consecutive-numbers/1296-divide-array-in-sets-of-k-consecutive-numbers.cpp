class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
    
        map<int,int>mp;
        int n=nums.size();
        
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n;i++)
        {
            if(mp[nums[i]]==0) continue;
            
            bool bo=1;
            
            for(int j=nums[i];j<=(nums[i]+k-1);j++)
            {
                if(mp[j]){
                    mp[j]--;
                }else{
                    bo=0;
                }
            }
            
            cout<<bo; 
           
            if(!bo) return 0;
        }
                
        return 1; 
        
    }
    
};