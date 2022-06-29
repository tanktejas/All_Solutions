class Solution {
public:
    
    int mod=1000000007;
    
    int kadne(vector<int> &nums){
        int cs=0,ms=0;
        for(int i=0;i<nums.size();i++){
          cs+=nums[i];
          ms=max(ms,cs);
          if(cs<0) cs=0;
        }
        return ms;
    }
    
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int sum=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
        }
        
        int ans=0;
        vector<int>temp;
        for(int i=0;i<arr.size();i++) temp.push_back(arr[i]);
         if(k==1){
             return kadne(temp)%mod;
         }     
         else if(sum<=0){
         for(int i=0;i<arr.size();i++) temp.push_back(arr[i]); 
            return kadne(temp)%mod;  
        }else{
         for(int i=0;i<arr.size();i++) temp.push_back(arr[i]); 
            return (kadne(temp)  + (((long long)(k-2)*sum)%mod))%mod;  
        }   
    }
};