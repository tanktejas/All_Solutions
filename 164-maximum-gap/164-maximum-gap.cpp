class Solution {
public:
   
    vector<int>temp;
    
    void docount(int last,vector<int> &nums)
    { 
        
         int dev=1; 
         
         while(last>0){
             dev*=10;
             last--;
         }
 
        
         vector<int>v(10,0);
         int n=nums.size();
         
         temp.resize(n,0);
          
         for(int i=0;i<n;i++)
         {  
             int ele=(nums[i]/dev)%10;
             v[ele]++;   
         }
          
         for(int i=1;i<10;i++)
         {
             v[i]+=v[i-1];
         } 
        
           
         for(int i=n-1;i>=0;i--)
         { 
             int ele=(nums[i]/dev)%10; 
             int idx=v[ele]-1;    
             v[ele]--;   
             temp[idx]=nums[i];
         }
          
        for(int i=0;i<n;i++)
        {
            nums[i]=temp[i];
        }
          
    }
     
    int maximumGap(vector<int>& nums) {
         
        int n=nums.size();
        
        if(n<2) return 0;
        
        int maxi;
        for(int i=0;i<n;i++)
        {
            maxi=max(maxi,nums[i]);
        }
        
        int tillwhen=10;
        // while(maxi)
        // {
        //     tillwhen++;
        //     maxi/=10;
        // }  
        
        int curr=0;  
        
        while(curr<tillwhen)
        {  
            docount(curr,nums);  
            curr++; 
        }
         
        int diff=nums[1]-nums[0];
        
        for(int i=2;i<n;i++)
        {
             diff=max(diff,nums[i]-nums[i-1]);
        }
       
        cout<<endl;  
        
        return diff;
    }
};