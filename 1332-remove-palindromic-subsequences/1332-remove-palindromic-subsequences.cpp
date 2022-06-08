class Solution {
public:
    int removePalindromeSub(string s) {
        bool ispal=0;
        for(int i=0;i<s.length()/2;i++)
        {
            if(s[i]!=s[s.length()-i-1]) ispal=1;
        }
        
        return ispal+1; 
    }
};