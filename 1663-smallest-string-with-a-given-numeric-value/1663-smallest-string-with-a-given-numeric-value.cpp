class Solution {
public:
    string getSmallestString(int n, int k) {
        
        string ans="";
        char curr='z';
        
        while(n>0)
        {
            int remval=(k - ((curr-'a') + 1));
            if((remval >= (n-1)))
            {
                n--;
                k-=((curr-'a')+1);
                ans+=curr;
            }else{
                curr--;
            }
        }
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};