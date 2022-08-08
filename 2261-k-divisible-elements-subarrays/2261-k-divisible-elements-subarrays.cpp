class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int key=201;    
        map<unsigned long long,unsigned long long>mp;
        int n=nums.size();
        long long curr=0; 
        long long divi=0;
        int ans=0;
        
        for(int i=0;i<n;i++)
        {
            curr=0;  
            unsigned long long yy=key; 
            divi=0;  
            for(int j=i;j<n;j++)
            { 
                if((nums[j]%p) == 0) divi++;
                curr+=(yy*nums[j]);  
                yy*=key; 
                if(mp.count(curr)==0 and divi<=k)
                {
                    ans++;   
                    mp[curr]=1;
                }   
            }  
            
        }
        return ans;
    }
};