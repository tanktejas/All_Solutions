class Solution {
public:
    int minSetSize(vector<int>& nums) {
        unordered_map<int,int>m;
        int n=nums.size();
        
        for(int i=0;i<n;i++)
        {
            m[nums[i]]++;
        }
        
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(m[nums[i]]!=0)
            {
                ans.push_back(m[nums[i]]);
                m[nums[i]]=0;
            }
        }
        
        sort(ans.begin(),ans.end(),greater<int>());
        
        int cnt=0; 
        
        for(int i=0;i<n;i++)
        {
            cnt+=ans[i];
            
            if(cnt >= (n/2)) return i+1;
        }
        
        return 1;
    }
};