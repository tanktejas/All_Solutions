class Solution {
public:
    string shiftingLetters(string s, vector<int>& sh) {
        string ans="";
        long long sum=0; 
        int i;
        
        for(i=sh.size()-1;i>=0;i--){
            sum+=sh[i]; 
            ans+=((char)('a'+((sum+(s[i]-'a'))%26)));  
        }
        reverse(ans.begin(),ans.end()); 
        return ans;
    }
};