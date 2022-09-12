class Solution {
public:
    int bagOfTokensScore(vector<int>& to, int po) {
        sort(to.begin(),to.end());
        
        int n=to.size();
        int i=0,j=n-1;
        int sc=0;
        
        while(i<=j)
        {
            if((po-to[i])<=0)
            {
                sc--;
                if(sc<0) return 0;
                po+=to[j];
                j--;
            }
            int noofinc=0;
            while(i<=j and ((po-to[i])>=0))
            { 
                noofinc++;
                po-=to[i];
                i++;
            }
            
            if(noofinc==0) return ++sc;
            else sc+=noofinc;
            
        }
        
        return sc;
    }
};