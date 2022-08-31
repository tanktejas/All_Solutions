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
            
//              if(len > n or len < ans.length()){
//                  continue;
//              }
             
             int start=-1;   
             bool bo=1;
             for(int i=0;i<len;i++)
             {
                 int j=0;
                 int pp=v[curr[i]-'a'].size();
                 while(j<pp and v[curr[i]-'a'][j] <= start)
                 {
                     j++;
                 }
                 
                 if(j>=pp)
                 {
                    bo=0;
                 }else{
                    start=v[curr[i]-'a'][j];
                 } 
             }
             if(bo)
             {
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