class Solution {
public:
    bool find132pattern(vector<int>& nums) {
         int third=INT_MIN;
         stack<int>s;
         int n=nums.size();
        
         for(int i=n-1;i>=0;i--){
             if(nums[i] < third) return 1;
             while(!s.empty() and s.top() < nums[i]){third=s.top(); s.pop();}
             s.push(nums[i]);
         }
        
       return 0;
    }
};