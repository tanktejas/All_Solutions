class Solution {
public:
    
    bool chk(int thre,vector<int> &bd,int m,int k)
    {
        int icando=0;
        int n=bd.size(); 
        
        for(int i=0;i<n;i++)
        {
            if(bd[i]>thre)
            {
                m-=((int)(icando/k));
                icando=0;
            }else{
                icando++;
            }
        }
        
        m-=(icando/k);
        
        return m<=0;
    }
    
    int minDays(vector<int>& bd, int m, int k) {
       int n=bd.size();
       int maxi=0; 
        
       for(int i=0;i<n;i++)
       {
           maxi=max(maxi,bd[i]);
       }
        
       int ans=INT_MAX;
       long long i=0,j=maxi; 
        
       while(i<=j)
       {
           
          int mid=(i+j)/2;
             
           if(chk(mid,bd,m,k))
           {
               ans=mid;
               j=mid-1;
           }else{
               i=mid+1;
           }
       }   
        
        return ans==INT_MAX ? -1 : ans;
    }
};