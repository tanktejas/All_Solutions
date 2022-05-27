class Solution {
public:
    int numSteps(string s) {
        int ans=0;  
        reverse(s.begin(),s.end());
        int cc=0;
        for(int i=0;i<s.length()-1;i++){
             int curr=((s[i]-'0')+cc)&1;
             ans+=1+curr;
             if(curr!=0) cc=1;
        }
        return ans+cc;
    } 
};