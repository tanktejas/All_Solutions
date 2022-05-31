class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(s.length()<=k){
            return 0;
        }
        unordered_map<string,int>m;
        string win=s.substr(0,k);
        int cnt=1;
        reverse(win.begin(),win.end());
        m[win]++;
        for(int i=k;i<s.length();i++){
              win.pop_back();
              win=s[i]+win;
           if(m.find(win)==m.end()){
               cnt++;
               m[win]++;
           }
        
        }
        cout<<cnt<<" ";
        if(cnt>=pow(2,k)){
            return 1;
        }
        return 0;
    }
};