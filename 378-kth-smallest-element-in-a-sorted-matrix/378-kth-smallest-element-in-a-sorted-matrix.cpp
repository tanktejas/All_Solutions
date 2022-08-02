class Solution {
public:
    int tellpos(vector<vector<int>>& ma,int mid)
    {
        int n=ma.size();
        int i=n-1,j=0; 
        int how=0;
        while(i>=0 and j<n)
        {
            if(ma[i][j] > mid)
            {
                i--;
            }else{
                how+=(i+1);
                j++;
            }
        }
        return how;
    }
    
    
    int kthSmallest(vector<vector<int>>& ma, int k) {
         int n=ma.size();
        
        int i=ma[0][0],j=ma[n-1][n-1];
        int ans=0;
        
        while(i<=j)
        {
            int mid=(i+j)/2;
            int poss=tellpos(ma,mid);
            
             if(poss >= k)
            { 
                ans=mid;
                j=mid-1; 
            }else{
                i=mid+1;
            }
            
        }
        
        return ans;
         
    }
};