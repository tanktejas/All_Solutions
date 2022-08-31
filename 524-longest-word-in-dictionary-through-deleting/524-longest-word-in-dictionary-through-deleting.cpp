class Solution {
public:
    string findLongestWord(string s, vector<string>& dic) {
        vector<vector<int>>v(26);
        int n=s.length();
        int m=dic.size();
        
        for(int i=0;i<n;i++)
        {
            v[s[i]-'a'].push_back(i);
        }
         
        string ans="";
        
        for(int i=0;i<m;i++)
        {  
             string curr=dic[i];
             int len=curr.length();
            
             int start=0;
             int j;
             for(j=0;j<len and start<n;start++)
             {
                   if(s[start]==curr[j]){
                        j++;
                   } 
             }
            
             if(j==len){
                 
                 if(ans.size() < len)
                 {
                     ans=curr;
                 }else if(ans.length() == len)
                 {
                     if(ans > curr)
                     {
                         ans=curr;
                     }
                 }
                
             }
            
        }
        
        return ans;
    }
};