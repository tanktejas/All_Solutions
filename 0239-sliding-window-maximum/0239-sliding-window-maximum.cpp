class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>d;
        
        vector<int>ans;
        int n=nums.size();
        
        for(int i=0;i<n;i++)
        {
            int ele=nums[i];
            
            while(!d.empty() and (nums[d.back()] <= ele))
            {
                d.pop_back();   
            }
            
            d.push_back(i);
        
            while(!d.empty() and (i - d.front()) >= k)
            {
                d.pop_front();
            }
              
            if(i >= (k-1))
                ans.push_back(nums[d.front()]);   
        }
        
        return ans;
    }
};