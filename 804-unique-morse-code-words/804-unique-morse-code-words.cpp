class Solution {
public:
    
    int uniqueMorseRepresentations(vector<string>& w) {
        vector<string>s={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    
       map<string,int>mp;
       int ans=0;
    
       for(int i=0;i<w.size();i++)
       {
           string curr="";
           for(int j=0;j<w[i].length();j++)
           {
                
               int idx=w[i][j]-'a';
               curr+=s[idx];
           }
           
           if(mp[curr]==0){
               mp[curr]=1;
               ans++;
           }
           
       }
        
        return ans;
    }
};