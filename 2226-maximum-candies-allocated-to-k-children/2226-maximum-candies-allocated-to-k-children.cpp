class Solution {
public:
    bool cani(int candy,long long k,vector<int> &cn){
        long long people=0;
        
        for(int i=0;i<cn.size();i++)
        {
            people+=(cn[i]/candy);
        }
        
        return people >= k;
    }
    
    int maximumCandies(vector<int>& cn, long long k) {
        sort(cn.begin(),cn.end());
        int maxcan=0;
        
        for(int i=0;i<cn.size();i++) maxcan=max(maxcan,cn[i]);
        
        long long i=1,j=maxcan;
        int ans=0;
        
        while(i<=j){
            
            int mid=(i+j)/2;
            
            if(cani(mid,k,cn)){
                ans=mid;
                i=mid+1;
            }else{
                j=mid-1;
            }
            
        }
        
        return ans;
    }
};