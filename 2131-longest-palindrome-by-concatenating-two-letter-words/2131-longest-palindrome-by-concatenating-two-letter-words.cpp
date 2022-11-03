class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        vector<string>same;
        int n=words.size();
        int cnt=0;
        
        for(int i=0;i<n;i++)
        {
            if(words[i][0]==words[i][1]){
                string k="";
                k+=words[i][0];
                k+=k;
                same.push_back(k);
            } 
            
        }
        
        map<string,int>mp;
        
        for(int i=0;i<n;i++)
        {
                string k="",l="";
                k+=words[i][0];
                k+=words[i][1];
                l=k;   
                reverse(l.begin(),l.end()); 
                if(mp[l])    
                {
                    mp[l]--;
                    cnt+=4;
                }else{
                    mp[k]++;
                } 
        } 
        
        n=same.size();
        for(int i=0;i<n;i++)
        {
            if(mp[same[i]]==1)
            {
                cnt+=2;    
                break;
            }
        }
        
        return cnt;
    }
};