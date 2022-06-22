class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        
        auto cmp=[&](int a,int b){
            if(nums[a].length() < nums[b].length()){
                return 0;
            }
            if(nums[a].length() > nums[b].length()){
               return 1;
            }
              
            for(int i=0;i<nums[a].length();i++){
                  if(nums[a][i] > nums[b][i]) return 1;  
                  else if(nums[a][i] < nums[b][i]) return 0;
            }
            
            return 0;
        };
        
        priority_queue<int,vector<int>,decltype(cmp)>q(cmp);
        
        
        for(int i=0;i<nums.size();i++){
            
            if(q.size()<k){
                q.push(i);
            }else{
                q.push(i);
                cout<<nums[q.top()]<<" ";
                q.pop();
            }
        }
        return nums[q.top()];
         
    }
};