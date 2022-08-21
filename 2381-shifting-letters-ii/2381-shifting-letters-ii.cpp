class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& sh) {
        long long n=s.length();
        
        vector<unsigned long long>pre(n+2,0);
        
        for(int i=0;i<sh.size();i++)
        {
            unsigned long long s=sh[i][0];
            unsigned long long e=sh[i][1];
            long long up=(sh[i][2]==0 ? -1 : 1);
            long long dn=(sh[i][2]==0 ? 1 : -1);
            
            pre[s]+=(up);
            pre[e+1]+=(dn);
            
        }
        
       unsigned long long curr=0;
        string ans="";
        
        for(long long i=0;i<n;i++)
        {
            curr+=pre[i];
            int yy=(s[i]-'a')+curr;
            if(yy<0){
                yy=-yy;
                yy=yy%26;
                yy=-yy;
            }
            
            unsigned long long asc=26 + yy;
            asc=asc%26;
            
            char ch=('a' + asc);
            
            ans+=ch; 
        }
        
        return ans;
    }
};   