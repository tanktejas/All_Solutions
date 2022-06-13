class Solution {
public:
    vector<vector<int>>dp;
    
    int find(vector<vector<int>> &tri,int row,int col,int n){
        if(row==n){
            return 0;
        }
        if(col==(int)(tri[row].size())) return 0;
        
        if(dp[row][col]!=-1) return dp[row][col];
        
        int maxi=INT_MAX;
        
        maxi=min(maxi,tri[row][col] + find(tri,row+1,col,n));
        
        maxi=min(maxi,tri[row][col] +find(tri,row+1,col+1,n));
        
        return dp[row][col] = maxi;
    }
    
    int minimumTotal(vector<vector<int>>& tri) {
         int n=tri[tri.size()-1].size();
       if(n==1){
           return tri[0][0];
       }         
        
        vector<int>temp;
        temp.push_back(tri[0][0]);
        
        vector<int>ans;
        int fa=INT_MAX;
        for(int i=1;i<n;i++){
            ans.resize(0);
            ans.push_back(temp[0] + tri[i][0]);
            
            for(int j=1;j<temp.size();j++){
                int tt=min(temp[j],temp[j-1]);
                ans.push_back(tri[i][j] + tt);  
               
            }  
            
            ans.push_back(temp[temp.size()-1] + tri[i][tri[i].size()-1]); 
            temp=ans;
        }
        for(int i=0;i<n;i++){
            fa=min(fa,ans[i]);
        }
        // cout<<endl;
        return fa;
    }
};