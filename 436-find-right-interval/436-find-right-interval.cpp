class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& in) {
        vector<vector<int>>t;
        int n=in.size();
        vector<int>ans(n,-1);
        for(int i=0;i<n;i++){
            t.push_back({in[i][0],in[i][1],i});
        }
        
        sort(t.begin(),t.end());
        
        int ci=t[0][2]; 
         
        vector<int>ind(n),start(n);
         
        for(int i=0;i<n;i++){
            ind[i]=t[i][2];
            start[i]=t[i][0];
            
        }
        
        // for(int i=0;i<start.size();i++) cout<<start[i]<<" ";  
                                                    
        for(int i=0;i<n;i++){
            int ele=in[i][1];
            int lb=lower_bound(start.begin(),start.end(),ele) - start.begin();
            if(lb<n)
               ans[i]=ind[lb]; 
        }
        
        return ans;
    }  
};