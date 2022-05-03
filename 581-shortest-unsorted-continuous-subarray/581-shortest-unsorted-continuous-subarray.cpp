class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
    
        int n=nums.size();
        
        if(n==2 and nums[0]>nums[1]) return 2;
        
        vector<int>minsuff(n),maxpre(n);
        minsuff[n-1]=nums[n-1];
        
        for(int i=n-2;i>=0;i--){
            minsuff[i]=min(minsuff[i+1],nums[i]);
        }
        
        maxpre[0]=nums[0];
        for(int i=1;i<n;i++){
            maxpre[i]=max(maxpre[i-1],nums[i]);
        }
        
        int start=0,end=n-1;
        for(int i=0;i<n;i++)
        { 
            if(nums[i]!=minsuff[i]){
                break;
            }else{
                start=i;
            }
        }
        
        for(int i=n-1;i>=0;i--)
        {
            if(nums[i]!=maxpre[i]){
                break;
            }else{
                end=i;
            }
        }
        
        cout<<start<< " "<<end;
        
        if(nums[0]!=minsuff[0] and nums[n-1]!=maxpre[n-1]) return n;
        if((start==0 and nums[start]!=minsuff[start]) or (end==n-1 and nums[end]!=maxpre[end])) return end-start;
           if(end <= start) return 0;
        return end-start-1;
    } 
};