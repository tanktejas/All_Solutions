class Solution {
public:
    string breakPalindrome(string p) {
        if(p.length()==1)
        {
            return "";
        }
        
        int n=p.length();
        bool bo=1;
        int i=0,j=n-1;
        int idx=-1;
        
        while(i<j)
        {
            if(p[i]!='a')
            {
                idx=i;
                bo=0;
                break;
            }
            i++;
            j--;
        }
        
        if(bo)
        {
            p[n-1]='b';
        }else{
            p[idx]='a';
        }
        
        return p;
    }
};