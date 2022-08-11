class Solution {
public:
    bool chk(vector<string> &s){

        for(int i=1;i<s.size();i++)
        {
            if(s[i] < s[i-1]) return 0;
        }
        return 1;
    }
    
    int minDeletionSize(vector<string>& strs) {
        vector<string>sor(strs.size(),"");
        int ans=0;
        
        for(int i=0;i<strs[0].length();i++)
        {
            vector<string>temp=sor;
            
            for(int j=0;j<strs.size();j++)
            {
                temp[j]+=(strs[j][i]);
            }
            
            
            if(chk(temp)){
                sor=temp;
            }else{
                ans++;
            }
            
        }
        
        return ans;
    }
};