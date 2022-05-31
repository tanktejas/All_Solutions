class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(s.length()<=k){
            return 0;
        }
        
        int ss=pow(2,k);
        vector<int>mark(ss,0);
        int allones=0;
        for(int i=0;i<k;i++){
            allones=(allones)|(1<<i);
        } 
        
        int wind=stoi(s.substr(0,k),0,2); 
        
        int n=s.length();
        int cnt=1;
        mark[wind]=1;
        for(int i=k;i<n;i++){
            wind=(wind<<1)&(allones);
            wind|=((s[i]-'0')); 
            if(mark[wind]==0){
                mark[wind]=1;
                cnt++;
            }
        }
        
        if(cnt==ss){
            return 1;
        }
        return 0;
    }
};