class Solution {
public:
    string ans;
    int cnt=0;
    vector<char>v={'a','b','c'};
    int nn,kk;
    
    void kth(string s)
    {
        if(s.length()==nn)
        {
            cnt++;
            if(cnt==kk) ans=s;
            return ;
        }
        
        for(int i=0;i<3;i++)
        {
            if(s=="" or s[s.length()-1]!=v[i])
            {
                kth(s+v[i]);
            }
        }
        
    }
    
    string getHappyString(int n, int k) {
        nn=n;
        kk=k;
        kth("");  
        return ans;
    }
};