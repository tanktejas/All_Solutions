class Solution {
public:
    string reverseWords(string s) {
       vector<string>ans;
        string cc="";
        
        for(int i=0;i<s.length();i++)
        {
             
            if(s[i]==' '){
                ans.push_back(cc);
                cc="";
            }else{
                cc+=s[i];
            }
        }
        ans.push_back(cc);
        string ff="";
        for(int i=0;i<ans.size();i++)
        {
            reverse(ans[i].begin(),ans[i].end());
            ff+=ans[i];
            if(i!=ans.size()-1) ff+=" ";
        }
        
        return ff;
    }
};