class Solution {
public:
    bool checkIfPangram(string sentence) {
        
       vector<int>f(26,0);
        int n=sentence.length();
       for(int i=0;i<n;i++) f[sentence[i]-'a']++;
       for(int i=0;i<26;i++)
       {
           if(f[i]==0) return 0;
       }
        
        return 1;
    }
};
