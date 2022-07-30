 
class Solution {
public:
    
    void slv(long long &s,long long &m,long long &e,vector<long long> &nums)
    {
         long long n=(m-s+1),mo=(e-m); 
         
        long long i=s,j=m+1;
        long long k=0; 
        
        vector<long long>u(n+mo);
        
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

   

    void mrg(long long s,long long e,vector<long long> &nums,int lo,long long &ans){
        
        if(s<e){
            long long mid=(s+e)/2;
            
            mrg(s,mid,nums,lo,ans);
            mrg(mid+1,e,nums,lo,ans);
            
            long long i=s,j=mid+1;
            
            while(i<=mid and j<=e){
                if((nums[j]-nums[i]) >= lo)
                {
                    ans+=(e-j+1);
                    i++;
                }else{
                    j++;
                }
            }
            
            slv(s,mid,e,nums);
        }
        
    }

    
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        long long n=nums.size();
        
        vector<long long>pre(n,0);
        pre[0]=nums[0];
        
        for(long long i=1;i<n;i++){
              pre[i]=pre[i-1]+nums[i];
        }
        
        vector<long long>pre1=pre;
        
        long long ans=0,ans1=0;
        
        for(auto it:pre) if(it>=lower) ans++;
        
        mrg(0,n-1,pre,lower,ans);
        
        for(auto it:pre) if(it>upper) ans1++;
        
        mrg(0,n-1,pre1,upper+1,ans1);
        
        return ans-ans1;
        
    }
};