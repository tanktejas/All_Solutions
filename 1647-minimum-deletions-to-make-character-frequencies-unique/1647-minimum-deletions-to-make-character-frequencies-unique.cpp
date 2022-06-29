class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int>m;
        sort(s.begin(),s.end());
        for(int i=0;i<s.length();){
            int tt=0;
            char ch=s[i];
            while(i<s.length() and ch==s[i]){
             tt++;
             i++;
            }
            m[ch]=tt;
        }
        
        map<int,int>run;
     
        int ans=0;
        
        for(char i='a';i<='z';i++){
            int temp=m[i];
            cout<<i<<' '<<temp<<" ";
            cout<<run[temp]<<endl;
            while(temp!=0 and run[temp]!=0){
                 ans++; 
                 m[i]--;
                temp--; 
            }       
            run[temp]=1;
        }
       
        return ans;
    }
};