class Solution {
public:
    bool isPossible(vector<int>& nums) {
        map<int,int>mp;
        map<int,int>ct;
        
        for(int i=0;i<nums.size();i++)
        {
            ct[nums[i]]++;
        }
        
        int n=nums.size();
        
        for(int i=0;i<n;i++)
        {
            if(ct[nums[i]] == 0) continue;
            
            ct[nums[i]]--;
            
            if(mp[nums[i]-1]){
                
                mp[nums[i]-1]--;
                mp[nums[i]]++; 
                
            }else if(ct[nums[i]+1] and ct[nums[i]+2])
            {
                ct[nums[i]+2]--;
                ct[nums[i]+1]--; 
                
                mp[nums[i]+2]++;
            }else{
                return 0;
            }
        }
        
        return 1;
    }
};