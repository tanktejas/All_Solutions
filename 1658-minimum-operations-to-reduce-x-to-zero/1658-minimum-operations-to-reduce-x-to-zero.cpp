class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int tot=0;
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++) sum+=nums[i];
        
        int need=sum-x;
        
        if(need<0) return -1;
        
        int mw=INT_MIN;
        
        int i=0,j=0;
        int cs=0;  
        while(j<n and i<=j){ 
         
            if(cs<=need){
                cs+=nums[j];
                j++; 
            }else{
                cs-=nums[i];
                i++;
            }
            if(cs==need){
                mw=max(mw,j-i); 
            }
        }
           
        
        while(i<n and cs>=need){
            cs-=nums[i];
            if(cs==need) mw=max(mw,j-i-1);
            i++;
        }
        
        if(mw==INT_MIN) return -1;
        else return n-mw;
    }   
};