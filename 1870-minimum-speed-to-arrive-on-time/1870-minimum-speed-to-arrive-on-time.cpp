class Solution {
public:
    bool chk(int speed,vector<int> &dis,double hr){
        double take=0.00; 
        
        for(int i=0;i<dis.size();i++)
        {
            float nu=dis[i];
            float de=speed;
            if(i==(dis.size()-1)){
              take+=(nu*1.0/de*1.0);  
            }else
              take+=(ceil(nu/de));
            
        }  
         
        return take<=hr;
    }
    
    int minSpeedOnTime(vector<int>& dist, double hour) {
        
        // if(dist.size())
        
        int i=1,j=1e7;
        int ans=-1;
        
        while(i<=j){
        
            int mid=(i+j)/2;
            
            if(chk(mid,dist,hour)){
                // if(mid==50) cout<<1;
                ans=mid;
                j=mid-1;
            }else{
                i=mid+1; 
            }
        }
        
        return ans;
    }
};