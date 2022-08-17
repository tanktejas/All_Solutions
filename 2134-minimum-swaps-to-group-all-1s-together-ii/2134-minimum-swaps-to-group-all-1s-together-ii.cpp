class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        
        vector<int>v(2*n);
        
        for(int i=0;i<n;i++)
        {
            v[i]=nums[i];
        }
        
        for(int i=0;i<n;i++)
        {
            v[i+n]=nums[i];
        }
         
        int tot1=0;
        
        for(int i=0;i<n;i++)
        {
            tot1+=(nums[i]==1);
        }
        
        int cz=0;
        
        for(int i=0;i<tot1;i++)
        {
            cz+=(v[i]==0);
        }
        
        int i=0,j=tot1; 
        int opneed=INT_MAX;
        
        while(j<(2*n))
        {
            opneed=min(opneed,cz); 
            if(v[i]==0)
            {
                cz--; 
            }
            if(v[j]==0){
              cz++; 
            } 
            i++;
            j++;
        }
        
        opneed=min(opneed,cz);
        
        return opneed;
    }
};