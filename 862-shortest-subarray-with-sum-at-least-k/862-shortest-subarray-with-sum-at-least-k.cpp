class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long>pre(n+1,0);
        int cnt=INT_MAX;
        long long ele=0;
        deque<int>d;
     
        for(int i=0;i<n;i++){
            pre[i+1]=nums[i] + pre[i];
            
            if(pre[i+1] >= k) cnt=min(cnt,i+1);
            
            while(d.size()>0 and pre[i+1] - pre[d.front()+1] >=k){ 
                cnt=min(cnt,i-d.front());
                ele++;  
                d.pop_front();
            }
            
             while(d.empty() == false and pre[i+1] <= pre[d.back()+1]){ 
                d.pop_back();
            }
            
            d.push_back(i);
        }
        
        return cnt == INT_MAX ? -1 : cnt;
        
 }
};