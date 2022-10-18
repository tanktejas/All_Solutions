class Solution {
public:
    string find(int n){
        if(n==1){
            return "1";
        }
        string ans=find(n-1);
        string curr="";
        int occ=1;
        char ch=ans[0];
        for(int i=1;i<ans.length();i++){
            if(ch!=ans[i]){
                curr+=(occ+48);
                curr+=ch; 
                ch=ans[i];
                occ=1; 
            }else{
                occ++;
            }
        }
        curr+=(occ+48);
        curr+=ch; 
        cout<<curr<<" ";
        return curr;
    }
    string countAndSay(int n) {
        return find(n);
    }
};