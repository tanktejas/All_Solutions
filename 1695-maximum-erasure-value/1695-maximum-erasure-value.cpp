class Solution {
public:
    int maximumUniqueSubarray(vector<int>& s) {
        map<int,int>m;
        int sum=0;
        
        int n=s.size();
        int i=0,j=0;
        sum=s[0];
        m[s[0]]++;
        int ans=0;
        while(j<n){ 
            if(m[s[j]]>1){
                m[s[i]]--;
                sum-=s[i];
                i++;     
            }else{  
                ans=max(ans,sum);
                j++;  
                if(j<n){
                 sum+=s[j]; 
                 m[s[j]]++;
                }
            }
        }
        
        cout<<i;
        return ans;
    }
};