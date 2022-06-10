class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<int,int>m;
        if(s=="") return 0;
       int i=0;
       int j=0;
        int ans=1;
        m[s[0]]++;
       int n=s.length();
       while(j<n){ 
           if(m[s[j]]>1){
               m[s[i]]--;
               i++;
           }else{
               ans=max(ans,j-i+1);
               j++;
               m[s[j]]++;
           }
       }
        
        return ans;
    }
};