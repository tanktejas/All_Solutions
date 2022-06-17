class Solution {
public:
    string longestPalindrome(string s) {
    
        int ans=0;
        int n=s.length();
        int ll=0,rr=0;
        for(int i=0;i<n;i++){
            int mid=0;
            
            int lef=i-1;
            int righ=i+1;
            
            while(lef>=0 and righ<n and s[lef]==s[righ]){
                lef--;
                righ++;
            }
            if((righ-lef+1)>ans){
                ll=lef+1;
                rr=righ-lef-1;
            }
            ans=max(ans,righ-lef+1);
            
        }
        
        for(int i=0;i<n-1;i++){
            int lef=i,righ=i+1;
            
             while(lef>=0 and righ<n and s[lef]==s[righ]){
                lef--;
                righ++;
            }
            if((righ-lef+1)>ans){
                ll=lef+1;
                rr=righ-lef-1;
            }
            ans=max(ans,righ-lef+1);
        }
        // cout<<rr;  
        return s.substr(ll,rr);
    }
};