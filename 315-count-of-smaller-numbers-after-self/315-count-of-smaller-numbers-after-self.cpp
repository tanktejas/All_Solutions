class Solution {
public:
    vector<int>ans;

    void slv(int &s,int &m,int &e,vector<pair<int,int>> &nums)
    {
         int n=(m-s+1),mo=(e-m); 
         
        int i=s,j=m+1;
        int k=0;
        int cnt=0;
        
        vector<pair<int,int>>u(n+mo);
        
        while(i<=m and j<=e){  
            if(nums[i].first<=nums[j].first){
                u[k]=nums[i];
                ans[nums[i].second]+=(j-m-1);
                i++; 
            }else{  
                cnt++;
                u[k]=nums[j];
                j++;
            } 
            k++;
        }
         
        while(i<=m){
            u[k]=nums[i];
            ans[nums[i].second]+=(j-m-1);
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
    
    void mrg(int s,int e,vector<pair<int,int>> &nums){
        
        if(s<e){
            int mid=(s+e)/2;
            
            mrg(s,mid,nums);
            mrg(mid+1,e,nums);
            
            slv(s,mid,e,nums);
        }
        
    }
    
    vector<int> countSmaller(vector<int>& nums) {
          int n=nums.size();
           vector<pair<int,int>>pp;
           for(int i=0;i<n;i++){
               pp.push_back({nums[i],i});
           }
          ans.resize(n,0);
          mrg(0,n-1,pp);  
        
         for(int i=0;i<n;i++) cout<<nums[i]<<" ";
        
        return ans;
    }
};