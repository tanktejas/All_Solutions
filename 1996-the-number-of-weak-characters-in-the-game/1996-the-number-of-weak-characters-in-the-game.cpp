class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& pro) {
        sort(pro.begin(),pro.end(),greater<vector<int>>());
        int n=pro.size();
        int maxi=-1e9;
        vector<int>hj;
        int cnt=0;
         
        for(int i=0;i<n;)
        {
             int ele=pro[i][0]; 
             int tp=maxi;  
              
        
             while(i<n and ele == pro[i][0])
             {   
                 int  hh=pro[i][1];
                 if(tp > hh)  
                 {
                     cnt++;
                 }  
                 
                 maxi=max(maxi,hh);
                  
                 i++;  
             }
             
        }
        return cnt;
    }
};