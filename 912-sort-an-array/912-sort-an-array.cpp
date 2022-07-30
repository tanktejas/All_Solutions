class Solution {
public:
    
    void slv(int &s,int &m,int &e,vector<int> &nums)
    {
         int n=(m-s+1),mo=(e-m); 
         
        int i=s,j=m+1;
        int k=0; 
        
        vector<int>u(n+mo);
        
        while(i<=m and j<=e){  
            if(nums[i] <=nums[j] ){
                u[k]=nums[i]; 
                i++; 
            }else{   
                u[k]=nums[j];
                j++;
            } 
            k++;
        }
         
        while(i<=m){
            u[k]=nums[i]; 
            i++;
            k++;
        }
         
        while(j<=e){
          u[k]=nums[j];
          j++;
          k++;
        }
        
        for(int i=0;i<n+mo;i++){
            nums[i+s]=u[i];
        }
       
    }
    
    void mrg(int s,int e,vector<int> &nums){
        
        if(s<e){
            int mid=(s+e)/2;
            
            mrg(s,mid,nums);
            mrg(mid+1,e,nums);
            
            slv(s,mid,e,nums);
        }
        
    }
    
    vector<int> sortArray(vector<int>& nums) {
         mrg(0,nums.size()-1,nums); 
        return nums;
    }
};